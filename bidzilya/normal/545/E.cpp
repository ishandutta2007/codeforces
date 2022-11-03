#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
vector<vector<pair<int, int> > > g;
vector<int> w, from, to;
int start;

const long long kInf = 1e18;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    w.resize(m);
    from.resize(m);
    to.resize(m);
    g.resize(n);
    for (int i = 0; i < m; ++i) {
        cin >> from[i] >> to[i] >> w[i];
        --from[i];
        --to[i];
        int v1 = from[i];
        int v2 = to[i];
        g[v1].push_back(make_pair(v2, i));
        g[v2].push_back(make_pair(v1, i));
    }
    cin >> start;
    --start;
    vector<long long> d(n, kInf);
    priority_queue<pair<long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > q;
    d[start] = 0;
    q.push(make_pair(0, start));
    while (!q.empty()) {
        long long cd = q.top().first;
        int v = q.top().second;
        q.pop();
        
        if (cd > d[v]) {
            continue;
        }
        for (int i = 0; i < (int) g[v].size(); ++i) {
            int u = g[v][i].first;
            long long nd = cd + w[g[v][i].second];
            if (nd < d[u]) {
                d[u] = nd;
                q.push(make_pair(nd, u));
            }
        }
    }
    vector<pair<int, int> > torder(n);
    for (int i = 0; i < n; ++i) {
        torder[i].first = d[i];
        torder[i].second = i;
    }
    sort(torder.begin(), torder.end());
    vector<int> order(n);
    for (int i = 0; i < n; ++i) {
        order[i] = torder[i].second;
    }
    vector<int> mn(n, 1e9 + 10);
    vector<int> cans(n);
    mn[start] = 0;
    for (int i = 0; i < n; ++i) {
        int v = order[i];
        for (int j = 0; j < (int) g[v].size(); ++j) {
            int idx = g[v][j].second;
            int cto = g[v][j].first;
            if (d[cto] == d[v] + w[idx]) {
                if (w[idx] < mn[cto]) {
                    mn[cto] = w[idx];
                    cans[cto] = idx;
                }
            }
        }
    }
    long long sm = 0;
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (i != start) {
            int idx = cans[i];
            sm += w[idx];
            ans.push_back(idx);
        }
    }
    sort(ans.begin(), ans.end());
    cout << sm << endl;
    for (int i = 0; i < (int) ans.size(); ++i) {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;
    
    return 0;
}