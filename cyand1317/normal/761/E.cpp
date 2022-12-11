// No zuo no die why you try
#include <cstdio>
typedef long long int64;
static const int MAXN = 32;

int n;
int deg[MAXN] = { 0 };
bool g[MAXN][MAXN];

int64 pow3[MAXN];
int64 ans_x[MAXN], ans_y[MAXN];

// 0: +x (up)
// 1: -x (down)
// 2: +y (right)
// 3: -y (left)
static const int mov[4][2] = {{+1, 0}, {-1, 0}, {0, +1}, {0, -1}};
void dfs_tryplace(int u, int dir, int p = -1, int d = MAXN - 1)
{
    int cur_dir = -1;   // (`)
    for (int v = 0; v < n; ++v) if (v != p && g[u][v]) {
        ++cur_dir; if (p != -1 && cur_dir == (dir ^ 1)) ++cur_dir;
        ans_x[v] = ans_x[u] + pow3[d] * mov[cur_dir][0];
        ans_y[v] = ans_y[u] + pow3[d] * mov[cur_dir][1];
        dfs_tryplace(v, cur_dir, u, d - 1);
    }
}

int main()
{
    pow3[0] = 1; for (int i = 1; i < MAXN; ++i) pow3[i] = pow3[i - 1] * 3;

    scanf("%d", &n);
    int u, v;
    for (int i = 0; i < n - 1; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        ++deg[u]; ++deg[v]; g[u][v] = g[v][u] = true;
    }
    for (int i = 0; i < n; ++i) if (deg[i] > 4) { puts("NO"); return 0; }

    ans_x[0] = ans_y[0] = 0;
    dfs_tryplace(0, 114514);

    puts("YES");
    for (int i = 0; i < n; ++i) printf("%I64d %I64d\n", ans_x[i], ans_y[i]);
    return 0;
}