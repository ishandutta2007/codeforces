#include <cstdio>
#include <algorithm>
#include <functional>
#include <map>
#include <queue>
#include <utility>
#include <vector>
static const int MAXN = 1e4 + 3;
static const int MAXK = 1e4 + 2;
static const int INF = 0x3fffffff;

struct edge { int v, w; edge() { } edge(int v, int w) : v(v), w(w) { } };
static const int mov[4][2] = { { +1, 0 }, { -1, 0 }, { 0, +1 }, { 0, -1 } };

int n, m, k;
int r[MAXK], c[MAXK];
std::map<std::pair<int, int>, int> id;
std::vector<edge> e[MAXN * 2 + MAXK];
#define row_node(_i) (k + (_i))
#define col_node(_i) (k + n + (_i))

int d[MAXN * 2 + MAXK];

void dijkstra(int src)
{
    std::fill(d, d + MAXN * 2 + MAXK, INF);
    typedef std::pair<int, int> node;
    std::priority_queue<
        node, std::vector<node>, std::greater<node>
    > q;

    d[src] = 0; q.push(node(0, src));
    node r;
    while (!q.empty()) {
        do { r = q.top(); q.pop(); } while (d[r.second] != r.first && !q.empty());
        for (std::vector<edge>::iterator i = e[r.second].begin(); i != e[r.second].end(); ++i)
            if (d[i->v] > r.first + i->w) {
                d[i->v] = r.first + i->w;
                q.push(node(d[i->v], i->v));
            }
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < k; ++i) {
        scanf("%d%d", &r[i], &c[i]); --r[i], --c[i];
        id[std::make_pair(r[i], c[i])] = i + 1;
    }
    int &fin = id[std::make_pair(n - 1, m - 1)];
    if (fin == 0) {
        fin = k + n + m;
        e[row_node(n - 1)].push_back(edge(fin, 0));
        e[col_node(m - 1)].push_back(edge(fin, 0));
    }

    for (int i = 0; i < k; ++i) {
        for (int dir = 0; dir < 4; ++dir) {
            int rr = r[i] + mov[dir][0],
                cc = c[i] + mov[dir][1], targ;
            if ((targ = id[std::make_pair(rr, cc)] - 1) >= 0 && targ < k)
                e[i].push_back(edge(targ, 0));
        }
        for (int rr = std::max(0, r[i] - 1); rr < std::min(n, r[i] + 2); ++rr) {
            e[i].push_back(edge(row_node(rr), 1));
            e[row_node(rr)].push_back(edge(i, 0));
        }
        for (int cc = std::max(0, c[i] - 1); cc < std::min(m, c[i] + 2); ++cc) {
            e[i].push_back(edge(col_node(cc), 1));
            e[col_node(cc)].push_back(edge(i, 0));
        }
    }

    dijkstra(0);
    if (fin <= k) --fin;
    printf("%d\n", d[fin] >= INF / 2 ? -1 : d[fin]);

    return 0;
}