#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod=1000000007;

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
    const int D=1000;
    int n,m,r;
    cin >> n >> m >> r;
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
    vector<vector<int>> sum(D+1,vector<int>(D+1,0));
    vector<array<int,3>> snakes(n);
    for(int i=0;i<n;i++)
    {
        auto &[x,y,b]=snakes[i];
        cin >> x >> y >> b;
        sum[x][y]++;
    }
    for(int i=1;i<=D;i++) for(int j=1;j<=D;j++) sum[i][j]+=sum[i][j-1];
    for(int i=1;i<=D;i++) for(int j=1;j<=D;j++) sum[i][j]+=sum[i-1][j];
    auto s=[&](int a,int b,int c,int d)->int
    {
        if(a>c||b>d) return 0;
        a=max(a,1);
        b=max(b,1);
        c=min(c,D);
        d=min(d,D);
        return (sum[c][d]-sum[c][b-1]-sum[a-1][d]+sum[a-1][b-1]);
    };
    auto add=[&](ll &a,ll b){a=(a+b)%mod;};
    auto sub=[&](ll &a,ll b){a=(a-(b%mod)+mod)%mod;};
    auto mul=[&](ll &a,ll b){a=(a*b)%mod;};
    ll res=0;
    for(auto [x,y,b]:snakes)
    {
        int one=s(x-r,y-r,x+r,y+r);
        int two=n-one;
        for(int i=1;i<=one;i++)
        {
            if(i>m||m-i>two) continue;
            ll now=b;
            mul(now,b);
            mul(now,ch(one,i));
            mul(now,ch(two,m-i));
            add(res,now);
        }
    }
    vector<ll> pre(n+1,0);
    for(int both=1;both<=n;both++)
    {
        for(int k=1;k<=both;k++)
        {
            if(k>m||m-k>n-both) continue;
            ll now=ch(both,k);
            mul(now,ch(n-both,m-k));
            add(pre[both],now);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            auto [x1,y1,b1]=snakes[i];
            auto [x2,y2,b2]=snakes[j];
            int both=s(max(x1,x2)-r,max(y1,y2)-r,min(x1,x2)+r,min(y1,y2)+r);
            ll tmp=(2*b1);
            mul(tmp,b2);
            mul(tmp,pre[both]);
            add(res,tmp);
            int one=s(x1-r,y1-r,x1+r,y1+r)-both;
            int two=s(x2-r,y2-r,x2+r,y2+r)-both;
            int z=n-both;
            if(z<m) continue;
            tmp=ch(z,m);
            if(z-one>=m) sub(tmp,ch(z-one,m));
            if(z-two>=m) sub(tmp,ch(z-two,m));
            if(z-one-two>=m) add(tmp,ch(z-one-two,m));
            mul(tmp,2*b1);
            mul(tmp,b2);
            add(res,tmp);
        }
    }
    cout << res << "\n";
    return 0;
}