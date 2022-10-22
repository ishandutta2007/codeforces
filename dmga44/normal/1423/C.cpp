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
typedef pair<ld,pii> pdp;
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
#define MAXN (ll)(3e5+5)


vector<int> g[MAXN],nodes;
bool mk1[MAXN],mk2[MAXN];
int sons[MAXN][2];
vector<pii> res;

void dfs1(int u)
{
    mk1[u]=1;
    sons[u][0]=1;
    nodes.push_back(u);
    for(auto v : g[u])
        if(!mk1[v] && !mk2[v])
        {
            dfs1(v);
            sons[u][0]+=sons[v][0];
            sons[u][1]=max(sons[v][0],sons[u][1]);
        }
}

void dfs2(int u)
{
    mk1[u]=1;
    ///usually you start coding over here
    nodes.push_back(u);
    for(auto v : g[u])
        if(!mk1[v] && !mk2[v])
            dfs2(v);
}

void solve(int u)
{
    dfs1(u);

    ///tamanho 2
    if(nodes.size()<=2)
    {
        for(auto v : nodes)
        {
            sons[v][0]=sons[v][1]=0;
            mk2[v]=1;
        }
        nodes.clear();
        return ;
    }

    int cent1=-1,cant=nodes.size()/3;
    for(auto v: nodes)
    {
        if(cent1==-1 && sons[v][0]>=cant && sons[v][1]<=cant)
            cent1=v;
        mk1[v]=sons[v][0]=sons[v][1]=0;
    }
    nodes.clear();

    mk2[cent1]=1;
    ///el tipo
    if(cent1==u)
    {
        ///usually you start coding over here
        for(auto v : g[cent1])
        {
            if(mk2[v])
                continue;
            ///usually you start coding over here
            dfs2(v);

            for(auto y : nodes)
            {
                res.push_back(pii(y,cent1));
                mk1[y]=0;
            }
            nodes.clear();
        }

        for(auto v : g[cent1])
            if(!mk2[v])
                solve(v);

        return ;
    }

    dfs1(u);

    int cent2=-1;
    cant=nodes.size()/2;
    for(auto v: nodes)
    {
        if(cent2==-1 && sons[v][0]>=cant && sons[v][1]<=cant)
            cent2=v;
        mk1[v]=sons[v][0]=sons[v][1]=0;
    }
    nodes.clear();

    mk2[cent2]=1;
    for(auto v : g[cent1])
    {
        if(mk2[v])
            continue;
        ///usually you start coding over here
        dfs2(v);

        for(auto y : nodes)
        {
            res.push_back(pii(y,cent1));
            mk1[y]=0;
        }
        nodes.clear();
    }

    for(auto v : g[cent2])
    {
        if(mk2[v])
            continue;
        ///usually you start coding over here
        dfs2(v);

        for(auto y : nodes)
        {
            res.push_back(pii(y,cent2));
            mk1[y]=0;
        }
        nodes.clear();
    }

    res.push_back(pii(cent1,cent2));
    for(auto v : g[cent1])
        if(!mk2[v])
            solve(v);
    for(auto v : g[cent2])
        if(!mk2[v])
            solve(v);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin >> n >> k;
    map<pii,bool> there;
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
        there[pii(u,v)]=there[pii(v,u)]=1;
    }

    solve(0);

    vector<pii> tr;
    for(auto y : res)
    {
        if(there[y])
            continue;
        tr.push_back(y);
    }

    db(tr.size())
    for(auto y : tr)
        cout << y.f+1 << ' ' << y.s+1 << '\n';

    return 0;
}