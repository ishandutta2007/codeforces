#include <cstdio>
#include <algorithm>
#include <vector>
static const int MAXN = 1004;
static const int RG = 8;
template <typename T> inline void upd_max(T &var, const T val) { if (var < val) var = val; }

int n, a[MAXN];
std::vector<int> occ[RG];
int occ_next[RG][MAXN];

int p[RG], xt_mask, base_len;
inline bool check() {
    int ptr = 0;
    for (int i = 0; i < RG; ++i) {
        int u = p[i];
        int this_len = base_len + ((xt_mask >> u) & 1);
        if (this_len <= 0) continue;
        ptr = occ_next[u][ptr];
        if ((ptr += (this_len - 1)) >= (int)occ[u].size()) return false;
        ptr = occ[u][ptr] + 1;
    }
    return true;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]); --a[i];
        occ[a[i]].push_back(i);
    }
    for (int i = 0; i < RG; ++i) {
        int last = 0;
        for (int j = 0; j < (int)occ[i].size(); ++j)
            for (; last <= occ[i][j]; ++last) occ_next[i][last] = j;
        for (; last < MAXN; ++last) occ_next[i][last] = (int)occ[i].size();
    }

    for (int i = 0; i < RG; ++i) p[i] = i;
    int ans = 0;
    do {
        for (xt_mask = 0; xt_mask < (1 << RG); ++xt_mask) {
            int lo = -1, hi = MAXN / RG + 10;
            while (lo < hi - 1) {
                base_len = (lo + hi) >> 1;
                if (check()) lo = base_len; else hi = base_len;
                if (ans >= __builtin_popcount(xt_mask) + hi * 8) break;
            }
            if (lo >= 0) upd_max(ans, __builtin_popcount(xt_mask) + lo * 8);
        }
    } while (std::next_permutation(p, p + RG));

    printf("%d\n", ans);
    return 0;
}