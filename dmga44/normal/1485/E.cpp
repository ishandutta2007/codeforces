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
#define MAXN (ll)(2e5+5)

vector<int> g[MAXN];
vector<int> sons[MAXN];
ll a[MAXN];
ll dp[MAXN];
ll lvl[MAXN];
vector<int> level[MAXN];
bool mk[MAXN];

void dfs(int u)
{
    mk[u]=1;
    level[lvl[u]].push_back(u);
    for(auto v : g[u])
        if(!mk[v])
        {
            lvl[v]=lvl[u]+1;
            sons[u].push_back(v);
            dfs(v);
        }
}

void solve()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        mk[i]=0;
        a[i]=0;
        dp[i]=0;
        lvl[i]=0;
        g[i].clear();
        level[i].clear();
        sons[i].clear();
    }
    for(int i=0;i<n-1;i++)
    {
        int x;
        cin >> x;
        x--;
        g[i+1].push_back(x);
        g[x].push_back(i+1);
    }

    for(int i=1;i<n;i++)
        cin >> a[i];

    dfs(0);

    ll d=0;
    for(int i=0;i<n;i++)
        d=max(d,lvl[i]);

    for(int l=d-1;l>=0;l--)
    {
        ll aux1=-1e18;
        ll aux2=-1e18;
        ll me=1e18;
        ll ma=-1e18;
        for(auto v : level[l+1])
        {
            me=min(me,a[v]);
            ma=max(ma,a[v]);
            aux1=max(aux1,dp[v]+a[v]);
            aux2=max(aux2,dp[v]-a[v]);
        }
        for(auto u : level[l])
        {
            for(auto v : sons[u])
            {
                dp[u]=max(dp[u],dp[v]+(ma-a[v]));
                dp[u]=max(dp[u],dp[v]+(a[v]-me));
                dp[u]=max(dp[u],aux1-a[v]);
                dp[u]=max(dp[u],aux2+a[v]);
            }
        }
    }
//    for(int i=0;i<=d;i++)
//    {
//        db("")
//        db(i)
//        for(auto u : level[i])
//            cout << u  << ":" << dp[u] << ' ';
//        cout << '\n';
//    }

    db(dp[0])
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
/**
1
14
1 1 1 2 3 4 4 5 5 6 7 8 8
2 3 7 7 6 9 5 9 7 3 6 6 5

**/