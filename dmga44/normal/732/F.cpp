#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")

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
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

struct graph
{
	int n;
	vector<vector<int>> adj;

	graph(int n) : n(n), adj(n) {}
	graph() : n(0), adj(0) {}

	void add_edge(int src, int dst)
	{
		adj[src].push_back(dst);
		adj[dst].push_back(src);
	}
};

vector<vector<int>> comps;
vector<pii> bridges;

void bridge_components(const graph &g)
{
	vector<int> num(g.n), low(g.n), stk;

	function<void(int, int, int&)> dfs = [&](int u, int p, int &t)
	{
		num[u] = low[u] = ++t;
		stk.push_back(u);
		for (int v : g.adj[u])
		{
			if (v == p) continue;
			if (num[v] == 0)
			{
				dfs(v, u, t);
				low[u] = min(low[u], low[v]);
			}
			else low[u] = min(low[u], num[v]);
            if(low[v]>num[u])
                bridges.push_back(pii(u,v));
		}

		if (low[u] == num[u])
		{
			comps.push_back({});
			do
			{
				comps.back().push_back(stk.back());
				stk.pop_back();
			}
			while (comps.back().back() != u);
		}
	};

	for (int u = 0, t; u < g.n; ++u)
		if (num[u] == 0) dfs(u, -1, t = 0);
}

int c[MAXN];
vector<int> g[MAXN];
bool mk[MAXN];
int lvl[MAXN];

void dfs(int u)
{
    mk[u]=1;
    for(auto v : g[u])
    {
        if(mk[v])
            continue;
        lvl[v]=lvl[u]+1;
        dfs(v);
    }
}

set<pii> s;
graph gg;
int p[MAXN];

void dfs2(int u)
{
    mk[u]=1;
//    db("")
//    db(u)
    for(auto v : gg.adj[u])
    {
        if(c[v]!=c[u])
            continue;
        if(v==p[u] || s.count(pii(v,u)))
            continue;
        p[v]=u;
        s.insert(pii(u,v));
//        cout << u << ' ' << v << '\n';
        if(!mk[v])
            dfs2(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,u,v;
    cin >> n >> m;
    vector<pii> edges;
    gg = graph(n);
    for(int i=0;i<m;i++)
    {
        cin >> u >> v;
        u--,v--;
        edges.push_back(pii(u,v));
        gg.add_edge(u,v);
    }

    bridge_components(gg);

    int root=0;
    for(int i=0;i<comps.size();i++)
    {
        for(auto y : comps[i])
            c[y]=i;
        if(comps[i].size()>comps[root].size())
            root=i;
    }

    for(auto y : bridges)
    {
        int u=c[y.f];
        int v=c[y.s];
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(root);

    for(auto y : bridges)
    {
        int u=c[y.f];
        int v=c[y.s];
        if(lvl[u]>lvl[v])
            s.insert(pii(y.f,y.s));
        else
            s.insert(pii(y.s,y.f));
    }

    for(int i=0;i<comps.size();i++)
        mk[i]=0;

    for(int i=0;i<comps.size();i++)
    {
//        db("")
//        db(i)
//        db(comps[i].size())
//        for(auto v : comps[i])
//            cout << v << ' ';
//        cout << '\n';
        p[comps[i][0]]=-1;
        dfs2(comps[i][0]);
    }

    db(comps[root].size())
    for(auto e : edges)
    {
        if(s.count(e))
            cout << e.f+1 << ' ' << e.s+1 << '\n';
        else
            cout << e.s+1 << ' ' << e.f+1 << '\n';
    }

    return 0;
}
/**
7 9
4 3
2 6
7 1
4 1
7 3
3 5
7 4
6 5
2 5
**/