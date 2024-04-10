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
const ll mod = (998244353);
const ld eps = (1e-9);
const ll oo = (ll)(1e18 + 5);
#define pi acos(-1)
#define MAXN (ll)(1e2 + 5)

int pas[MAXN][MAXN];

ll comb(ll n,ll m)
{
    return pas[n+1][m+1];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pas[0][0]=1;
    for(int i=1;i<MAXN;i++)
        for(int j=1;j<MAXN;j++)
            pas[i][j]=(pas[i-1][j]+pas[i-1][j-1])%mod;

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<ll> ans(2);
        for(int i=0;i<n;i++)
        {
            if(i%4==0 || i%4==3)
            {
                if(i%4==0)
                    ans[0]=(ans[0]+comb(n-i-1,(n-i-1)/2))%mod;
                else
                    ans[0]=(ans[0]+comb(n-i-1,(n-i-1)/2+1))%mod;
            }
            else
            {
                if(i%4==1)
                    ans[1]=(ans[1]+comb(n-i-1,(n-i-1)/2+1))%mod;
                else
                    ans[1]=(ans[1]+comb(n-i-1,(n-i-1)/2))%mod;
            }
        }
        cout << ans[0] << ' ' << ans[1] << ' ' << 1 << '\n';
    }

    return 0;
}