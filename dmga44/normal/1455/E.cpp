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
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

struct info{
    ll l,r;
    ll v;
};

info aux(pii v1,pii v2)
{
    ll v=abs(v1.f-v1.s);
    v+=abs(v2.f-v2.s);

    if(v1.f>v1.s)
        swap(v1.f,v1.s);
    if(v2.f>v2.s)
        swap(v2.f,v2.s);

    ll r=0,l=0;
    if(v2.f>v1.s)
        l=max(l,v2.f-v1.s);
    if(v1.f>v2.s)
        l=max(l,v1.f-v2.s);

    if(v2.s>v1.f)
        r=max(r,v2.s-v1.f);
    if(v1.f>v2.f)
        r=max(r,v1.s-v2.f);
    return {l,r,v};
}

ll solve(vector<point>& v)
{
    info x=aux(pii(v[0].real(),v[1].real()),pii(v[2].real(),v[3].real()));
    info y=aux(pii(v[0].imag(),v[2].imag()),pii(v[1].imag(),v[3].imag()));

    if((x.l<=y.r && x.r>=y.r) || (y.l<=x.r && y.r>=x.r))
        return x.v+y.v;
    if(x.l>y.r)
        return x.v+y.v+2*(x.l-y.r);
    return x.v+y.v+2*(y.l-x.r);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        vector<point> ps;
        vector<int> p;
        for(int i=0;i<4;i++)
        {
            int x,y;
            cin >> x >> y;
            ps.push_back(point(x,y));
            p.push_back(i);
        }

        ll ans=4e9;
        do{
            vector<point> np;
            for(int i=0;i<4;i++)
                np.push_back(ps[p[i]]);
            ans=min(ans,solve(np));
        }while(next_permutation(all(p)));

        db(ans)
    }

    return 0;
}