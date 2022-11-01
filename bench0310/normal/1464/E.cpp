#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod=998244353;

ll fpow(ll b,ll e)
{
    ll res=1;
    while(e)
    {
        if(e&1) res=(res*b)%mod;
        b=(b*b)%mod;
        e/=2;
    }
    return res;
}

ll inv(ll b)
{
    return fpow(b,mod-2);
}

ll add(ll a,ll b){return (((a+b)%mod)+mod)%mod;}
ll sub(ll a,ll b){return (((a-b)%mod)+mod)%mod;}
ll mul(ll a,ll b){return (((a*b)%mod)+mod)%mod;}

vector<ll> gauss(vector<vector<ll>> a)
{
    int n=a.size();
    auto m=[&](int r,ll x){for(ll &b:a[r]) b=mul(b,x);};
    for(int j=0;j<n;j++)
    {
        int r=-1;
        for(int i=j;i<n;i++) if(a[i][j]!=0) r=i;
        swap(a[j],a[r]);
        m(j,inv(a[j][j]));
        for(int i=0;i<n;i++)
        {
            if(i==j) continue;
            ll x=a[i][j];
            for(int k=0;k<=n;k++) a[i][k]=sub(a[i][k],mul(a[j][k],x));
        }
    }
    vector<ll> res(n,0);
    for(int i=0;i<n;i++) res[i]=a[i][n];
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> v[n+1];
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
    }
    vector<int> g(n+1,-1);
    vector<bool> mex(n+1,0);
    function<void(int)> dfs=[&](int a)
    {
        for(int to:v[a]) if(g[to]==-1) dfs(to);
        for(int to:v[a]) mex[g[to]]=1;
        for(int i=0;i<=n;i++)
        {
            if(mex[i]==0)
            {
                g[a]=i;
                break;
            }
        }
        for(int to:v[a]) mex[g[to]]=0;
    };
    for(int i=1;i<=n;i++) if(g[i]==-1) dfs(i);
    int mx=0;
    for(int i=1;i<=n;i++) mx=max(mx,g[i]);
    for(int j=30;j>=0;j--) mx|=(mx>>j);
    vector<int> cnt(mx+1,0);
    for(int i=1;i<=n;i++) cnt[g[i]]++;
    vector<vector<ll>> a(mx+1,vector<ll>(mx+2,0));
    for(int i=0;i<=mx;i++)
    {
        for(int j=0;j<=mx;j++) a[i][i^j]=mul(cnt[j],inv(n+1));
        a[i][i]=sub(a[i][i],1);
        if(i>0) a[i][mx+1]=sub(0,inv(n+1));
    }
    ll res=gauss(a)[0];
    cout << res << "\n";
    return 0;
}