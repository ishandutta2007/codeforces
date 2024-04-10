#include <cstdio>
#include <queue>
#include <utility>
static const int MAXN = 10004 * 2;
static const int INF = 0x7fff0fff;
// first = d, second = vertex ID
typedef std::pair<int, int> vertinfo;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    if (n >= m) {
        printf("%d\n", n - m);
        return 0;
    }
    // n < m
    int g[MAXN][3];
    g[0][0] = -1;
    for (int i = 1; i <= MAXN; ++i) g[i][0] = i - 1, g[i][1] = -1;
    for (int i = 1; i <= MAXN / 2; ++i) g[i][1] = i + i, g[i][2] = -1;
    // Dijkstra's algorithm
    int d[MAXN]; bool v[MAXN];
    std::priority_queue< vertinfo, std::vector<vertinfo>, std::greater<vertinfo> > q;
    for (int i = 0; i <= MAXN; ++i) d[i] = INF, v[i] = false;
    d[n] = 0; q.push(vertinfo(0, n));
    g[0][0] = -1;   // g[0][0] is changed accidentally. Strange.
    do {
        vertinfo vi = q.top(); q.pop();
        int curvert = vi.second, nextvert;
        if (curvert == m) break;
        else if (v[curvert]) continue;
        v[curvert] = true;
        for (int i = 0; (nextvert = g[curvert][i]) >= 0; ++i)
            // The weights of all edges are all 1.
            if (!v[nextvert] && d[nextvert] > d[curvert] + 1) {
                d[nextvert] = d[curvert] + 1;
                q.push(vertinfo(d[nextvert], nextvert));
            }
    } while (!q.empty());
    printf("%d\n", d[m]);
    return 0;
}