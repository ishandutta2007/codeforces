#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v[n+1];
        for(int i=1;i<=n-1;i++)
        {
            int a,b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        vector<int> sz(n+1,0);
        vector<int> dp(n+1,0);
        function<void(int,int)> dfs=[&](int a,int p)
        {
            int x=0,y=0;
            sz[a]=1;
            for(int to:v[a])
            {
                if(to==p) continue;
                dfs(to,a);
                sz[a]+=sz[to];
                if(x==0) x=to;
                else y=to;
            }
            if(x==0) dp[a]=0;
            else if(y==0) dp[a]=(sz[x]-1);
            else dp[a]=max(sz[x]-1+dp[y],sz[y]-1+dp[x]);
        };
        dfs(1,0);
        cout << dp[1] << "\n";
    }
    return 0;
}