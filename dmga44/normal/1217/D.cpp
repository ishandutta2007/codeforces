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
#define mod (ll)(998244353)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

struct graph
{
	int n;
	vector<vector<int>> adj;

	graph(int n) : n(n), adj(n) {}

	void add_edge(int u, int v)
	{
		adj[u].push_back(v);
	}

	vector<int>& operator[](int u) { return adj[u]; }
};

vector<vector<int>> scc_gabow(graph &adj)
{
	int n = adj.n;

	vector<vector<int>> scc;
	vector<int> S, B, I(n);

	function<void(int)> dfs = [&](int u)
	{
		B.push_back(I[u] = S.size());
		S.push_back(u);

		for (int v : adj[u])
			if (!I[v]) dfs(v);
			else while (I[v] < B.back()) B.pop_back();

		if (I[u] == B.back())
		{
			scc.push_back({});
			for (B.pop_back(); I[u] < S.size(); S.pop_back())
			{
				scc.back().push_back(S.back());
				I[S.back()] = n + scc.size();
			}
		}
	};

	for (int u = 0; u < n; ++u)
		if (!I[u]) dfs(u);

	return scc; // in reverse topological order
}

int mk[MAXN];
int res[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,u,v;
    cin >> n >> m;
    vector<pii> edges;
    map<pii,int> mp;
    for(int i=0;i<m;i++)
    {
        cin >> u >> v;
        u--,v--;
        edges.push_back(pii(u,v));
        mp[pii(u,v)]=i;
    }

    int k=1;
    while(1)
    {
        graph g(n);
        for(int i=0;i<m;i++)
            if(!mk[i])
                g.add_edge(edges[i].f,edges[i].s);

        vector<vector<int> > comps=scc_gabow(g);
        int ok=-1;
        for(int i=0;i<comps.size();i++)
            if(comps[i].size()>1)
                ok=i;

        if(ok==-1)
            break;
        else
        {
            k=2;
            int u=comps[ok][0];
            for(auto v : g[u])
            {
                int id=mp[pii(u,v)];
                mk[id]=1;
                res[id]=1;
            }
            for(int i=0;i<n;i++)
            {
                if(i==u)
                    continue;
                for(auto v : g[i])
                {
                    if(v!=u)
                        continue;
                    int id=mp[pii(i,u)];
                    mk[id]=1;
                    res[id]=2;
                }
            }
        }
    }

    db(k)
    for(int i=0;i<m;i++)
    {
        if(!res[i])
            res[i]=1;
        cout << res[i] << ' ';
    }
    cout << '\n';

    return 0;
}