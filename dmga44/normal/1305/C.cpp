#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 200005

ll a[MAXN],f[MAXN],c[MAXN];

ll qp(ll b,ll e,ll mod)
{
    if(!e)
        return 1;

    ll x=qp(b,e/2,mod);
    x=(x*x)%mod;
    if(e&1)
        x=(x*b)%mod;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >>n >> m;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        c[i]=a[i];
        a[i]%=m;
        f[a[i]]++;
    }

    ll res=1;
    for(int i=0;i<m;i++)
        if(f[i]>1)
            res=0;
    if(!res)
    {
        db(0)
        return 0;
    }

    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            res=(res*abs(c[i]-c[j]))%m;
    db(res)

    return 0;
}