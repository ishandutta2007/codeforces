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
const ld eps=(1e-8);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(3e5+5)

int d[MAXN];
vector<int> g[MAXN];
int level[MAXN];
bool mk[MAXN];

int find(int u)
{
    if(d[u]<0)
        return u;
    d[u]=find(d[u]);
    return d[u];
}

bool join(int u,int v)
{
    u=find(u);
    v=find(v);
    if(u==v)
        return 0;
    if(d[u]>d[v])
        swap(d[u],d[v]);
    d[u]+=d[v];
    d[v]=u;
    return 1;
}

void dfs(int u)
{
    mk[u]=1;
    bool ok=1;
    for(auto v : g[u])
        if(mk[v] && level[v])
            ok=0;
    level[u]=ok;
    for(auto v : g[u])
        if(!mk[v])
            dfs(v);

}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        for(int i=0;i<n;i++)
        {
            d[i]=-1;
            mk[i]=0;
            level[i]=0;
            g[i].clear();
        }
        int comps=n;

        for(int i=0;i<m;i++)
        {
            int u,v;
            cin >> u >> v;
            u--,v--;
            if(join(u,v))
                comps--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        if(comps!=1)
        {
            db("NO")
            continue;
        }
        dfs(0);

        vector<int> res;
        for(int i=0;i<n;i++)
            if(level[i])
                res.push_back(i);
        db("YES")
        db(res.size())
        for(auto y : res)
            cout << y+1 << ' ';
        cout << '\n';
    }

    return 0;
}