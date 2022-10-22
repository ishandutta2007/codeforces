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
#define MAXN (ll)(5e3+5)

ll dp[MAXN][MAXN];
ll ad[MAXN][MAXN];
ll ini[MAXN],men[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];

    sort(all(a));

    int pos=0;
    for(int i=0;i<n;i++)
    {
        while(pos<n && a[i]*2>a[pos])
        {
            men[pos]=i;
            pos++;
        }
        ini[i]=pos;
    }

    for(int i=0;i<n;i++)
        dp[0][i]=1;
    for(ll i=0;i<n;i++)
    {
//        for(int j=0;j<n;j++)
//            cout << dp[i][j] << ' ';
//        cout << '\n';
        for(ll j=0;j<n;j++)
        {
            dp[i+1][j]=(dp[i][j]*(men[j]-i))%mod;
            ad[i+1][ini[j]]=(ad[i+1][ini[j]]+dp[i][j])%mod;
        }
        for(int j=1;j<n;j++)
        {
            ad[i+1][j]=(ad[i+1][j]+ad[i+1][j-1])%mod;
            dp[i+1][j]=(dp[i+1][j]+ad[i+1][j])%mod;
        }
    }

    db(dp[n-1][n-1])

    return 0;
}