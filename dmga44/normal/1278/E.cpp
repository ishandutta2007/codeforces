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
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(1e18)
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

vector<int> g[MAXN];
bool mk[MAXN];
int sz[MAXN];
int dd[MAXN];
int res[MAXN][2];

void dfs1(int u)
{
    mk[u]=1;
    sz[u]=1;
    for(auto v : g[u])
        if(!mk[v])
        {
            dfs1(v);
            sz[u]+=sz[v];
            dd[u]++;
        }
}

void dfs2(int u,int l)
{
    mk[u]=1;
    res[u][1]=l+dd[u];
//    db("")
//    cout << u << ' ' << l << '\n';
    int ac=0;
    int cont=0;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(mk[v])
            continue;
        cont++;
        res[v][0]=res[u][1]-cont;
        dfs2(v,res[u][1]+ac+1);
        ac+=2*sz[v]-1;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

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

    dfs1(0);

    for(int i=0;i<n;i++)
        mk[i]=0;
    res[0][0]=1;
    dfs2(0,2);

    for(int i=0;i<n;i++)
        cout << res[i][0] << ' ' << res[i][1] << '\n';

    return 0;
}