#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> adj[200002];
bool dp[200002];

int dfs(int x, int p)
{
    dp[x] = true;
    int ret = 0;
    for(int i : adj[x])
    {
        if(i == p) continue;
        ret += dfs(i, x);
        if(dp[i]) dp[x] = false;
    }
    if(dp[x]) ret++;
    else ret--;
    return ret;
}

void solve()
{
    int n; cin >> n;
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=1;i<n;i++)
    {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int L = 0;
    for(int i=2;i<=n;i++)
    {
        if(adj[i].size() == 1) L++;
    }

    int s = 200002;
    int ans = 0, tmp = 0;
    for(int i : adj[1])
    {
        ans += dfs(i, 1);
    }
    for(int i : adj[1])
    {
        if(dp[i] == 1)
        {
            ans--;
            break;
        }
    }
    ans++;
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}