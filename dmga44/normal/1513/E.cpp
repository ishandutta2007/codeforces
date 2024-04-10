#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

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
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

ll fac[MAXN];
ll ifac[MAXN];

ll comb(ll n,ll m)
{
    ll den=(ifac[m]*ifac[n-m])%mod;
    return (fac[n]*den)%mod;
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

    fac[0]=1;
    ifac[0]=1;
    for(int i=1;i<MAXN;i++)
    {
        fac[i]=(fac[i-1]*i)%mod;
        ifac[i]=qp(fac[i],mod-2);
    }

    ll n;
    cin >> n;
    ll sum=0;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        sum+=a[i];
    }

    ll x=sum/n;
    if(sum!=x*n)
    {
        db(0)
        return 0;
    }


    map<int,int> f;
    int c1=0;
    int c2=0;
    for(int i=0;i<n;i++)
    {
        f[a[i]]++;
        if(a[i]<x)
            c1++;
        if(a[i]>x)
            c2++;
    }
    vector<int> m1;
    vector<int> m2;

    int s1=0;
    int s2=0;
    for(auto p : f)
    {
        if(p.f<x)
        {
            m1.push_back(p.s);
            s1+=p.s;
        }
        if(p.f>x)
        {
            m2.push_back(p.s);
            s2+=p.s;
        }
    }

    int ss1=s1;
    int ss2=s2;
    ll k1=1;
    for(auto x : m1)
    {
        k1=(k1*comb(ss1,x))%mod;
        ss1-=x;
    }
    ll k2=1;
    for(auto x : m2)
    {
        k2=(k2*comb(ss2,x))%mod;
        ss2-=x;
    }
//    cout << c1 << ' ' << c2 << '\n';

    ll ans=(k1*k2)%mod;
    if(min(c1,c2)==0)
        ans=1;
    else if(min(c1,c2)==1)
    {
        ans=(ans*comb(n,s1))%mod;
        ans=(ans*comb(n-s1,s2))%mod;
    }
    else
    {
        ll mul=0;
        for(int i=s1;i<=n-s2;i++)
            mul=(mul+comb(n-i,s2)*comb(i-1,s1-1))%mod;
        ans=(ans*2*mul)%mod;
    }
    db(ans)

    return 0;
}