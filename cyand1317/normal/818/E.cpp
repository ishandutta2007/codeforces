#include <cstdio>
typedef long long int64;
static const int MAXN = 1e5 + 4;
static const int MAXCT = 10;

int n, k, a[MAXN][MAXCT] = {{ 0 }};
int ct, p[MAXCT], q[MAXCT];

inline void factorize(int k)
{
    ct = 0;
    for (int i = 2; i * i <= k; ++i) if (k % i == 0) {
        p[ct] = i; q[ct] = 0;
        do { k /= i; ++q[ct]; } while (k % i == 0);
        ++ct;
    }
    if (k > 1) { p[ct] = k; q[ct++] = 1; }
}

int accum[MAXCT] = { 0 };

inline bool valid()
{
    for (int i = 0; i < ct; ++i) if (accum[i] < q[i]) return false;
    return true;
}

int main()
{
    scanf("%d%d", &n, &k);
    factorize(k);
    //for (int i = 0; i < ct; ++i) printf("%d - %d\n", p[i], q[i]);

    for (int i = 0, a_i; i < n; ++i) {
        scanf("%d", &a_i);
        for (int j = 0; j < ct; ++j)
            while (a_i % p[j] == 0) {
                ++a[i][j]; a_i /= p[j];
            }
    }

    int64 ans = 0;
    int s = 0, t = 0;
    while (t < n && (s == t || !valid())) {
        for (int i = 0; i < ct; ++i) accum[i] += a[t][i];
        ++t;
    }
    if (!valid()) { puts("0"); return 0; }
    ans += (n - t + 1);
    for (++s; s < n; ++s) {
        for (int i = 0; i < ct; ++i) accum[i] -= a[s - 1][i];
        while (t < n && (s == t || !valid())) {
            for (int i = 0; i < ct; ++i) accum[i] += a[t][i];
            ++t;
        }
        if (!valid()) break;
        //printf("%d %d\n", s, t);
        ans += (n - t + 1);
    }

    printf("%I64d\n", ans);
    return 0;
}