#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
static const int INF = 0x7f7f7f7f;
static const int MAXN = 1e5 + 4;
static const int MAXOPS = 302;
static const int MAXELM = 1e5 + 2;
template <typename T> inline void upd_min(T &var, const T val) { if (var > val) var = val; }

int n, m, s, e, a[MAXN], b[MAXN];
std::vector<int> occ[MAXELM];
int f[MAXN][MAXOPS];

inline int next_occ(int greater, int val) {
    std::vector<int>::iterator p = std::upper_bound(occ[val].begin(), occ[val].end(), greater);
    return (p == occ[val].end() ? INF : *p);
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &e);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i) { scanf("%d", &b[i]); occ[b[i]].push_back(i); }

    memset(f, 0x7f, sizeof f);
    for (int i = 0; i < n; ++i) f[i][0] = -1;
    f[0][1] = next_occ(-1, a[0]);
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < MAXOPS - 1; ++j) {
            upd_min(f[i + 1][j], f[i][j]);
            upd_min(f[i + 1][j + 1], next_occ(f[i][j], a[i + 1]));
        }

    int ans = 0;
    for (int i = 1; i < MAXOPS; ++i) {  // # of operations
        for (int j = 0; j <= n; ++j)    // position of last move
            if ((long long)i * e + j + f[j][i] + 2 <= s) ans = i;   // +2 for two 0-based indices
    }

    printf("%d\n", ans);
    return 0;
}