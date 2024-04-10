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
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define mod (ll)(998244353)
#define eps (1e-9)
#define oo (ll)(1e18)
#define pi acos(-1)
#define MAXN (ll)(5e3+5)

ll dp[MAXN][MAXN];

ll qp(ll b,ll e)
{
    if(!e)
        return 1;
    ll x=qp(b,e/2);
    x=(x*x)%mod;
    if(e&1)
        x=(x*b)%mod;
    return x;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,m,k;
    cin >> n >> m >> k;
    dp[0][0]=1;
    for(int i=0;i<k;i++)
        for(int j=0;j<=i;j++)
        {
            dp[i+1][j]=(dp[i+1][j]+dp[i][j]*j)%mod;
            dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j]*(n-j))%mod;
        }

    ll res=0;
    for(int i=1;i<=k;i++)
        res=(res+dp[k][i]*qp(m,(ll)(mod-2)*(ll)i))%mod;
    db(res)

    return 0;
}