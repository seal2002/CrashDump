#include <jni.h>
#include <string>

void makeCrash();

extern "C" JNIEXPORT jstring JNICALL
Java_com_sample_CrashDump_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    makeCrash();
    return env->NewStringUTF(hello.c_str());
}

void makeCrash() {
    auto j = [=]()->int
    {
        int i = 0;
        while(i < 1000) {
            i++;
        }
        std::abort();
        return i;
    };
    j();
}
