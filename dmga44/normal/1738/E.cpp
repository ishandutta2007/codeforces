#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native", "no-zero-upper") // Enable AVX

/// UH Top
#include <bits/stdc++.h>
#define db(x) cerr << #x << ':' << (x) << '\n';
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
// #define int ll
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
// typedef __int128_t int128;
typedef pair<ll, ll> pii;
typedef pair<ld, ll> pdi;
typedef pair<ld, ld> pdd;
typedef pair<ld, pdd> pdp;
typedef pair<string, ll> psi;
typedef pair<ll, string> pls;
typedef pair<string, string> pss;
typedef pair<ll, pii> pip;
typedef pair<pii, pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef vector<ll> vi;
typedef pair<point, int> ppi;
#define prec(n)        \
    cout.precision(n); \
    cout << fixed
const ll mod = (998244353);
const ld eps = (1e-9);
const ll oo = (ll)(1e18 + 5);
#define pi acos(-1)
#define MAXN (ll)(1e5 + 5)

ll fac[MAXN],ifac[MAXN];

ll qp(ll b,ll e)
{
    ll ans=1;
    while(e)
    {
        if(e&1)
            ans=(ans*b)%mod;
        e>>=1;
        b=(b*b)%mod;
    }
    return ans;
}

ll comb(ll n,ll m)
{
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

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<ll> ac(n+1);
        for(int i=0;i<n;i++)
        {
            int x;
            cin >> x;
            ac[i+1]=ac[i]+x;
        }
        if(ac[n]==0)
        {
            ll ans=1;
            for(int i=0;i<n-1;i++)
                ans=(ans+ans)%mod;
            cout << ans << '\n';
            continue;
        }
        map<ll,pii> freq;
        for(int i=1;i<n;i++)
            if(ac[i]*2<ac[n])
                freq[ac[i]].first++;
        for(int i=1;i<n;i++)
            if((ac[n]-ac[i])*2<ac[n])
                freq[ac[n]-ac[i]].second++;
            
        int cant=0;
        for(int i=1;i<n;i++)
            if(ac[i]*2==ac[n])
                cant++;
        ll ans=1;
        for(int i=0;i<cant;i++)
            ans=(ans+ans)%mod;
        for(auto y : freq)
        {
            pii p=y.second;
            // cout << p.first << ' ' << p.second << '\n';
            ll sum=0;
            for(int j=0;j<=min(p.first,p.second);j++)
                sum=(sum+comb(p.first,j)*comb(p.second,j))%mod;
            ans=(ans*sum)%mod;
        }
        cout << ans << '\n';
    }

    return 0;
}