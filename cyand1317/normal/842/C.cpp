#include <cstdio>
#include <algorithm>
#include <vector>
static const int MAXN = 2e5 + 4;
static const int LOGN = 18;
static const int MAXA = 2e5 + 6;
template <typename T> inline T gcd(const T a, const T b) { return b == 0 ? a : gcd(b, a % b); }

int n;
int a[MAXN];
std::vector<int> e[MAXN];

int dep[MAXN], anc[MAXN][LOGN], rou[MAXN][LOGN];

void dfs_anc(int u, int p, int d)
{
    dep[u] = d;
    anc[u][0] = p;
    rou[u][0] = a[u];
    for (int i = 1; i < LOGN; ++i) {
        anc[u][i] = (anc[u][i - 1] == -1) ? -1 : anc[anc[u][i - 1]][i - 1];
        rou[u][i] = (anc[u][i - 1] == -1) ? rou[u][i - 1] : gcd(rou[u][i - 1], rou[anc[u][i - 1]][i - 1]);
    }
    for (int v : e[u]) if (v != p) {
        dfs_anc(v, u, d + 1);
    }
}

int b[MAXN];
int up[MAXN];
std::vector<int> chg;

inline int root_path(int u, int steps)
{
    int ans = 0;
    for (int i = 0; i < LOGN; ++i) if (steps & (1 << i)) {
        ans = gcd(ans, rou[u][i]);
        u = anc[u][i];
    }
    return ans;
}

void dfs_val(int u, int p, int val)
{
    up[u] = val;
    b[u] = val;
    for (int w : chg) {
        int cur = (anc[w][0] == -1 ? 0 : up[anc[w][0]]);
        cur = gcd(cur, root_path(u, dep[u] - dep[w]));
        b[u] = std::max(b[u], cur);
    }

    for (int v : e[u]) if (v != p) {
        int g = gcd(val, a[v]);
        if (g != val) chg.push_back(v);
        dfs_val(v, u, g);
        if (g != val) chg.pop_back();
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0, u, v; i < n - 1; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs_anc(0, -1, 0);
    chg.push_back(0);
    dfs_val(0, -1, a[0]);
    for (int i = 0; i < n; ++i) printf("%d%c", b[i], i == n - 1 ? '\n' : ' ');

    return 0;
}