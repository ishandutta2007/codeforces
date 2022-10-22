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
#define MAXN (ll)(2e5 + 5)

int dp[MAXN];
int last[MAXN];
int act[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin >> n >> k;
    dp[0]++;
    last[0]++;
    int sum=0;
    for(int i=k;1;i++)
    {
        if(sum>n)
            break;
        vector<int> ac(i);
        for(int j=0;j<=n;j++)
        {
            int m=j%i;
            act[j]=ac[m];
            ac[m]=(last[j]+ac[m]);
            if(ac[m]>=mod)
                ac[m]-=mod;
        }
        for(int j=0;j<=n;j++)
        {
            dp[j]=dp[j]+act[j];
            if(dp[j]>=mod)
                dp[j]-=mod;
            last[j]=act[j];
            act[j]=0;
        }
        sum+=i;
    }

    for(int i=1;i<=n;i++)
        cout << dp[i] << ' ';
    cout << '\n';

    return 0;
}