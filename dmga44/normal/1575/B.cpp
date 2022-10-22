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
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(1e6+5)

point operator*(point p,ld x)
{
    return point(p.real()*x,p.imag()*x);
}

point operator/(point p,ld x)
{
    return p*(1/x);
}

int aux(vector<point>& ps,ld x)
{
    vector<pdi> ts;
    for(auto p : ps)
    {
        ld v=abs(p);
        if(v<x+eps)
            continue;
        ld ang1;
        if(p.imag()>=0)
            ang1=acos(p.real()/v);
        else
            ang1=2*pi-acos(p.real()/v);
        ld ang2=acos(x/v);
        if(ang1-ang2<0)
            ang1+=2*pi;
        ts.push_back(pdi(ang1-ang2,1));
        ts.push_back(pdi(ang1+ang2,-1));
        ts.push_back(pdi(2*pi+ang1-ang2,1));
        ts.push_back(pdi(2*pi+ang1+ang2,-1));
    }

    sort(all(ts));

    int res=0;
    int act=0;
    for(auto y : ts)
    {
        act+=y.s;
        res=max(act,res);
    }

//    cout << res << ' ' << x << '\n';
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin >> n >> k;
    vector<point> ps;
    ///inversa con const=2e9
    ld c=2e9;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        if(x==0 && y==0)
        {
            k--;
            continue;
        }
        ps.push_back(point(x,y));
        ld d=abs(ps.back());
        point nor=ps.back()/d;
        point np=nor*(c/d);
        ps.back()=np;
    }

    ld l=0,r=1e6;
    while(r-l>1e-9)
    {
        ld m=(l+r)/2;
        if(aux(ps,c/m)<k)
            l=m;
        else
            r=m;
    }

    prec(10);
    db(l/2)

    return 0;
}