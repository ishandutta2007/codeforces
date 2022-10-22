#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
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
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(1e18)
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int xa,ya,za;
        cin >> xa >> ya >> za;
        int xb,yb,zb;
        cin >> xb >> yb >> zb;

        ll res=0;
        int x=min(zb,xa);
        zb-=x;
        xa-=x;
        x=min(za,yb);
        res+=x*2;
        yb-=x;
        za-=x;

        x=min(za,zb);
        zb-=x;
        za-=x;
        x=min(ya,yb);
        yb-=x;
        ya-=x;
        x=min(xa,xb);
        xb-=x;
        xa-=x;
        x=min(xa,yb);
        yb-=x;
        xa-=x;
        x=min(ya,xb);
        xb-=x;
        ya-=x;
        x=min(ya,zb);
        res-=2*x;
        db(res)
    }

    return 0;
}