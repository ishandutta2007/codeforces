#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define dbg(x) cerr << #x ": " << (x)<< '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > adyList;

#define x first
#define y second
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define MAXN 1007

const int INF = int(1e9);
const ll INF64 = ll(1e18);
const int MOD = int(1e9) + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);
int n,m,s,t;
vector<pii> BB;
vector<pii> BBB;
pii nnot;
pii rnnot;
int cc,dd;
map<pii,int> f;
struct graph
{
	int n;
	vector<vector<int>> adj;

	graph(int n) : n(n), adj(n) {}
	graph() : n(0), adj(0) {}

	void add_edge(int u, int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int>& operator[](int u) { return adj[u]; }
};

vector<pair<int, int>> bridges;
vector<vector<int>> comps;
vector<vector<int>> bridge_blocks(graph &adj)
{
	int n = adj.n;

	vector<int> num(n), low(n), stk;

	function<void(int, int, int&)> dfs = [&](int u, int p, int &t)
	{
		num[u] = low[u] = ++t;
		stk.push_back(u);

		// remove if there isn't parallel edges
		sort(adj[u].begin(), adj[u].end());

		for (int i = 0, sz = adj[u].size(); i < sz; ++i)
		{
			int v = adj[u][i];
		    if(cc==1 && (v == nnot.y && u == nnot.x))
            {
                cc++;
                continue;
            }
            if(dd == 1 && (u == nnot.y && v == nnot.x))
            {
                dd++;
                continue;
            }
			if (v == p)
			{
				if (i + 1 < sz && adj[u][i + 1] == v)
					low[u] = min(low[u], num[v]);
				continue;
			}

			if (!num[v])
			{
				dfs(v, u, t);
				low[u] = min(low[u], low[v]);

				if (low[v] == num[v])
					bridges.push_back({u, v});
			}
			else low[u] = min(low[u], num[v]);
		}

		if (num[u] == low[u])
		{
			comps.push_back({});
			for (int v = -1; v != u; stk.pop_back())
				comps.back().push_back(v = stk.back());
		}
	};

	for (int u = 0, t; u < n; ++u)
		if (!num[u]) dfs(u, -1, t = 0);

	return comps;
}

function<graph()> build_tree = []()
{
    vector<int> id(n);

    for (int i = 0; i < (int) comps.size(); ++i)
        for (int u : comps[i]) id[u] = i;

    graph tree(comps.size());
    vi pa(comps.size()), markk(comps.size());
    map<pii,pii> prov;
    for (auto &e : bridges)
    {
        tree.add_edge(id[e.first], id[e.second]);
        prov[{id[e.x],id[e.y]}] = e;
        prov[{id[e.y],id[e.x]}] = e;
    }

    function<void(int)> dfs2 = [&](int u)
    {
        markk[u] = 1;
        for(auto v : tree[u])
        {
            if(markk[v])
                continue;
            pa[v] = u;
            dfs2(v);
        }
    };
    pa[id[s]] = -1;
    pa[id[t]] = -1;
    dfs2(id[s]);
    BBB.clear();
    if(pa[id[t]] != -1)
        for(int k = id[t];k!= id[s];k = pa[k])
            BBB.pb(prov[{k,pa[k]}]);

    return tree;
};
graph G;
bool mark[MAXN];
vi p;
vi proof;
void dfs(int u)
{
    mark[u] = 1;
    for(auto v : G[u])
    {
        if(mark[v])
            continue;
        p[v] = u;
        dfs(v);
    }
}
map<pii,ll> ma;
map<pii,int> mm;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>s>>t;
    s--;t--;
    p.assign(n,-1);
    G = graph(n);
    proof.pb(0);
    forn(i,m)
    {
        ll a,b,w;
        cin>>a>>b>>w;
        a--;b--;
        ma[{a,b}] += w;
        ma[{b,a}] += w;
        f[{a,b}]++;
        f[{b,a}]++;
        if(mm[{a,b}])
        {
            proof[mm[{a,b}]] = i+1;
        }
        else
        {
            mm[{a,b}] = i+1;
            mm[{b,a}] = i+1;}
            proof.push_back(0);
        
        G.add_edge(a,b);
    }

    ll res = INF64;
    nnot  = {-1,-1};
    pii ress = {-1,-1};
    int c = 0;

    p[t] = -1;
    dfs(s);
    bool ok = 1;
    if(p[t] != -1)
        for(int k = t;k!= s;k = p[k])
            BB.pb({k,p[k]});
    else
        ok = 0;

    bridge_blocks(G);
    build_tree();


    if(BBB.size() > 0)
    {
        for(auto x : BBB)
        {
            int k = ma[x];
            if(k<res)
            {
                c = 1;
                ress = {mm[x],-1};
                res = k;
            }
        }
    }
    forn(i,BB.size())
    {
        nnot = BB[i];
        cc = 1;
        dd = 1;

        bridges.clear();
        comps.clear();
        bridge_blocks(G);
        build_tree();
        for(auto x : BBB)
        {
            ll k = ma[nnot]+ma[x];
            if(mm[nnot] == mm[x])
                k/=2;
            if(k < res)
            {
                res = k;
                c = 2;
                ress = {mm[nnot],mm[x]};
                if(mm[nnot] == mm[x])
                {
                    ress = {mm[nnot],proof[mm[x]]};
                }
            }
        }
    }
    if(res == INF64)
    {
        if(ok)
            db(-1)
        else
        {
            db(0)
            db(0)
        }
    }
    else if(c == 1)
    {
        db(res)
        db(c)
        db(ress.x)
    }
    else
    {
        db(res)
        db(c)
        cout << ress.x << " " << ress.y << '\n';
    }

    return 0;
}