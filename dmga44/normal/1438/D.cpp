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
#define mod (ll)(998244353)
#define eps (1e-9)
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(1e2+5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    ll xorr=0;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        xorr^=x;
    }
    if(n&1)
    {
        db("YES")
        db(n/2+(n/2)-1)
        for(int i=0;i<(n/2);i++)
            cout << 2*i+1 << ' ' << 2*i+2 << ' ' << 2*i+3 << '\n';
        for(int i=(n/2)-2;i>=0;i--)
            cout << 2*i+1 << ' ' << 2*i+2 << ' ' << 2*i+3 << '\n';
    }
    else
    {
        if(xorr)
            db("NO")
        else
        {
            n--;
            db("YES")
            db(n/2+(n/2)-1)
            for(int i=0;i<(n/2);i++)
                cout << 2*i+1 << ' ' << 2*i+2 << ' ' << 2*i+3 << '\n';
            for(int i=(n/2)-2;i>=0;i--)
                cout << 2*i+1 << ' ' << 2*i+2 << ' ' << 2*i+3 << '\n';
        }
    }

    return 0;
}