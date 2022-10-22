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
typedef pair<int,int> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<int,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(2e2+5)

int dp[MAXN][MAXN][MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    string t;
    cin >> t;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=k;j++)
            for(int u=0;u<=n;u++)
                dp[i][j][u]=-oo;
    dp[0][0][0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            for(int u=0;u<=n;u++)
            {
                if(dp[i][j][u]==-oo)
                    continue;
                ///igual
                int pu=u+(s[i]==t[0]);
                if(s[i]==t[1])
                    dp[i+1][j][pu]=max(dp[i+1][j][pu],dp[i][j][u]+u);
                else
                    dp[i+1][j][pu]=max(dp[i+1][j][pu],dp[i][j][u]);
                ///cambio
                if(j==k)
                    continue;
                if(t[0]==t[1])
                    dp[i+1][j+1][u+1]=max(dp[i+1][j+1][u+1],dp[i][j][u]+u);
                else
                {
                    dp[i+1][j+1][u+1]=max(dp[i+1][j+1][u+1],dp[i][j][u]);
                    dp[i+1][j+1][u]=max(dp[i+1][j+1][u],dp[i][j][u]+u);
                }
            }
        }
    }

    int res=0;
    for(int i=0;i<=k;i++)
        for(int u=0;u<=n;u++)
            res=max(res,dp[n][i][u]);
    db(res)

    return 0;
}