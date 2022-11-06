#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
using namespace std;
const int N = 1e6;
priority_queue<pair<int, int> > q;
vector<int> g[N];
int a[N];
int n, m;
set<int> f[N];
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i ++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        if (f[i].size() == a[i] - 1)
            q.push({-a[i], i});
    }
    vector<int> ans;
    while (q.size()) {
        auto u = q.top();
        ans.push_back(u.second);
        q.pop();
        u.first = -u.first;
        for (auto v:g[u.second]) {
            if (a[v] == u.first) {
                puts("-1");
                return 0;
            }
            if (a[v] > u.first && f[v].find(u.first) == f[v].end()) {
                f[v].insert(u.first);
                if (f[v].size() == a[v] - 1)
                    q.push({-a[v], v});
            }
        }
    }
    if (ans.size() == n) {
        for (auto u:ans)
            printf("%d ", u);
    } else {
        puts("-1");
    }
    return 0;
}