#include <cstdio>
#include <cstring>

int main() {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    int tot = 0;
    for (int ln = 0; ln <= 63; ++ln) {
        unsigned long long big = (((unsigned long long) 1LL) << ln) - 1;
        for (int k = 0; k + 1 < ln; ++k) {
            unsigned long long ch = 1;
            ch = ch << k;
            big -= ch;
            if (big >= a && big <= b) {
                ++tot;
            }
            big += ch;
        }
    }
    printf("%d\n", tot);
    return 0;
}