// Quite messy > <
#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
static const int MAXN = 1005;
static const int MAXM = 10004;
typedef long long int64;
static const int INF32 = 0x7fffffff;
static const int64 INF64 = (1LL << 61);

int n, m, l, s, t;
struct edge {
    int first, second; int rev, tag;
    edge() : first(-1), second(0), tag(false) { }
    edge(int dest, int len, int rev, bool flag = false)
        : first(dest), second(len), rev(rev), tag(flag) { }
};
//typedef std::pair<int, int> edge;
typedef std::vector<edge> edgelist;
edgelist e[MAXN];

// == Template OvO ==
int64 d[MAXN];
void dijkstra(int source)
{
    for (int i = 0; i < n; ++i) d[i] = INF64;
    d[source] = 0;

    typedef std::pair<int64, int> node_data;
#define distance first
#define node_idx second
    typedef std::priority_queue<
        node_data, std::vector<node_data>, std::greater<node_data>
    > node_queue;
    
    node_queue q;
    node_data cur;
    q.push(node_data(0, source));
    while (!q.empty()) {
        cur = q.top(); q.pop();
        while (!q.empty() && d[cur.node_idx] != cur.distance) {
            cur = q.top(); q.pop();
        }
        if (d[cur.node_idx] != cur.distance) break;
        for (edgelist::iterator i = e[cur.node_idx].begin();
             i != e[cur.node_idx].end(); ++i)
        {
            if (d[i->first] > cur.distance + i->second) {
                d[i->first] = cur.distance + i->second;
                q.push(node_data(d[i->first], i->first));
            }
        }
    }
#undef distance
#undef node_idx
}
// == End ==

int main()
{
    scanf("%d%d%d%d%d", &n, &m, &l, &s, &t);
    int ui, vi, wi;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &ui, &vi, &wi);
        if (wi == 0) wi = INF32;
        e[ui].push_back(edge(vi, wi, e[vi].size(), wi == INF32));
        e[vi].push_back(edge(ui, wi, e[ui].size() - 1, wi == INF32));
    }

    dijkstra(s);
    if (d[t] < l) { puts("NO"); return 0; }

    // d[t] >= l
    for (int i = 0; i < n; ++i)
        for (edgelist::iterator j = e[i].begin(); j != e[i].end(); ++j)
            if (j->tag) j->second = 1;
    dijkstra(s);
    if (d[t] > l) { puts("NO"); return 0; }
    do {
        bool found = false;
        for (int i = 0; i < n; ++i) {
            for (edgelist::iterator j = e[i].begin(); j != e[i].end(); ++j)
                if (j->tag && d[i] + j->second == d[j->first]) {
                    j->second = l - d[t] + 1;
                    j->tag = false;
                    e[j->first][j->rev].second = l - d[t] + 1;
                    e[j->first][j->rev].tag = false;
                    found = true; break;
                }
            if (found) break;
        }
        dijkstra(s);
    } while (d[t] < l);
    puts("YES");
    for (int i = 0; i < n; ++i)
        for (edgelist::iterator j = e[i].begin(); j != e[i].end(); ++j)
            if (i < j->first)
                printf("%d %d %d\n", i, j->first, j->second); 

    return 0;
}