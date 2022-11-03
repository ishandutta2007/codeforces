#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

#ifdef LOCAL
    #define LLD_SPEC "%lld"
#else
    #define LLD_SPEC "%I64d"
#endif

int main() {
    long long h1, h2, a, b;
    scanf(LLD_SPEC LLD_SPEC LLD_SPEC LLD_SPEC, &h1, &h2, &a, &b);

    h1 += a * 8;

    if (h1 >= h2) {
        cout << 0 << endl;
        return 0;
    }

    long long diff = (-b + a) * 12;

    if (diff <= 0) {
        cout << -1 << endl;
        return 0;
    }

    long long dayCount = (h2 - h1) / diff + ((h2 - h1) % diff != 0);

    printf(LLD_SPEC "\n", dayCount);

    return 0;
}