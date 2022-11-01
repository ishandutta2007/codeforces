#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod=998244353;
int sum[(1<<20)][41][2];

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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> add[n+1];
    vector<int> rm[n+1];
    for(int i=1;i<=n;i++)
    {
        int l,r;
        cin >> l >> r;
        add[l].push_back(i);
        rm[r].push_back(i);
    }
    vector<array<int,2>> v[n+1];
    vector<array<int,2>> edges(m);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back({b,i});
        v[b].push_back({a,i});
        edges[i]={a,b};
    }
    vector<int> c((1<<m),0);
    vector<bool> vis(n+1,0);
    for(int i=0;i<(1<<m);i++) for(int j=0;j<=2*m;j++) for(int k=0;k<=1;k++) sum[i][j][k]=0;
    for(int i=0;i<(1<<m);i++)
    {
        vector<int> tmp;
        bool s=0;
        for(int j=0;j<m;j++)
        {
            if((i&(1<<j))==0) continue;
            auto [a,b]=edges[j];
            c[i]+=(vis[a]==0);
            c[i]+=(vis[b]==0);
            vis[a]=vis[b]=1;
            tmp.push_back(a);
            tmp.push_back(b);
            s=!s;
        }
        for(int t:tmp) vis[t]=0;
        sum[i][c[i]][s]=1;
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<(1<<m);j++)
        {
            if((j&(1<<i))==0) continue;
            for(int a=0;a<=2*m;a++) for(int b=0;b<=1;b++) sum[j][a][b]+=sum[j^(1<<i)][a][b];
        }
    }
    vector<ll> f(n+1,1);
    for(ll i=1;i<=n;i++) f[i]=(f[i-1]*i)%mod;
    vector<ll> finv(n+1,1);
    finv[n]=fpow(f[n],mod-2);
    for(ll i=n-1;i>=0;i--) finv[i]=(finv[i+1]*(i+1))%mod;
    auto ch=[&](int a,int b)->ll
    {
        ll res=f[a];
        res=(res*finv[b])%mod;
        res=(res*finv[a-b])%mod;
        return res;
    };
    ll res=0;
    ll now=0;
    vector<bool> in(n+1,0);
    int x=0;
    for(int i=1;i<=n;i++)
    {
        for(int a:add[i])
        {
            now++;
            in[a]=1;
            for(auto [to,id]:v[a]) if(in[to]==1) x^=(1<<id);
        }
        if(now>=i)
        {
            for(int a=0;a<=2*m;a++)
            {
                if(a>i) continue;
                res=(res+sum[x][a][0]*ch(now-a,i-a))%mod;
                res=(res-sum[x][a][1]*ch(now-a,i-a))%mod;
                if(res<0) res+=mod;
            }
        }

        for(int a:rm[i])
        {
            now--;
            in[a]=0;
            for(auto [to,id]:v[a]) if(in[to]==1) x^=(1<<id);
        }
    }
    cout << res << "\n";
    return 0;
}