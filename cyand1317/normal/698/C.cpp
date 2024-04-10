#include <cstdio>
typedef double ldouble;
static const int MAXN = 21;

int n, k;
double p[MAXN];
ldouble p_sum[1 << MAXN] = { 0 }, ans[MAXN] = { 0 }, ans_sum = 0;
ldouble f[1 << MAXN] = { 0 };
bool vis[1 << MAXN] = { false };

void calc(int mask) {
    if (vis[mask]) return;
    for (int i = 0; i < n; ++i) if (mask & (1 << i)) {
        calc(mask ^ (1 << i));
        f[mask] += f[mask ^ (1 << i)] * p[i] / p_sum[((1 << n) - 1) ^ (mask ^ (1 << i))];
    }
    vis[mask] = true;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%lf", &p[i]);
    int nonzero_cnt = 0;
    for (int i = 0; i < n; ++i) if (p[i] != 0) ++nonzero_cnt;
    if (nonzero_cnt < k) k = nonzero_cnt;

    for (int i = 0; i < (1 << n); ++i)
        for (int j = 0; j < n; ++j) if (i & (1 << j)) p_sum[i] += p[j];
    for (int i = 0; i < n; ++i) { f[1 << i] = p[i]; vis[1 << i] = true; }
    calc((1 << n) - 1);
    //for (int i = 0; i < (1 << n); ++i) printf("%.7Lf\n", f[i]);

    for (int i = 0; i < (1 << n); ++i) if (__builtin_popcount(i) == k) {
        for (int j = 0; j < n; ++j) if (i & (1 << j)) { ans[j] += f[i]; ans_sum += f[i]; }
    }
    for (int i = 0; i < n; ++i) printf("%.7lf%c", (double)(ans[i] / ans_sum * k), i == n - 1 ? '\n' : ' ');

    return 0;
}