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
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(ll)(1e9+7);
const ld eps=(1e-8);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(3e5+5)

int ask(int p)
{
    cout << "? " << p+1 << '\n';
    cout.flush();
    int x;
    cin >> x;
    return x;
}

int32_t main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    mt19937 rng(time(0));

    ll n,k;
    cin >> n >> k;
    ll p,t;
    ll cont=0;
    while(1)
    {
        ll xxx=rng();
        xxx=abs(xxx)%n;
        ll x=ask(xxx);
        cont++;
        if(x!=k)
        {
            if(x>k)
                xxx=(xxx-min((n-1)/2,cont)-1+n)%n;
            p=xxx;
            break;
        }
    }

    ///at most t pa alante

    ll last;
    while(1)
    {
        ll x=ask(p);
        cont++;
        last=x;
        if(x<k)
            break;
        p=(p+1)%n;
    }

    t=min(cont,(n-1)/2);
    ll add=0;
    for(int po=(1<<10);po;po>>=1)
        if(add+po<t)
        {
            ll v1=ask((p+add+po)%n);
            ll v2=ask((p+add+po+1)%n);
            if(v1>=v2 && v2<k)
                add+=po;
        }
    p=(p+add)%n;
    last=1e18;
    ll res;
    while(1)
    {
        ll x=ask(p);
        if(x>last)
        {
            res=p;
            break;
        }
        last=x;
        p=(p+1)%n;
    }
    cout << "! " << res+1 << '\n';
    cout.flush();

    return 0;
}