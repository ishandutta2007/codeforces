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
typedef double ld;
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
const ll mod=(ll)(998244353);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(1e4+5)

void print(vector<pii> p)
{
    db(p.size())
    for(auto x : p)
        cout << x.f << ' ' << x.s << '\n';
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pii a,b,c;
    cin >> a.f >> a.s;
    cin >> b.f >> b.s;
    cin >> c.f >> c.s;

    vector<pii> x1;
    x1.push_back(a);
    x1.push_back(b);
    x1.push_back(c);
    a.s*=-1;
    b.s*=-1;
    c.s*=-1;
    vector<pii> x2;
    x2.push_back(a);
    x2.push_back(b);
    x2.push_back(c);
    a.s*=-1;
    b.s*=-1;
    c.s*=-1;

    sort(all(x1));
    sort(all(x2));

    bool ok=1;
    for(int i=0;i<2;i++)
        if(x1[i].s>x1[i+1].s)
            ok=0;
    vector<pii> res;
    if(ok)
    {
        for(int i=x1[0].f;i<=x1[2].f;i++)
            res.push_back(pii(i,x1[1].s));
        for(int i=x1[0].s;i<x1[1].s;i++)
            res.push_back(pii(x1[0].f,i));
        for(int i=x1[1].s+1;i<=x1[2].s;i++)
            res.push_back(pii(x1[2].f,i));
        print(res);
    }
    ok=1;
    for(int i=0;i<2;i++)
        if(x2[i].s>x2[i+1].s)
            ok=0;
    if(ok)
    {
        for(auto &p : x2)
            p.s*=-1;
        x1=x2;
        for(int i=x1[0].f;i<=x1[2].f;i++)
            res.push_back(pii(i,x1[1].s));
        for(int i=x1[2].s;i<x1[1].s;i++)
            res.push_back(pii(x1[2].f,i));
        for(int i=x1[1].s+1;i<=x1[0].s;i++)
            res.push_back(pii(x1[0].f,i));
        print(res);
    }

    vector<int> xs;
    vector<int> ys;
    xs.push_back(a.f);
    xs.push_back(b.f);
    xs.push_back(c.f);
    ys.push_back(a.s);
    ys.push_back(b.s);
    ys.push_back(c.s);

    sort(all(xs));
    sort(all(ys));
//    db("xxx")
    for(int i=xs[0];i<=xs[2];i++)
        res.push_back(pii(i,ys[1]));
    if(x1[0]==pii(xs[0],ys[0]))
    {
        for(int i=ys[0];i<ys[1];i++)
            res.push_back(pii(xs[0],i));
        for(int i=ys[1]+1;i<=ys[2];i++)
            res.push_back(pii(xs[1],i));
    }
    else if(x1[0]==pii(xs[0],ys[2]))
    {
        for(int i=ys[0];i<ys[1];i++)
            res.push_back(pii(xs[1],i));
        for(int i=ys[1]+1;i<=ys[2];i++)
            res.push_back(pii(xs[0],i));
    }
    else
    {
        if(x1[1]==pii(xs[1],ys[2]))
        {
            for(int i=ys[0];i<ys[1];i++)
                res.push_back(pii(xs[2],i));
            for(int i=ys[1]+1;i<=ys[2];i++)
                res.push_back(pii(xs[1],i));
        }
        else
        {
            for(int i=ys[0];i<ys[1];i++)
                res.push_back(pii(xs[1],i));
            for(int i=ys[1]+1;i<=ys[2];i++)
                res.push_back(pii(xs[2],i));
        }
    }
    print(res);

    return 0;
}