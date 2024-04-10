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
//#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    ll dx1,dy1;
    cin >> dx1 >> dy1;
    ll dx2,dy2;
    cin >> dx2 >> dy2;
    ll mod=dx1*dy2-dx2*dy1;
    mod=abs(mod);
    if(mod!=n)
    {
        db("NO")
    }
    else
    {
        db("YES")
        ll gx=__gcd(abs(dx1),abs(dx2));
        for(int i=0;i<gx;i++)
            for(int j=0;j<mod/gx;j++)
                cout << i << ' ' << j << '\n';
    }


//    map<pii,bool> mk;
//    for(int i=-100;i<100;i++)
//        for(int j=-100;j<100;j++)
//            mk[pii(i*dx1+j*dx2,i*dy1+j*dy2)]=1;
//
//    for(int i=0;i<40;i++,cout << '\n')
//        for(int j=0;j<40;j++)
//            cout << mk[pii(i,j)];

    return 0;
}