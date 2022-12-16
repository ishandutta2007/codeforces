#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 500500;

vector<int> adj[N];

int nxt=2;

pii ans[N];

void dfs(int u, int p) {
    ans[u].second = nxt+adj[u].size()-(p!=0);
    nxt += adj[u].size()+1-(p!=0);
    int be = nxt-2;
    for (int i=0, j=be; i<adj[u].size(); ++i, --j) {
        int v = adj[u][i];
        if (v == p) {
            ++j;
            continue;
        }
        ans[v].first = j;
        dfs(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i=1; i<n; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ans[1].first = 1;
    dfs(1, 0);
    for (int i=1; i<=n; ++i) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
        
    return 0;
}