#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll l[100002], r[100002];
vector<int> adj[100002];
ll dp1[100002], dp2[100002];
//Min, Max
void dfs(int x, int p)
{
    for(int i : adj[x])
    {
        if(i == p) continue;
        dfs(i, x);
        dp1[x] += max(dp1[i] + abs(l[i] - l[x]), dp2[i] + abs(r[i] - l[x]));
        dp2[x] += max(dp1[i] + abs(l[i] - r[x]), dp2[i] + abs(r[i] - r[x]));
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1;i<=n;i++) cin >> l[i] >> r[i];
        for(int i=1;i<=n;i++) dp1[i] = dp2[i] = 0;
        for(int i=1;i<=n;i++) adj[i].clear();
        for(int i=1;i<n;i++)
        {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, -1);
        cout << max(dp1[1], dp2[1]) << "\n";
    }
}