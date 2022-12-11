#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
static const int MAXN = 302;
typedef std::pair<short, short> position;
#define row first
#define col second
typedef std::vector<position> poslist;
template <typename T> inline bool update_min(T &var, T val) { if (var > val) { var = val; return true; } else return false; }
template <typename T> inline T abs(T x) { return x < 0 ? -x : x; }

int n, m, p;
int a[MAXN][MAXN], f[2][MAXN][MAXN], cur = 0;
poslist level[MAXN * MAXN];
static const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main()
{
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i][j]);
            level[a[i][j]].push_back(position(i, j));
        }

    memset(f[cur], 0x7f, sizeof f[cur]);
    for (poslist::iterator i = level[1].begin(); i != level[1].end(); ++i) {
        f[cur][i->row][i->col] = i->row + i->col;
    }
    int threshold = (int)sqrt(n * m);
    for (int i = 1; i < p; ++i) {
        cur ^= 1;
        memset(f[cur], 0x7f, sizeof f[cur]);
        if (level[i].size() <= threshold) {
            for (poslist::iterator j = level[i].begin(); j != level[i].end(); ++j) {
                for (poslist::iterator k = level[i + 1].begin(); k != level[i + 1].end(); ++k)
                        update_min(f[cur][k->row][k->col], f[cur ^ 1][j->row][j->col] + abs(k->row - j->row) + abs(k->col - j->col));
            }
        } else {
            std::queue<position> q;
            for (poslist::iterator j = level[i].begin(); j != level[i].end(); ++j) {
                f[cur][j->row][j->col] = f[cur ^ 1][j->row][j->col];
                q.push(*j);
            }
            while (!q.empty()) {
                position r = q.front(); q.pop();
                for (int k = 0; k < 4; ++k) {
                    int rr = r.row + dir[k][0];
                    int cc = r.col + dir[k][1];
                    if (rr >= 0 && rr < n && cc >= 0 && cc < m
                        && update_min(f[cur][rr][cc], f[cur][r.row][r.col] + 1))
                    {
                        q.push(position(rr, cc));
                    }
                }
            }
        }
    }

    printf("%d\n", f[cur][level[p][0].row][level[p][0].col]);
    return 0;
}