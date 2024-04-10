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
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

vector<int> g[MAXN];
int d[MAXN];
bool mk[MAXN];

int find(int u)
{
    if(d[u]<0)
        return u;
    d[u]=find(d[u]);
    return d[u];
}

void join(int u,int v)
{
    int uu=u;
    int vv=v;
    u=find(u);
    v=find(v);
    if(u==v)
        return ;
    g[uu].push_back(vv);
    g[vv].push_back(uu);
    if(d[u]>d[v])
        swap(u,v);
    d[u]+=d[v];
    d[v]=u;
}

void dfs(int u,vector<int>& p)
{
    mk[u]=1;
    p.push_back(u);
    for(auto v : g[u])
        if(!mk[v])
            dfs(v,p);
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
        for(int i=0;i<n;i++)
        {
            mk[i]=0;
            d[i]=-1;
            g[i].clear();
        }
        vector<set<int> > appears(n);
        vector<vector<int> > inis;
        vector<int> q;
        vector<int> p;
        queue<int> qq;
        for(int i=0;i<n-2;i++)
        {
            int a,b,c;
            cin >> a >> b >> c;
            a--,b--,c--;
            appears[a].insert(i);
            appears[b].insert(i);
            appears[c].insert(i);
            inis.push_back({a,b,c});
        }

        for(int i=0;i<n;i++)
            if(appears[i].size()==1)
                qq.push(i);

        while(!qq.empty())
        {
            int u=qq.front();
            qq.pop();
            if(appears[u].empty())
                continue;

            int t=(*appears[u].begin());
            q.push_back(t);
            for(auto v : inis[t])
            {
                if(v!=u)
                    join(u,v);
                appears[v].erase(t);
                if(appears[v].size()==1)
                    qq.push(v);
            }
        }

        vector<int> vs;
        for(int i=0;i<n;i++)
            if(g[i].size()==1)
                vs.push_back(i);
        if(vs.size())
        {
            g[vs[0]].push_back(vs[1]);
            g[vs[1]].push_back(vs[0]);
        }

        dfs(0,p);

        for(int i=0;i<n;i++)
            cout << p[i]+1 << ' ';
        cout << '\n';
        for(int i=0;i<n-2;i++)
            cout << q[i]+1 << ' ';
        cout << '\n';
    }

    return 0;
}