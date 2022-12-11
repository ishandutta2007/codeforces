#include <cstdio>
#include <algorithm>
static const int INF = 0x1fffffff;
static const int MAXN = 52;
template <typename T> inline void upd_min(T &var, const T val) { if (var > val) var = val; }

int n, m;
char s[MAXN][MAXN];
int cost[MAXN][3];

inline int get_type(const char ch) {
    if (ch >= '0' && ch <= '9') return 0;
    else if (ch >= 'a' && ch <= 'z') return 1;
    else return 2;
}

int main()
{
    scanf("%d%d", &n, &m); getchar();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= m; ++j) s[i][j] = getchar();

    for (int i = 0; i < n; ++i) {
        cost[i][0] = cost[i][1] = cost[i][2] = INF;
        for (int j = 0; j < m; ++j)
            upd_min(cost[i][get_type(s[i][j])], std::min(j, m - j));
    }

    int ans = INF;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) if (i != j)
            for (int k = 0; k < n; ++k) if (i != k && j != k)
                upd_min(ans, cost[i][0] + cost[j][1] + cost[k][2]);

    printf("%d\n", ans);
    return 0;
}