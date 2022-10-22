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
const ll mod=(ll)(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(3e5+5)

vector<int> g[MAXN];
ll level[MAXN];
ll ts[MAXN];
ll dp[MAXN];
bool mk[MAXN];

void dfs(int u)
{
    mk[u]=1;
    vector<pii> sons;
    for(auto v : g[u])
        if(!mk[v])
        {
            level[v]=level[u]+1;
            dfs(v);
            sons.push_back(pii(ts[v],dp[v]));
        }

    if(sons.empty())
    {
        ts[u]=level[u];
        dp[u]=0;
        return ;
    }

    sort(allr(sons));
    if(!u)
        reverse(all(sons));

    for(int i=0;i<sons.size();i++)
    {
        dp[u]=max(dp[u],sons[i].s);
        ts[u]=sons[i].f;
        if(i+1<sons.size())
            dp[u]=max(dp[u],ts[u]-level[u]+1);
    }
    if(!u)
        dp[u]=max(dp[u],ts[u]);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            cin >> u >> v;
            u--,v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(0);
        db(dp[0])

        for(int i=0;i<n;i++)
        {
            g[i].clear();
            mk[i]=0;
            dp[i]=0;
            ts[i]=0;
            level[i]=0;
        }
    }

    return 0;
}