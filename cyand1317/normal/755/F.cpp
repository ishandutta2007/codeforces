#include <cstdio>
#include <bitset>
static const int MAXN = 1000004;
static const int THRESHOLD = 114;

int n, k;
int p[MAXN];
bool cyc_vis[MAXN] = { false }; int cyc_sz_bucket[MAXN], cyc_ct = 0;
std::bitset<MAXN> knapsack;

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) { scanf("%d", &p[i]); --p[i]; }

    for (int i = 0; i < n; ++i) if (!cyc_vis[i]) {
        int sz, j;
        for (cyc_vis[i] = true, j = p[i], sz = 1; j != i; j = p[j], ++sz) cyc_vis[j] = true;
        ++cyc_sz_bucket[sz];
        ++cyc_ct;
    }

    // Preprocessing for knapsack & greedy implementation
    int effect2_ct = 0, effect1_ct = 0;
    for (int i = 1; i <= n; ++i) {
        effect2_ct += (i / 2) * cyc_sz_bucket[i];
        effect1_ct += (i % 2) * cyc_sz_bucket[i];
    }
    for (int i = 1; i < n / 2; ++i) if (cyc_sz_bucket[i] > 2) {
        int half = (cyc_sz_bucket[i] - 1) / 2;
        cyc_sz_bucket[i * 2] += half;
        cyc_sz_bucket[i] -= half * 2;
    }

    // Minimum
    knapsack.reset();
    knapsack.set(0);
    for (int i = 1; i <= k; ++i)
        for (int j = 0; j < cyc_sz_bucket[i]; ++j)
            knapsack |= (knapsack << i);
    printf("%d ", knapsack.test(k) ? k : k + 1);

    // Maximum
    int ans = 0;
    if (k < effect2_ct) {
        ans += k * 2;
    } else {
        ans += effect2_ct * 2;
        k -= effect2_ct;
        if (k < effect1_ct) ans += k; else ans += effect1_ct;
    }
    printf("%d\n", ans);

    return 0;
}