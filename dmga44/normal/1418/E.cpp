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
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(998244353)
#define eps (1e-9)
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

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

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    vector<ll> d(n);
    vector<ll> ac(n+1);
    for(int i=0;i<n;i++)
        cin >> d[i];
    sort(all(d));

    for(int i=0;i<n;i++)
        ac[i+1]=ac[i]+d[i];

    for(int i=0;i<m;i++)
    {
        ll a,b;
        cin>> a >> b;
        ll c=lower_bound(all(d),b)-d.begin();
//        db(c)
        if(n-c<a)
        {
            db(0)
            continue;
        }
        ll sum1=ac[n]-ac[c];
        ll sum2=ac[c];
        sum1%=mod;
        sum2%=mod;
        c=n-c;
        ll f1=((c-a)*qp(c,mod-2))%mod;
        ll f2=((c-a+1)*qp(c+1,mod-2))%mod;
        db((sum1*f1+sum2*f2)%mod)
    }

    return 0;
}