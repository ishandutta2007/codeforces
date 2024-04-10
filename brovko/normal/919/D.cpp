#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, used[300005], dp[300005][30];
string s;
vector <int> g[300005];

void dfs(int v)
{
    used[v]=1;
    dp[v][s[v]-'a']=1;

    int f[30];

    for(int i=0;i<26;i++)
        f[i]=0;

    for(auto to:g[v])
    {
        if(used[to]==1)
        {
            cout << -1;
            exit(0);
        }

        if(used[to]==0)
        {
            dfs(to);
        }

        for(int i=0;i<26;i++)
            f[i]=max(f[i], dp[to][i]);
    }

    for(int i=0;i<26;i++)
        dp[v][i]+=f[i];

    used[v]=2;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> s;
    for(int i=0;i<m;i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
    }

    for(int i=0;i<n;i++)
        if(used[i]==0)
            dfs(i);

    int ans=0;

    for(int i=0;i<n;i++)
        for(int j=0;j<26;j++)
            ans=max(ans, dp[i][j]);

    cout << ans;
}