#include <cstdio>
#include <queue>
#include <utility>
static const int MAXN = 1024;
typedef std::pair<int, int> position;
#define row first
#define col second
static const int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int n, m;
char a[MAXN][MAXN];
int ans[MAXN][MAXN] = {{ 0 }};

void floodfill(int start_r, int start_c)
{
    int cur_ans = 0, q_tail = 0;
    std::vector<position> q;
    position p, pp;
    q.push_back(position(start_r, start_c));
    ans[start_r][start_c] = -233;
    do {
        p = q[q_tail++];
        for (int k = 0; k < 4; ++k) {
            pp.row = p.row + dir[k][0];
            pp.col = p.col + dir[k][1];
            if (pp.row >= 0 && pp.row < n && pp.col >= 0 && pp.col < m
                && ans[pp.row][pp.col] == 0)
            {
                if (a[pp.row][pp.col] == '*') ++cur_ans;
                else {
                    q.push_back(pp);
                    ans[pp.row][pp.col] = -233;
                }
            }
        }
    } while (q_tail < q.size());
    for (std::vector<position>::iterator i = q.begin(); i != q.end(); ++i)
        ans[i->row][i->col] = cur_ans;
}

int main()
{
    int k, x, y;
    scanf("%d%d%d", &n, &m, &k);
    getchar();
    for (int i = 0; i < n; ++i) gets(a[i]);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i][j] == '.' && !ans[i][j]) floodfill(i, j);
    do {
        scanf("%d%d", &x, &y);
        printf("%d\n", ans[x - 1][y - 1]);
    } while (--k);
    return 0;
}