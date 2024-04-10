#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    ll k;
    cin >> n >> m >> k;
    vector<int> x(n+1,0);
    for(int i=1;i<=n;i++) cin >> x[i];
    vector<int> v[n+1];
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    const int inf=(1<<30);
    int l=0,r=inf;
    while(l<r-1)
    {
        int lim=(l+r)/2;
        bool cycle=0;
        int mx=0;
        vector<int> st(n+1,0);
        vector<int> dp(n+1,0);
        function<void(int)> dfs=[&](int a)
        {
            st[a]=1;
            dp[a]=1;
            mx=max(mx,1);
            for(int to:v[a])
            {
                if(x[to]>lim) continue;
                if(st[to]==0) dfs(to);
                else if(st[to]==1) cycle=1;
                dp[a]=max(dp[a],dp[to]+1);
                mx=max(mx,dp[a]);
            }
            st[a]=2;
        };
        for(int i=1;i<=n;i++) if(x[i]<=lim&&st[i]==0) dfs(i);
        if(mx>=k||cycle) r=lim;
        else l=lim;
    }
    if(r<inf) cout << r << "\n";
    else cout << "-1\n";
    return 0;
}