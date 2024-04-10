#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(4e2+5)

ll fac[MAXN];
ll ifac[MAXN];
ll dp[MAXN][MAXN];

ll qp(ll b,ll e)
{
    if(!e)
        return 1;
    ll x=qp(b,e>>1);
    x=(x*x)%mod;
    if(e&1)
        x=(x*b)%mod;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,k;
    cin >> n >> k;
    fac[0]=ifac[0]=1;
    for(int i=1;i<MAXN;i++)
    {
        fac[i]=(fac[i-1]*i)%mod;
        ifac[i]=qp(fac[i],mod-2);
    }
//    db(qp(8,mod-2))
    dp[0][0]=1;
    for(int i=2;i<=k+1;i++)
    {
        vector<ll> times;
        times.push_back(1);
        for(int j=1;j*(i-1)<=k;j++)
            times.push_back((qp((fac[i-1]*ifac[i])%mod,j)*ifac[j])%mod);
//        db(i)
//        for(auto x : times)
//            cout << x << ' ';
//        db("")
//        db("")
        for(int j=min(2*k,n);j>=0;j--)
            for(int g=0;g<=k;g++)
                for(int t=1;t<times.size() && t*i+j<=min(2*k,n);t++)
                    dp[t*i+j][g+t]=(dp[t*i+j][g+t]+dp[j][g]*times[t])%mod;
    }

    ll mul=1;
    for(int i=1;i<=min(2*k,n);i++)
    {
        mul=(mul*(n-i+1))%mod;
        for(int j=0;j<=k;j++)
            dp[i][j]=(dp[i][j]*mul)%mod;
    }

//    for(int i=0;i<=n;i++,cout << '\n')
//    {
//        for(int j=0;j<=k;j++)
//            cout << dp[i][j] << ' ';
//    }
//    db("")

    for(int i=1;i<=k;i++)
    {
        ll ans=0;
        for(int j=0;j<=min(2*k,n);j++)
            for(int g=0;g<=k;g++)
                if(j-g<=i && ((i-(j-g))&1)==0)
                    ans=(ans+dp[j][g])%mod;
        cout << ans << ' ';
    }
    cout << '\n';

    return 0;
}