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
typedef double ld;
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
const ll mod=(ll)(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(1<<18)

ll dp[MAXN][18];
ll add[18][18];
ll v[18];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,k;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++)
        cin >> v[i];
    for(int i=0;i<k;i++)
    {
        ll u,v,w;
        cin >> u >> v >> w;
        u--,v--;
        add[u][v]=w;
    }

    for(int i=0;i<n;i++)
        dp[1<<i][i]=v[i];

    for(int i=1;i<(1<<n);i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i&(1<<j))
                continue;
            for(int k=0;k<n;k++)
            {
                if(!(i&(1<<k)))
                    continue;
                dp[i|(1<<j)][j]=max(dp[i|(1<<j)][j],dp[i][k]+add[k][j]+v[j]);
            }
        }
    }

    ll res=0;
    for(int i=0;i<(1<<n);i++)
        if(__builtin_popcount(i)==m)
            for(int j=0;j<n;j++)
                res=max(res,dp[i][j]);
    db(res)

    return 0;
}