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
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

mt19937 rng(time(0));

int f[MAXN];

int ask(int u,int v,int w)
{
//    if(u<1 || u>7 || v<1 || v>7 || w<1 || w>7)
//        while(1);
    cout << "? " << u << ' ' << v << ' ' << w << '\n';
    cout.flush();
    int x;
    cin >> x;
    return x;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int h;
    cin >> h;
    int n=(1<<h)-1;
    int tot=n+420;
    for(int i=3;i<=423;i++)
    {
        int u=rng();
        u=abs(u);
        u%=n;
        u++;
        int v=u;
        int w=v;
        while(v==u)
        {
            v=rng();
            v=abs(v);
            v%=n;
            v++;
        }
        while(w==u || w==v)
        {
            w=rng();
            w=abs(w);
            w%=n;
            w++;
        }
        f[ask(u,w,v)]++;
    }

    vector<pii> vp;

    for(int i=1;i<=n;i++)
        vp.push_back(pii(f[i],i));
    sort(allr(vp));
    int v1=vp[0].s;
    int v2=vp[1].s;
    int res=0;
    for(int i=1;i<=n;i++)
    {
        if(i==v1 || i==v2)
            continue;
        int x=ask(v1,v2,i);
        if(x==i)
            res=i;
    }
    cout << "! " << res << '\n';
    cout.flush();

    return 0;
}