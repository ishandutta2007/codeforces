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
const ll mod=(ll)(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        bool ok=1;
        int n,k;
        cin >> n >> k;
        vector<int> h(n);
        for(int i=0;i<n;i++)
            cin >> h[i];
        int l=h[0];
        int r=h[0];
        for(int i=1;i<n;i++)
        {
            int l1=l;
            int l2=r+k;
            int x1=h[i];
            int x2=h[i]+k-1+k;
            if(l1>=x2 || x1>=l2)
            {
                ok=0;
                continue;
            }
            ///l
            l=max(h[i],l-k+1);
            ///r
            r=min(h[i]+k-1,r+k-1);
        }
        ok&=(l==h[n-1]);
        if(ok)
            db("YES")
        else
            db("NO")
    }

    return 0;
}