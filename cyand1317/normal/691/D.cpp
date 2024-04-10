#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
static const int MAXN = 1e6 + 7;
static const int MAXM = 1e6 + 7;
typedef std::vector<int> edgelist;

int n, m;
int p[MAXN], pp[MAXN];
int a[MAXM], b[MAXM];
edgelist e[MAXN];
bool vis[MAXN] = { false };

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &p[i]);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a[i], &b[i]); --a[i], --b[i];
        e[a[i]].push_back(b[i]);
        e[b[i]].push_back(a[i]);
    }

    int last_unvis = 0;
    while (last_unvis < n) {
        std::vector<int> vals, poss;
        std::queue<int> q;
        while (last_unvis < n && vis[last_unvis]) ++last_unvis;
        if (last_unvis == n) break;
        q.push(last_unvis);
        vis[last_unvis] = true;
        vals.push_back(p[last_unvis]);
        poss.push_back(last_unvis);
        do {
            int r = q.front(); q.pop();
            for (edgelist::iterator i = e[r].begin(); i != e[r].end(); ++i)
                if (!vis[*i]) {
                    q.push(*i);
                    vis[*i] = true;
                    vals.push_back(p[*i]);
                    poss.push_back(*i);
                }
        } while (!q.empty());
        std::sort(vals.begin(), vals.end());
        std::sort(poss.begin(), poss.end());
        std::vector<int>::iterator i = vals.begin();
        std::vector<int>::reverse_iterator j = poss.rbegin();
        for (; i != vals.end(); ++i, ++j) pp[*j] = *i;
    }
    for (int i = 0; i < n; ++i)
        printf("%d%c", pp[i], i == n - 1 ? '\n' : ' ');
    return 0;
}