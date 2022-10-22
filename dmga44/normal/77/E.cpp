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
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(35)

ld l,r1,r2;
point c1,c2;

point operator*(ld x,point p)
{
    return point(x*p.real(),x*p.imag());
}

void print(point p)
{
    cout << p.real() << ' ' << p.imag() << '\n';
}

void solve(ld k)
{
    ld cnt=1e4;
    point center=point(-l,0);
    point p1=c1-center;
    point p2=c2-center;
    point pp1=point(l,0)-center;
    point pp2=((r2/(r1+r2))*c1)+((r1/(r1+r2))*c2)-center;

    point ip1=(cnt/(abs(pp1)*abs(pp1)))*pp1;
    point ip2=(cnt/(abs(pp2)*abs(pp2)))*pp2;
    point add=point(0,1)*(ip1-ip2);
    ip1=ip1+k*add;
    ip2=ip2+(k-1)*add;
    point ip3=0.5*(ip1+ip2);
    ip2=ip2+add;

    ip1=(cnt/(abs(ip1)*abs(ip1)))*ip1;
    ip2=(cnt/(abs(ip2)*abs(ip2)))*ip2;
    ip3=(cnt/(abs(ip3)*abs(ip3)))*ip3;
    ld a=abs(ip1-ip2);
    ld b=abs(ip2-ip3);
    ld c=abs(ip3-ip1);
    ld sp=(a+b+c)/2;
    ip3=ip3+center;

    r2=(a*b*c)/(sqrt(sp*(sp-a)*(sp-b)*(sp-c))*4);
    c2=c1+((r1+r2)/(abs(ip3-c1)))*(ip3-c1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int k;
        cin >> l >> r1 >> k;
        r2=l-r1;
        c1=point(-l+r1,0);
        c2=point(l-r2,0);
        solve(k);

        prec(10);
        cout << r2 << '\n';
    }

    return 0;
}