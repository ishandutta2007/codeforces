#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;
const int INF = 9100000000000000000;
const double EPS = 1E-7;

vector<vector<pair<int, int>>> adj;
map<int, int> ans;
bool x = 1;

void dfs(int node, int prev) {
    for(auto next : adj[node]) {
        if(next.first == prev) continue;
        if(x) ans[next.second] = 2;
        else ans[next.second] = 5;
        // cerr << x << " " << next.second << endl;
        x = !x;
        dfs(next.first, node);
    }
}

void solve() {
    int n, t1, t2;
    cin >> n;
    adj.resize(n);
    forn(i, 0, n) adj[i].clear();
    ans.clear();
    forn(i, 0, n - 1) {
        cin >> t1 >> t2;
        --t1; --t2;
        adj[t1].push_back({t2, i});
        adj[t2].push_back({t1, i});
    }
    int cnt = 0;
    int leaf = -1;
    forn(i, 0, n) {
        if(adj[i].size() == 1) {
            leaf = i;
            cnt++;
        }
    }
    if(cnt > 2) {
        cout << -1 << endl;
        return;
    }
    x = 1;
    dfs(leaf, leaf);
    // forn(i, 0, n) {
    //     cout << i << ":";
    //     for(auto next : adj[i]) cout << next.first << " ";
    //     cout << endl;
    // }
    for(auto i : ans) cout << i.second << " ";
    cout << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    for(int I = 1; I <= T; I++) {
        // cout << "Case #" << I << ": ";
        solve(); 
    }

    return 0;
}