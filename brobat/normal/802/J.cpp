#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forn(i, a, n) for (int i = a; i < n; i++)
#define MAXN 105
#define MOD 1000000007

int n, t1, t2, t3;
vector<pair<int, int>> adj[MAXN];
vector<int> ans;

void dfs(int node, int prev, int cost) {
    if(adj[node].size()==1 && node != 0) {
        ans.push_back(cost);
        return;
    }
    for(auto next : adj[node]) {
        if(next.first!=prev) {
            dfs(next.first, node, cost + next.second);
        }
    }
}

void solve() {
    cin >> n;
    forn(i, 0, n-1) {
        cin >> t1 >> t2 >> t3;
        adj[t1].push_back({t2, t3});
        adj[t2].push_back({t1, t3});
    }
    dfs(0, 0, 0);
    sort(ans.begin(), ans.end(), greater<int>());
    cout << ans[0];
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