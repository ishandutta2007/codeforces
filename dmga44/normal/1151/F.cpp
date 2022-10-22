#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define mod ((ll)1e9+7)
#define MAXN 105

ll a[MAXN],n;
pii m[MAXN][MAXN],aux[MAXN][MAXN],b[MAXN][MAXN],aux2[MAXN][MAXN];

pii sum(pii x,pii y)
{
    ll x1=x.first;
    ll x2=x.second;
    ll y1=y.first;
    ll y2=y.second;
    return pii((x1*y2+x2*y1)%mod,(x2*y2)%mod);
}

pii mul(pii x,pii y)
{
    ll x1=x.first;
    ll x2=x.second;
    ll y1=y.first;
    ll y2=y.second;
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

void mul2()
{
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            aux2[i][j]=pii(0,1);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            for(int u=0;u<=n;u++)
                aux2[i][j]=sum(aux2[i][j],mul(m[i][u],aux[u][j]));
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            m[i][j]=aux2[i][j];
}

void qp2(ll e)
{
    if(e==1)
        return ;
    qp2(e/2);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            aux[i][j]=m[i][j];
    mul2();
    if(e&1)
    {
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                aux[i][j]=b[i][j];
        mul2();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll k;
    cin >> n >> k;
    ll x=0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        x+=a[i];
    }

    ll fal=0;
    for(int i=n-1;i>=n-x;i--)
        fal+=(1-a[i]);
    for(ll i=0;i<=n;i++)
        for(ll j=0;j<=n;j++)
            m[i][j]=pii(0,1);
    m[fal+1][0]=pii(1,1);
    ll ccc=(n*(n-1))/2;

    for(ll i=0;i<=min(x,n-x);i++)
    {
        m[i][i+1]=pii(i*i,ccc);
        m[i+2][i+1]=pii((x-i)*(n-x-i),ccc);
        m[i+1][i+1]=pii(ccc-i*i-(x-i)*(n-x-i),ccc);
    }
    n=min(x,n-x)+1;
    for(ll i=0;i<=n;i++)
        for(ll j=0;j<=n;j++)
            b[i][j]=m[i][j];
    qp2(k+1);

    db((qp(m[1][0].second,mod-2)*m[1][0].first)%mod)

    return 0;
}