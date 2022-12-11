#include <cstdio>
#include <vector>
static const int MAXN = 512;

int n, k;
bool obstacle[MAXN][MAXN] = {{ false }};

int cc_ct = 0;
int cc_id[MAXN][MAXN];
int cc_sz[MAXN * MAXN] = { 0 };
static const int move[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

std::vector<int> ccs;
bool cc_vis[MAXN * MAXN] = { false };

inline bool inrange(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < n;
}

inline int try_visit_cc(int r, int c) {
    if (inrange(r, c) && !obstacle[r][c] && !cc_vis[cc_id[r][c]]) {
        cc_vis[cc_id[r][c]] = true;
        ccs.push_back(cc_id[r][c]);
        return cc_sz[cc_id[r][c]];
    } else {
        return 0;
    }
}
inline void clear_marked_cc()
{
    for (std::vector<int>::iterator i = ccs.begin(); i != ccs.end(); ++i)
        cc_vis[*i] = false;
    ccs.clear();
}

void dfs(int r, int c)
{
    cc_id[r][c] = cc_ct;
    ++cc_sz[cc_ct];
    for (int k = 0; k < 4; ++k) {
        int rr = r + move[k][0],
            cc = c + move[k][1];
        if (inrange(rr, cc) && !obstacle[rr][cc] && cc_id[rr][cc] == -1)
            dfs(rr, cc);
    }
}

int main()
{
    scanf("%d%d", &n, &k); getchar();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= n; ++j)
            obstacle[i][j] = (getchar() != '.');

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) cc_id[i][j] = -1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (!obstacle[i][j] && cc_id[i][j] == -1) {
                dfs(i, j);
                ++cc_ct;
            }
    /*for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            printf("%3d%c", cc_id[i][j], j == n - 1 ? '\n' : ' ');
    for (int i = 0; i < cc_ct; ++i)
        printf("%d%c", cc_sz[i], i == cc_ct - 1 ? '\n' : ' ');*/

    int ans = 0;
    for (int r = 0; r <= n - k; ++r) {
        for (int i = 0; i < k; ++i)
            for (int j = 0; j < k; ++j)
                --cc_sz[cc_id[i + r][j]];

        for (int c = 0; c <= n - k; ++c) {
            int cur = k * k;
            for (int i = 0; i < k; ++i) {
                cur += try_visit_cc(r - 1, c + i);
                cur += try_visit_cc(r + k, c + i);
                cur += try_visit_cc(r + i, c - 1);
                cur += try_visit_cc(r + i, c + k);
            }
            if (ans < cur) ans = cur;
            clear_marked_cc();
            if (c != n - k) {
                for (int i = 0; i < k; ++i) {
                    if (!obstacle[r + i][c]) ++cc_sz[cc_id[r + i][c]];
                    if (!obstacle[r + i][c + k]) --cc_sz[cc_id[r + i][c + k]];
                }
            }
        }

        for (int i = 0; i < k; ++i)
            for (int j = 0; j < k; ++j)
                ++cc_sz[cc_id[i + r][j + (n - k)]];
    }

    printf("%d\n", ans);
    return 0;
}