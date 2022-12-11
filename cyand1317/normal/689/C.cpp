#include <cstdio>

int main()
{
    long long m;
    scanf("%I64d", &m);

    long long lo = 0, hi = 1e16, mid;
    long long mm;
    while (lo < hi - 1) {
        mid = (lo + hi) >> 1;
        mm = 0;
        for (long long k = 2; k * k * k <= mid; ++k)
            mm += mid / k / k / k;
        if (mm < m) lo = mid;
        else hi = mid;
    }

    mm = 0;
    for (long long k = 2; k * k * k <= hi; ++k)
        mm += hi / k / k / k;
    printf("%I64d\n", mm == m ? hi : -1);
    return 0;
}