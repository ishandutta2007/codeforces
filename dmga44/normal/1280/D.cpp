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
#define eps (1e-9)
#define oo (ll)(1e18)
#define pi acos(-1)
#define MAXN (ll)(3e3+5)

ll w[MAXN];
int sz[MAXN];
vector<int> g[MAXN];
bool mk[MAXN];
int dp0[MAXN][MAXN];
int dp1[MAXN][MAXN];
ll dp2[MAXN][MAXN];
int n;

void dfs(ll u)
{
    mk[u]=1;
    for(ll i=0;i<=n;i++)
    {
        dp0[u][i]=dp1[u][i]=-1e9;
        dp2[u][i]=-oo;
    }
    dp1[u][0]=0;
    dp2[u][0]=w[u];
    sz[u]=1;
    for(auto v : g[u])
    {
        if(mk[v])
            continue;
        dfs(v);
        ll v1,v2,p1,p2;
        int mm;
        int  i,j;
        for(i=sz[u]-1+sz[v];i>=0;i--)
        {
            p1=-oo;
            p2=-oo;
            mm=min(sz[v],i);
            for(j=max(0,i-sz[u]+1);j<=mm;j++)
            {
                v1=dp1[u][i-j]+dp1[v][j];
                if(v1>=p1)
                {
                    v2=dp2[u][i-j]+dp2[v][j];
                    if(v1>p1 || v2>p2)
                    {
                        p1=v1;
                        p2=v2;
                    }
                }

                v1=dp1[u][i-j]+dp0[v][j];
                if(v1>=p1)
                {
                    v2=dp2[u][i-j];
                    if(v1>p1 || v2>p2)
                    {
                        p1=v1;
                        p2=v2;
                    }
                }
            }
            dp1[u][i]=p1;
            dp2[u][i]=p2;
        }

        sz[u]+=sz[v];
    }

    for(ll i=1;i<=sz[u];i++)
        dp0[u][i]=dp1[u][i-1]+(dp2[u][i-1]>0);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        ll m;
        cin >> n >> m;
        for(ll i=0;i<n;i++)
            cin >> w[i];
        for(ll i=0;i<n;i++)
        {
            ll x;
            cin >> x;
            w[i]=x-w[i];
        }

        for(ll i=0;i<n-1;i++)
        {
            ll u,v;
            cin >> u >> v;
            u--,v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(0);

//        for(int i=0;i<n;i++)
//        {
//            db("")
//            db(i)
//            for(int j=0;j<=m;j++)
//                cout << dp[i][j][0] << ' ';
//            cout << '\n';
//        }

        db(dp0[0][m])

        for(ll i=0;i<n;i++)
        {
            sz[i]=0;
            mk[i]=0;
            w[i]=0;
            g[i].clear();
        }
    }

    return 0;
}
/**
2
4 3
10 160 70 50
70 111 111 0
1 2
2 3
3 4
2 1
143 420
214 349
2 1
**/