#include <cstdio>
#include <queue>
#include <vector>
template <typename T> inline T max(const T a, const T b) { return a > b ? a : b; }
static const int MAXN = 103;
static const int MAXM = 103;
static const int MAXLEN = 24;

int n, t, m;
int a[MAXN][2];
char w[MAXN][MAXLEN];
int c[MAXM];

int d[MAXN][MAXM] = {{ 0 }};
std::vector<int> solved[MAXN];
std::queue<int> pile;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &t);
    int a1, a2, b1, b2;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%d", &a1, &a2, &b1, &b2);
        a[i][0] = a1 + b2;
        a[i][1] = a2 + b1;
    }
    scanf("%d", &m); getchar();
    for (int i = 0; i < m; ++i) {
        gets(w[i]); scanf("%d", &c[i]); getchar();
    }

    for (int i = 0; i < m; ++i) pile.push(i);
    int turn = 0, time;
    while (!pile.empty()) {
        time = t;
        do {
            int u = pile.front(); pile.pop();
            int r = c[u] - a[turn % n][turn / n] - d[turn % n][u];
            if (time < r) {
                d[turn % n][u] += time;
                pile.push(u);
                time = 0;
            } else {
                time -= max(1, r);
                solved[turn % n].push_back(u);
            }
        } while (time > 0 && !pile.empty());
        turn = (turn + 1) % (2 * n);
    }

    for (int i = 0; i < n; ++i) {
        printf("%lu", solved[i].size());
        for (std::vector<int>::iterator j = solved[i].begin(); j != solved[i].end(); ++j)
            printf(" %s", w[*j]);
        putchar('\n');
    }

    return 0;
}