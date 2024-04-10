#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
static const int MAXN = 100007;
struct edge {
    int dest; bool flip;
    edge(int dest, bool flip) : dest(dest), flip(flip) { }
};
typedef std::vector<edge> edgelist;

int n, m;
edgelist e[MAXN];
bool vis[MAXN], clr[MAXN], slctd[MAXN];

std::vector<int> solve()
{
    std::vector<int> ret, tmp[2];
    tmp[0].reserve(32);
    tmp[1].reserve(32);
    memset(vis, false, sizeof vis);
    memset(slctd, false, sizeof slctd);
    int last_unvis = 0;
    std::queue<int> q;
    while (last_unvis < n) {
        tmp[0].clear(); tmp[1].clear();
        for (; last_unvis < n; ++last_unvis) if (!vis[last_unvis]) {
            q.push(last_unvis);
            vis[last_unvis] = true;
            clr[last_unvis] = true;
            tmp[1].push_back(last_unvis);
            break;
        }
        if (last_unvis == n) break;
        do {
            int u = q.front(); q.pop();
            for (edgelist::iterator i = e[u].begin(); i != e[u].end(); ++i)
                if (!vis[i->dest]) {
                    q.push(i->dest);
                    vis[i->dest] = true;
                    clr[i->dest] = (clr[u] ^ i->flip);
                    tmp[clr[i->dest]].push_back(i->dest);
                } else {
                    if (clr[i->dest] != (clr[u] ^ i->flip)) {
                        for (int j = 0; j <= n; ++j) ret.push_back(-1);
                        return ret;
                    }
                }
        } while (!q.empty());
        int target = (tmp[0].size() < tmp[1].size() ? 0 : 1);
        for (std::vector<int>::iterator i = tmp[target].begin(); i != tmp[target].end(); ++i)
            slctd[*i] = true;
    }
    for (int i = 0; i < n; ++i) if (slctd[i]) ret.push_back(i);
    return ret;
}

int main()
{
    scanf("%d%d", &n, &m);
    int u, v; char ch;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d %c", &u, &v, &ch); --u, --v;
        e[u].push_back(edge(v, ch == 'R'));
        e[v].push_back(edge(u, ch == 'R'));
    }
    std::vector<int> a = solve();
    for (int i = 0; i < n; ++i)
        for (edgelist::iterator j = e[i].begin(); j != e[i].end(); ++j)
            j->flip ^= 1;
    std::vector<int> b = solve();
    if (a.size() > b.size()) std::swap(a, b);
    if (a.size() != 0 && a[0] == -1) puts("-1");
    else {
        printf("%lu\n", a.size());
        for (std::vector<int>::iterator i = a.begin(); i != a.end(); ++i)
            printf("%d ", *i + 1);
        putchar('\n');
    }
    return 0;
}