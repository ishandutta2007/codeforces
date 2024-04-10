#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> t(n+1,0);
    for(int i=1;i<=n;i++) cin >> t[i];
    vector<int> h(n+1,0);
    for(int i=1;i<=n;i++) cin >> h[i];
    vector<int> v[n+1];
    ll res=0;
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        res+=(t[a]+t[b]);
    }
    vector<bool> vis(n+1,0);
    const ll inf=(1ll<<40);
    auto chmax=[&](ll &a,ll b){a=max(a,b);};
    function<array<ll,2>(int,int)> dfs=[&](int a,int p)
    {
        vis[a]=1;
        array<int,2> tmp={0,0};
        vector<ll> d;
        ll now=0;
        for(int to:v[a])
        {
            if(to==p) continue;
            if(h[to]==h[a])
            {
                array<ll,2> nxt=dfs(to,a);
                now+=nxt[0];
                d.push_back(nxt[1]-nxt[0]);
            }
            else tmp[(h[to]>h[a])]++;
        }
        int cnt=d.size();
        ranges::sort(d,greater<>());
        array<ll,2> dp={-inf,-inf};
        for(int i=0;i<=cnt;i++)
        {
            if(i>=1) now+=d[i-1];
            array<int,2> c={tmp[0]+cnt-i,tmp[1]+i};
            ll cost=now;
            int m=min(c[0],c[1]);
            c[0]-=m; c[1]-=m;
            cost+=(ll(m)*t[a]);
            if(p==0) chmax(dp[0],cost);
            else
            {
                int x=(c[1]>0);
                if(c[x]>0) chmax(dp[x],cost+t[a]);
                chmax(dp[0],cost);
                chmax(dp[1],cost);
            }
        }
        return dp;
    };
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            array<ll,2> dp=dfs(i,0);
            res-=max(dp[0],dp[1]);
        }
    }
    cout << res << "\n";
    return 0;
}