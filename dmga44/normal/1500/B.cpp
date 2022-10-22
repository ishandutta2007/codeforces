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
const ll mod=(ll)(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(1e6+5)

ll ini[MAXN];
ll pos[MAXN];
vector<pii> posi;
vector<ll> a,b;
ll n,m,k;

ll aux(ll x)
{
    ll res=x;
    ll mcm=(n*m)/__gcd(n,m);
    for(auto p : posi)
    {
        ll dif=p.f;
        ll i=p.s;
        ll y=x-ini[dif]-i;
//        cout << x << ' ' << ini[dif] << ' ' << mcm << '\n';
        if(y>0)
            res-=((y-1)/mcm)+1;
    }
//    cout << x << ' ' << res << '\n';
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    a.resize(n);
    b.resize(m);
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<m;i++)
        cin >> b[i];

    if(n>m)
    {
        swap(n,m);
        swap(a,b);
    }

    for(int i=0;i<MAXN;i++)
        pos[i]=-1;
    for(int i=0;i<m;i++)
        pos[b[i]]=i;

    for(int i=0;i<MAXN;i++)
        ini[i]=oo;
    for(ll i=0;i<m/(__gcd(n,m));i++)
        ini[(n*i)%m]=n*i;

    for(int i=0;i<n;i++)
    {
        int v=a[i];
        if(pos[v]==-1)
            continue;
        ll dif=(pos[v]-i+m)%m;
        if(ini[dif]==oo)
            continue;
        posi.push_back(pii(dif,i));
    }

    ll res=0;
    for(ll po=(1ll<<60);po;po>>=1)
        if(aux(res+po)<k)
            res+=po;
    res++;
    db(res)

    return 0;
}
/**
4 2 4
4 2 3 1
2 1
4 2 1
4 2 3 1
2 1
4 2 2
4 2 3 1
2 1
4 2 3
4 2 3 1
2 1
**/