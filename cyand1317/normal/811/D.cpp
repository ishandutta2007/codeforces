#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <utility>
#include <vector>
static const int MAXN = 104;
static const int mov[4][2] = {{0, -1}, {0, +1}, {-1, 0}, {+1, 0}};
static const char *dir = "LRUD";
static const int L = 0, R = 1, U = 2, D = 3;

int n, m;
char s[MAXN][MAXN];
int fr, fc;
int pr = 0, pc = 0;
bool swapLR = false, swapUD = false;

inline void update_position()
{
    scanf("%d%d", &pr, &pc); --pr, --pc;
    if (pr == fr && pc == fc) { fputs("^ ^\n", stderr); exit(0); }
    else if (pr == -2) { fputs("> <\n", stderr); exit(0); }
}
inline void move(int d)
{
    putchar(dir[d ^ (d <= 1 ? swapLR : swapUD)]); putchar('\n');
    fflush(stdout); update_position();
}

void test_swapLR()
{
    move(L);
    if (pc == 1) swapLR = true;
    else swapLR = false, move(R);
}
void test_swapUD()
{
    move(U);
    if (pr == 1) swapUD = true;
    else swapUD = false, move(D);
}

typedef std::pair<int, int> coord;
bool vis[MAXN][MAXN] = {{ false }};
int pred[MAXN][MAXN];

int main()
{
    scanf("%d%d", &n, &m); getchar();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= m; ++j)
            if ((s[i][j] = getchar()) == 'F') fr = i, fc = j;

    if (n == 1 || s[1][0] == '*') {
        test_swapLR();
        move(L);
        while (n == 1 || s[1][pc] == '*') move(R);
        test_swapUD();
    } else {
        test_swapUD();
        move(U);
        while (m == 1 || s[pr][1] == '*') move(D);
        test_swapLR();
    }

    std::queue<coord> q;
    q.push(coord(pr, pc)); vis[pr][pc] = true; pred[pr][pc] = -1;
    while (!q.empty()) {
        coord r = q.front(); q.pop();
        for (int k = 0; k < 4; ++k) {
            int rr = r.first + mov[k][0],
                cc = r.second + mov[k][1];
            if (rr >= 0 && rr < n && cc >= 0 && cc < m && s[rr][cc] != '*' && !vis[rr][cc]) {
                q.push(coord(rr, cc)); vis[rr][cc] = true; pred[rr][cc] = k;
            }
        }
    }

    assert(vis[fr][fc]);
    std::vector<int> route;
    for (int r = fr, c = fc; r != pr || c != pc; ) {
        route.push_back(pred[r][c]);//, printf("%d %d\n", r, c);
        int rr = r - mov[pred[r][c]][0],
            cc = c - mov[pred[r][c]][1];
        r = rr, c = cc;
    }
    for (std::vector<int>::reverse_iterator i = route.rbegin(); i != route.rend(); ++i)
        move(*i);

    return 0;
}