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
const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(1e3+5)

vector<int> g[MAXN];
bool mk[MAXN];
int sons[MAXN][2],n;
vector<int> nodes;
int level[MAXN];
int ty[MAXN];
int parent[MAXN];
int dp[MAXN][MAXN];
int d[MAXN];

void dfs1(int u)
{
    mk[u]=1;
    nodes.push_back(u);
    sons[u][0]=1;
    for(auto v : g[u])
        if(!mk[v])
        {
            dfs1(v);
            sons[u][0]+=sons[v][0];
            sons[u][1]=max(sons[u][1],sons[v][0]);
        }
}

void dfs2(int u,int p)
{
    mk[u]=1;
    parent[u]=p;
    level[u]=level[p]+1;
    nodes.push_back(u);
    for(auto v : g[u])
        if(!mk[v])
            dfs2(v,u);
}

vector<pip> res;

void solve()
{
    dfs1(0);
    int cant=n/2;
    int cent=-1;
    for(auto v : nodes)
    {
        if(cent==-1 && sons[v][0]>=cant && sons[v][1]<=cant)
            cent=v;
        mk[v]=0;
    }
    nodes.clear();

    mk[cent]=1;
//    db(cent+1)
//    cout << sons[cent][0] << ' ' << sons[cent][1] << ' ' << cant << '\n';
    vector<pii> sz;
    map<int,vector<int> > mn;
    for(auto v : g[cent])
    {
        dfs2(v,cent);

        sz.push_back(pii(v,nodes.size()));
        mn[v]=nodes;
        nodes.clear();
    }

    dp[0][0]=1;
    for(int i=0;i<sz.size();i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(!dp[i][j])
                continue;
            if(!dp[i+1][j])
                dp[i+1][j]=dp[i][j];
            dp[i+1][j+sz[i].s]=i+1;
        }
    }

    vector<int> s1s;
    int m1=0;
    for(int i=0;i*2<=n;i++)
        if(dp[sz.size()][i])
            m1=i;
    int ini=m1;
    int p=sz.size();
    while(m1!=0)
    {
        int v=dp[p][m1];
        s1s.push_back(sz[v-1].f);
        m1-=sz[v-1].s;
        p=v-1;
    }

    for(auto y : s1s)
        for(auto v : mn[y])
            ty[v]=1;

    vector<pii> m1s;
    vector<pii> m2s;
    for(int i=0;i<n;i++)
        if(i!=cent)
        {
            if(ty[i])
                m1s.push_back(pii(level[i],i));
            else
                m2s.push_back(pii(level[i],i));
        }

    sort(all(m1s));
    sort(all(m2s));

    for(int i=0;i<m1s.size();i++)
    {
        int u=m1s[i].s;
        d[u]=i+1;
//        cout << "1 " << u+1 << '\n';
        res.push_back(pip(d[u]-d[parent[u]],pii(u,parent[u])));
    }

    for(int i=0;i<m2s.size();i++)
    {
        int u=m2s[i].s;
        d[u]=(i+1)*(ini+1);
//        cout << "2 " << u+1 << '\n';
        res.push_back(pip(d[u]-d[parent[u]],pii(u,parent[u])));
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    vector<pii> edges;
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        edges.push_back(pii(u,v));
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if(n<=4)
    {
        int cont=1;
        for(auto &y : edges)
            cout << y.f+1 << ' ' << y.s+1 << ' ' << cont++ << '\n';
        return 0;
    }

    solve();

    for(auto y : res)
        cout << y.s.f+1 << ' ' << y.s.s+1 << ' ' << y.f << '\n';

    return 0;
}