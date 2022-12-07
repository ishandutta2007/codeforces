#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 100100
#define MOD 1000000007

int n, m, t1, t2;
set<int> adj[MAXN];
bool visited[MAXN];
int tin[MAXN];
int low[MAXN];
int timer;
int number_of_bridges;
vector<pair<int, int>> ans;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                number_of_bridges++;
        }
    }
}

void find_bridges() {
    number_of_bridges = 0;
    timer = 0;
    forn(i, 0, n) {
        visited[i] = false;
        tin[i] = -1;
        low[i] = -1;
    }
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

void process(int node) {
    if(adj[node].size()==0) return;
    int next = *adj[node].begin();
    adj[node].erase(next);
    adj[next].erase(node);
    ans.push_back({node, next});
    process(next);
}

void solve() {
    cin >> n >> m;
    forn(i, 0, m) {
        cin >> t1 >> t2;
        adj[--t1].insert(--t2);
        adj[t2].insert(t1);
    }
    find_bridges();
    if(number_of_bridges > 0) {
        cout << 0 << endl;
        return;
    }
    forn(i, 0, n) {
        while(adj[i].size()>0) process(i);
    }
    for(auto i : ans) {
        cout << i.first+1 << " " << i.second+1 << "\n";
    }
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}