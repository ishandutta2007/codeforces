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
#define eps (1e-6)
#define oo (ll)(1e18)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    if(n==1 || m==1)
    {
        if(n==1 && m==1)
            db(0)
        else if(n==1)
        {
            for(int i=2;i<=m+1;i++)
                cout << i << ' ';
            cout << '\n';
        }
        else
        {
            for(int i=2;i<=n+1;i++)
                db(i)
        }
    }
    else
    {
        for(int i=2;i<=m+1;i++)
            cout << i << ' ';
        cout << '\n';
        for(int j=m+2;j<=m+n;j++)
        {
            for(int i=2;i<=m+1;i++)
                cout << i*j << ' ';
            cout << '\n';
        }
    }

    return 0;
}