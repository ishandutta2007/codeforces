#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define forn(i, a, n) for (int i = a; i < n; i++)

const int MAXN = 200100;
const int MOD = 1000000007;

int n, k, t1, t2;
vector <int> adj[MAXN];
int ans, x;
vector <int> v, arr;

void dfs(int node, int prev) {
    for(auto next : adj[node]) {
        if(next == prev) continue;
        dfs(next, node);
        arr[node] = arr[node]^arr[next];
    }
    if(arr[node]==x) {
        arr[node] = 0;
        ans++;
    }
}

void solve() {
    cin >> n >> k;
    v.resize(n); 
    arr.resize(n);
    ans = 0; x = 0;
    forn(i, 0, n) {
        adj[i].clear();
        cin >> v[i];
        x = x^v[i];
        arr[i] = v[i];
    }
    forn(i, 0, n - 1) {
        cin >> t1 >> t2;
        adj[--t1].push_back(--t2);
        adj[t2].push_back(t1);
    }
    if(x==0) {
        cout << "YES" << endl;
        return;
    }
    dfs(0, 0);
    if(ans >= 2 && k > 2) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
    int T = 1;
    cin >> T;
    while(T--) solve();

    return 0;
}