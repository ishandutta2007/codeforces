#include <stdio.h>
#include <math.h>

void swap(long long *a, long long *b)
{
    long long t = *a; *a = *b; *b = t;
}

int main()
{
    long long c, hr, hb, wr, wb;
    scanf("%I64d%I64d%I64d%I64d%I64d", &c, &hr, &hb, &wr, &wb);

    long long sqrtc = sqrt(c), cntbmax;
    if (wr >= sqrtc || wb >= sqrtc) {
        if (wr > wb) {
            swap(&hr, &hb);
            swap(&wr, &wb);
        }
        // Guaranteed that wr <= sqrt(c) <= wb
        cntbmax = c / wb;
    } else {
        if (hb * wr > hr * wb) {
            swap(&hr, &hb);
            swap(&wr, &wb);
        }
        // Guaranteed that hb * wr <= wb * hr
        cntbmax = wr - 1;
    }

    long long ans = 0, cntb;
    for (cntb = 0; cntb <= cntbmax; ++cntb) {
        long long cur = cntb * hb + (c - cntb * wb) / wr * hr;
        if (cur > ans) ans = cur;
    }

    printf("%I64d\n", ans);
    return 0;
}