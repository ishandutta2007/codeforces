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
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define mod (ll)(998244353)
#define eps (1e-9)
//#define oo (ll)(0x3f3f3f3f3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(5e2+5)

vector<int> g1[MAXN];
vector<int> g2[MAXN];
int c1[MAXN],c2[MAXN],a[MAXN];
vector<int> nodes1[MAXN];
vector<int> nodes2[MAXN];

template<typename flow_type, typename cost_type>
struct min_cost_max_flow
{
	struct edge
	{
		size_t src, dst, rev;
		flow_type flow, cap;
		cost_type cost;
	};

	int n;
	vector<vector<edge>> adj;

	min_cost_max_flow(int n) : n(n), adj(n), potential(n), dist(n), back(n) {}

	void add_edge(size_t src, size_t dst, flow_type cap, cost_type cost)
	{
		adj[src].push_back({src, dst, adj[dst].size(), 0, cap, cost});
		if (src == dst)
			adj[src].back().rev++;
		adj[dst].push_back({dst, src, adj[src].size() - 1, 0, 0, -cost});
	}

	vector<cost_type> potential;

	inline cost_type rcost(const edge &e)
	{
		return e.cost + potential[e.src] - potential[e.dst];
	}

	void bellman_ford(int source)
	{
		for (int k = 0; k < n; ++k)
			for (int u = 0; u < n; ++u)
				for (edge &e : adj[u])
					if (e.cap > 0 && rcost(e) < 0)
						potential[e.dst] += rcost(e);
	}

	const cost_type oo = numeric_limits<cost_type>::max();

	vector<cost_type> dist;
	vector<edge*> back;

	cost_type dijkstra(int source, int sink)
	{
		fill(dist.begin(), dist.end(), oo);

		typedef pair<cost_type, int> node;
		priority_queue<node, vector<node>, greater<node>> pq;

		for (pq.push({dist[source] = 0, source}); !pq.empty();)
		{
			node p = pq.top(); pq.pop();

			if (dist[p.second] < p.first) continue;
			if (p.second == sink) break;

			for (edge &e : adj[p.second])
				if (e.flow < e.cap &&
					dist[e.dst] > dist[e.src] + rcost(e))
				{
					back[e.dst] = &e;
					pq.push({dist[e.dst] = dist[e.src] + rcost(e),
							 e.dst});
				}
		}

		return dist[sink];
	}

	pair<flow_type, cost_type> max_flow(int source, int sink)
	{
		flow_type flow = 0;
		cost_type cost = 0;

		for (int u = 0; u < n; ++u)
			for (edge &e : adj[u]) e.flow = 0;

		potential.assign(n, 0);
		dist.assign(n, 0);
		back.assign(n, nullptr);

		bellman_ford(source); // remove negative costs

		while (dijkstra(source, sink) < oo)
		{
			for (int u = 0; u < n; ++u)
				if (dist[u] < dist[sink])
					potential[u] += dist[u] - dist[sink];

			flow_type f = numeric_limits<flow_type>::max();

			for (edge *e = back[sink]; e; e = back[e->src])
				f = min(f, e->cap - e->flow);
			for (edge *e = back[sink]; e; e = back[e->src])
				e->flow += f, adj[e->dst][e->rev].flow -= f;

			flow += f;
			cost += f * (potential[sink] - potential[source]);

		}
		return {flow, cost};
	}
};

int mk1[MAXN],mk2[MAXN];
int used1,used2;

vector<int> dfs1(int u)
{
    mk1[u]=1;
    int ini=used1;
    vector<int> faltan={u};
    for(auto v : g1[u])
    {
        if(mk1[v])
           continue;
        vector<int> add=dfs1(v);
        for(auto vv : add)
            faltan.push_back(vv);
    }
    int cg=used1-ini;

    if(!c1[u])
        return faltan;
    c1[u]-=cg;
    nodes1[u]=faltan;
    used1+=c1[u];
    return {};
}

vector<int> dfs2(int u)
{
    mk2[u]=1;
    int ini=used2;
    vector<int> faltan={u};
    for(auto v : g2[u])
    {
        if(mk2[v])
           continue;
        vector<int> add=dfs2(v);
        for(auto vv : add)
            faltan.push_back(vv);
    }
    int cg=used2-ini;

    if(!c2[u])
        return faltan;
    c2[u]-=cg;
    nodes2[u]=faltan;
    used2+=c2[u];
    return {};
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,x,y,u,v;
    cin >> n >> x >> y;
    for(int i=0;i<n;i++)
        cin >> a[i];
    x--,y--;
    for(int i=0;i<n-1;i++)
    {
        cin >> u >> v;
        u--,v--;
        g1[u].push_back(v);
        g1[v].push_back(u);
    }
    for(int i=0;i<n-1;i++)
    {
        cin >> u >> v;
        u--,v--;
        g2[u].push_back(v);
        g2[v].push_back(u);
    }

    int q1;
    cin >> q1;
    for(int i=0;i<q1;i++)
    {
        int k;
        cin >> k;
        k--;
        cin >> c1[k];
    }

    int q2;
    cin >> q2;
    for(int i=0;i<q2;i++)
    {
        int k;
        cin >> k;
        k--;
        cin >> c2[k];
    }
    int v1=c1[x];
    int v2=c2[y];

    vector<int> xx=dfs1(x);
    vector<int> yy=dfs2(y);

    for(int i=0;i<n;i++)
        if(nodes1[i].size() && c1[i]<0)
        {
            db(-1)
            return 0;
        }

    for(int i=0;i<n;i++)
        if(nodes2[i].size() && c2[i]<0)
        {
            db(-1)
            return 0;
        }

    min_cost_max_flow<int,int> mcmf(2+3*n);
    for(int i=0;i<n;i++)
    {
        if(!nodes1[i].size())
            continue;
//        db("")
//        cout << i << ' ' << c1[i] << '\n';
//        for(auto y : nodes1[i])
//            cout << y << ' ';
//        cout << '\n';
        mcmf.add_edge(0,i+1,c1[i],0);
        for(auto y : nodes1[i])
            mcmf.add_edge(i+1,n+y+1,1,0);
    }

    for(int i=0;i<n;i++)
    {
        if(!nodes2[i].size())
            continue;
//        db("")
//        cout << i << ' ' << c2[i] << '\n';
//        for(auto y : nodes2[i])
//            cout << y << ' ';
//        cout << '\n';
        mcmf.add_edge(n+n+i+1,1+3*n,c2[i],0);
        for(auto y : nodes2[i])
            mcmf.add_edge(n+y+1,n+n+i+1,1,-a[y]);
    }

    pii res=mcmf.max_flow(0,1+3*n);
//    cout << res.first << ' ' << res.second << '\n';
    if(res.first==v1 && res.first==v2)
        db(-res.s)
    else
        db(-1)

    return 0;
}
/**
4 1 2
1 2 3 4
1 2
1 3
3 4
1 2
2 3
1 4
2
1 3
4 1
1
2 3
**/