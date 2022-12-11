#include <cstdio>
typedef long long int64;
static const int MULTIPLIER = 1e9;

int a, b, mod;

int main()
{
    scanf("%d%d%d", &a, &b, &mod);
    if (b >= mod) { puts("2"); return 0; }

    for (int i = 0; i <= mod && i <= a; ++i) {
        int64 p2_start = (int64)i * MULTIPLIER;
        int64 p2_end = (int64)i * MULTIPLIER + b;
        if ((p2_start == p2_end && p2_start % mod != 0) ||
            (p2_start < p2_end && p2_start % mod > 0 && p2_end % mod > 0 && p2_start % mod < p2_end % mod))
        {
            printf("1 %09d\n", i); return 0;
        }
    }

    puts("2");
    return 0;
}