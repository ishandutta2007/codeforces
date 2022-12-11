#include <cstdio>
#include <cstring>
static const int MAXN = 1e5 + 4;
static const int MAXK = 1e5 + 4;
static const int MAXVAL = 2048 + 3;

int n, k, x;
int ct[2][MAXVAL] = {{ 0 }};

int main()
{
    scanf("%d%d%d", &n, &k, &x);
    int a_i;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a_i); ++ct[0][a_i];
    }

    for (int i = 0; i < k; ++i) {
        memset(ct[1], 0, sizeof ct[1]);
        int accum = 0;
        for (int i = 0; i < MAXVAL; ++i) {
            ct[1][i] += ct[0][i] / 2;
            ct[1][i ^ x] += ct[0][i] / 2;
            if (ct[0][i] & 1) {
                if (accum & 1) ct[1][i]++; else ct[1][i ^ x]++;
            }
            accum += ct[0][i];
        }
        for (int i = 0; i < MAXVAL; ++i) ct[0][i] = ct[1][i];
    }

    for (int i = MAXVAL - 1; i >= 0; --i)
        if (ct[0][i]) { printf("%d ", i); break; }
    for (int i = 0; i < MAXVAL; ++i)
        if (ct[0][i]) { printf("%d\n", i); break; }

    return 0;
}