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
typedef unsigned long long ull;
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
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(2e3+5)

point read()
{
    ll x,y;
    cin >> x >> y;
    return point(x,y);
}

point px[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    ld x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    point c1=point(x1,y1);
    point c2=point(x2,y2);
    for(int i=0;i<n;i++)
        px[i]=read();

    vector<pdi> ds1;
    for(int i=0;i<n;i++)
        ds1.push_back(pdi(abs(px[i]-c1),i));

    sort(all(ds1));
    vector<bool> mk(n);
    ld r2=0;
    for(int j=0;j<n;j++)
        if(!mk[j])
            r2=max(r2,abs(c2-px[j]));
    ld res=r2*r2;
    for(int i=0;i<n;i++)
    {
        ld r1=ds1[i].f;
        mk[ds1[i].s]=1;
        ld r2=0;
        for(int j=0;j<n;j++)
            if(!mk[j])
                r2=max(r2,abs(c2-px[j]));
        res=min(res,r1*r1+r2*r2);
    }

    res+=0.5;
    ll re=res;
    db(re)

    return 0;
}