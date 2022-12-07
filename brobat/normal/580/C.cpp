#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 100100
#define MOD 1000000007

int n, m, t1, t2;
int cat[MAXN];
bool visited[MAXN];
vector<int> adj[MAXN];
int ans;

void dfs(int node, int num_cats) {
    visited[node] = true;
    if(num_cats != -1) {
        if(cat[node]) num_cats++;
        else num_cats = 0;
        if(num_cats > m) num_cats = -1;
    }
    for(auto next : adj[node]) {
        if(!visited[next]) dfs(next, num_cats);
    }
    if(adj[node].size()==1 && node != 1) {
        if(num_cats != -1) ans++;
    }
}

void solve() {
    cin >> n >> m;
    forn(i, 0, n) cin >> cat[i+1];
    forn(i, 0, n-1) {
        cin >> t1 >> t2;
        adj[t1].push_back(t2);
        adj[t2].push_back(t1);
    }
    ans = 0;
    dfs(1, 0);
    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(numeric_limits<double>::max_digits10);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // int t; cin >> t; while(t--)
    {solve();}
    return 0;
}