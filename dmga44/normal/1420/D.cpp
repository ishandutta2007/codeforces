#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(998244353)
#define eps (1e-9)
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(3e5+5)

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

ll fac[MAXN],ifac[MAXN];

ll comb(int n,int m)
{
    if(n<m)
        return 0;
    ll den=(ifac[m]*ifac[n-m])%mod;
    return (fac[n]*den)%mod;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fac[0]=ifac[0]=1;
    for(int i=1;i<MAXN;i++)
    {
        fac[i]=(fac[i-1]*i)%mod;
        ifac[i]=qp(fac[i],mod-2);
    }

    int n,k;
    cin >> n >> k;
    vector<pii> ls;
    for(int i=0;i<n;i++)
    {
        int l,r;
        cin >> l >> r;
        ls.push_back(pii(l,1));
        ls.push_back(pii(r+1,-1));
    }

    sort(all(ls));
    int cant=0;
    ll res=0;
    for(int i=0;i<ls.size();i++)
    {
        int ty=ls[i].s;
        if(ty==1)
        {
//            cout << cant << ' ' << k-1 << ' ' << comb(cant,k-1) << '\n';
            res=(res+comb(cant,k-1))%mod;
            cant++;
        }
        else
            cant--;
    }
    db(res)

    return 0;
}