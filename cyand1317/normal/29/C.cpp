#include <cstdio>
#include <map>
#include <set>
#include <vector>
static const int MAXN = 1e5 + 4;

int n;
std::map< int, std::vector<int> > adj;
std::set<int> vis;

int main()
{
    scanf("%d", &n);
    int u, v;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start = -1;
    for (std::map< int, std::vector<int> >::iterator i = adj.begin(); i != adj.end(); ++i)
        if (i->second.size() == 1) { start = i->first; break; }

    printf("%d", start); vis.insert(start);
    int last = start;
    for (int i = 0; i < n; ++i) {
        for (std::vector<int>::iterator j = adj[last].begin(); j != adj[last].end(); ++j)
            if (!vis.count(*j)) { printf(" %d", last = *j); vis.insert(last); break; }
    }

    putchar('\n');
    return 0;
}