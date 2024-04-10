#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
#define MAXN 200005
#define MAXM 3005
#define mod ((ll)(998244353))

bool b[MAXN];
ll w[MAXN];
pii f[MAXM][MAXM],g[MAXM][MAXM];

pii sum(pii a,pii b)
{
    ll x1=a.first;
    ll x2=a.second;
    ll y1=b.first;
    ll y2=b.second;

    return pii((x1*y2+x2*y1)%mod,(x2*y2)%mod);
}

pii mul(pii a,pii b)
{
    ll x1=a.first;
    ll x2=a.second;
    ll y1=b.first;
    ll y2=b.second;

    return pii((x1*y1)%mod,(x2*y2)%mod);
}

ll qp(ll b,ll e)
{
    if(!e)
        return 1;
    ll x=qp(b,e/2);
    x=(x*x)%mod;
    if(e&1)
        x=(x*b)%mod;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> b[i];
    ll s[2];
    s[0]=s[1]=0;
    for(int i=0;i<n;i++)
    {
        cin >> w[i];
        s[b[i]]+=w[i];
    }

    for(int i=0;i<=m;i++)
        for(int j=0;j<=m;j++)
            f[i][j]=g[i][j]=pii(0,1);

    for(int i=0;i<=m;i++)
        f[i][m-i]=g[i][m-i]=pii(1,1);

    for(ll ii=m-1;ii>=0;ii--)
        for(ll jj=ii;jj>=0;jj--)
        {
            ll j=jj,i=ii-jj;
            pii pf1=pii(s[1]+i+1,s[1]+s[0]+i-j);
            pf1.second=max(1,pf1.second);
            f[i][j]=sum(f[i][j],mul(f[i+1][j],pf1));
            pii pf2=pii(s[0]-j,s[1]+s[0]+i-j);
            pf2.second=max(1,pf1.second);
            pf2.first=max(0,pf2.first);
            f[i][j]=sum(f[i][j],mul(f[i][j+1],pf2));

            pii pg1=pii(s[1]+i,s[1]+s[0]+i-j);
            pg1.second=max(1,pg1.second);
            g[i][j]=sum(g[i][j],mul(g[i+1][j],pg1));
            pii pg2=pii(s[0]-j-1,s[1]+s[0]+i-j);
            pg2.second=max(1,pg1.second);
            pg2.first=max(0,pg2.first);
            g[i][j]=sum(g[i][j],mul(g[i][j+1],pg2));
        }

//    for(int i=0;i<=m;i++,cout << '\n')
//        for(int j=0;j<=m;j++)
//            cout << "(" << f[i][j].first << ',' << f[i][j].second << ") ";

    for(int i=0;i<n;i++)
    {
        if(b[i])
            db((((w[i]*f[0][0].first)%mod)*qp(f[0][0].second,mod-2))%mod)
        else
            db((((w[i]*g[0][0].first)%mod)*qp(g[0][0].second,mod-2))%mod)
    }

    return 0;
}