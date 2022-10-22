#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native", "no-zero-upper") // Enable AVX

/// UH Top
#include <bits/stdc++.h>
#define db(x) cerr << #x << ':' << (x) << '\n';
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
// #define int ll
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
// typedef __int128_t int128;
typedef pair<ll, ll> pii;
typedef pair<ld, ll> pdi;
typedef pair<ld, ld> pdd;
typedef pair<ld, pdd> pdp;
typedef pair<string, ll> psi;
typedef pair<ll, string> pls;
typedef pair<string, string> pss;
typedef pair<ll, pii> pip;
typedef pair<pii, pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef vector<ll> vi;
typedef pair<point, int> ppi;
#define prec(n)        \
    cout.precision(n); \
    cout << fixed
const ll mod = (1e9 + 7);
const ld eps = (1e-8);
const ll oo = (ll)(1e18 + 5);
#define pi acos(-1)
#define MAXN (ll)(1e6 + 5)

ld ask(vector<point>& p)
{
    cout << "? " << p.size() << '\n';
    for(auto px : p)
        cout << px.real() << ' '<< px.imag() << '\n';
    cout.flush();
    ld ans;
    cin >> ans;
    return ans;
}

int32_t main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    prec(12);
    // cout << 1.0/18.0 << '\n';

    int n,m;
    cin >> n >> m;
    ld px,py;
    vector<point> tqx1;
    for(int i=0;i<(n+1)/2;i++)
    {
        tqx1.push_back(point(i*2,0));
        tqx1.push_back(point(i*2+1,0));
        tqx1.push_back(point(i*2+1,m));
        tqx1.push_back(point(i*2+2,m));
    }
    tqx1.push_back(tqx1.back()+point(0,1));
    tqx1.push_back(point(0,m+1));

    ld x=ask(tqx1);
    for(int i=0;i<tqx1.size();i++)
        tqx1[i]+=point(1.0-x,0);
    
    ld result_ok=ask(tqx1);
    if(abs(result_ok-1.0)<eps)
        px=1-x;
    else
        px=1+x;
    // cout << px << '\n';
    
    vector<point> tqy1;
    for(int i=0;i<(m+1)/2;i++)
    {
        tqy1.push_back(point(0,i*2));
        tqy1.push_back(point(0,i*2+1));
        tqy1.push_back(point(n,i*2+1));
        tqy1.push_back(point(n,i*2+2));
    }
    tqy1.push_back(tqy1.back()+point(1,0));
    tqy1.push_back(point(n+1,0));

    ld y=ask(tqy1);
    for(int i=0;i<tqy1.size();i++)
        tqy1[i]+=point(0,1.0-y);
    
    ld result_okk=ask(tqy1);
    if(abs(result_okk-1.0)<eps)
        py=1-y;
    else
        py=1+y;
    // cout << py << '\n';

    vector<point> last;
    point base=point(px,py);
    for(int i=0;i<n;i++)
    {
        last.push_back(point(i,0)+base);
        if(i)
            last.push_back(point(i+((ld)i)/((ld)(n)),0)+base);
        last.push_back(point(i+((ld)i+1)/((ld)(n)),m)+base);
        if(i!=n-1)
            last.push_back(point(i+1,m)+base);
    }
    last.push_back(last.back()+point(0,1));
    last.push_back(point(0,m+1));

    ld ar=ask(last);

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            ld must_be=((ld)i)/((ld)n)+1.0/(2.0*n*m);
            must_be+=((ld)j)/((ld)(n*m));
            if(abs(ar-must_be)<eps)
            {
                point ans=point(i,j)+base;
                cout << "! "<< ans.real() << ' ' << ans.imag() << '\n';
                cout.flush();
                return 0;
            }
        }

    return 0;
}