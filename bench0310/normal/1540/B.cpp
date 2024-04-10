#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
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
    const ll mod=1000000007;
    auto add=[&](ll a,ll b)->ll{return (a+b)%mod;};
    auto mul=[&](ll a,ll b)->ll{return (a*b)%mod;};
    vector<ll> inv(n+1,1);
    for(int i=2;i<=n;i++) inv[i]=mod-mul(mod/i,inv[mod%i]);
    vector f(n+1,vector(n+1,ll(0)));
    for(int i=0;i<=n;i++) f[0][i]=1;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) f[i][j]=mul(add(f[i-1][j],f[i][j-1]),inv[2]);
    vector<int> depth(n+1,0);
    vector<int> sub[n+1];
    ll res=0;
    function<void(int,int)> dfs=[&](int a,int p)
    {
        depth[a]=depth[p]+1;
        for(int to:v[a])
        {
            if(to==p) continue;
            dfs(to,a);
            for(int b:sub[to])
            {
                for(int c:sub[a])
                {
                    int x=depth[max(b,c)]-depth[a];
                    int y=depth[min(b,c)]-depth[a];
                    res=add(res,f[x][y]);
                }
                res=add(res,(a>b));
            }
            for(int b:sub[to]) sub[a].push_back(b);
        }
        sub[a].push_back(a);
    };
    for(int i=1;i<=n;i++)
    {
        dfs(i,0);
        for(int j=1;j<=n;j++) sub[j].clear();
    }
    cout << mul(res,inv[n]) << "\n";
    return 0;
}