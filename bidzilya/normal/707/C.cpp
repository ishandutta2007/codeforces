#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

#include <cassert>
using namespace std;

#ifdef LOCAL
    #define LLD_SPEC "%lld"
#else
    #define LLD_SPEC "%I64d"
#endif

void SolveOdd(const long long a, long long& b, long long& c) {
    assert(a & 1);

    b = (a * a - 1) / 2;
    c = (a * a + 1) / 2;
}

void ShowResult(long long b, long long c) {
    printf(LLD_SPEC " " LLD_SPEC "\n", b, c);
}

int main() {
    long long a;
    scanf(LLD_SPEC, &a);

    if (a == 1 || a == 2) {
        printf("-1\n");
        return 0;
    }

    if (a & 1) {
        long long b, c;
        SolveOdd(a, b, c);
        ShowResult(b, c);
    } else {
        int pw = 0;
        while ((a & 1) == 0) {
            ++pw;
            a >>= 1;
        }

        if (pw == 1) {
            long long b, c;
            SolveOdd(a, b, c);

            ShowResult(b << 1, c << 1);
        } else {
            --pw;
            long long pwValue = (1LL << pw);

            long long n = pwValue;
            long long m = a;

            long long b = m * m - n * n;
            if (b < 0) {
                b *= -1;
            }
            long long c = m * m + n * n;

            printf(LLD_SPEC " " LLD_SPEC "\n", b, c);
        }
    }

    return 0;
}