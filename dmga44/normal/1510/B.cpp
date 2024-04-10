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
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

//int men=0;
vector<int> bests;

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
	int to;
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

		int cont=0;
		while (dijkstra(source, sink) < oo && cont<to)
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
            bests.push_back(cost);
            cont++;
		}
		return {flow, cost};
	}
};

vector<int> tp;

void dfs(int u,min_cost_max_flow<int,int>& g,int t)
{
    tp.push_back(u/2);
    int v=-1;
    for(auto e : g.adj[u])
        if(e.flow==1)
            v=e.dst;
    if(v==t)
        return ;
    dfs(v+1,g,t);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int d,n;
    cin >> d >> n;
    vector<int> kks;
    for(int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        int x=0;
        for(int j=0;j<d;j++)
            if(s[j]=='1')
                x|=(1<<j);
        kks.push_back(x);
    }

    int sum=0;
    min_cost_max_flow<int,int> g(2+2*(1<<d));
    int s=2*(1<<d);
    int t=2*(1<<d)+1;
    for(int i=0;i<n;i++)
    {
        int v=kks[i];
        int x=__builtin_popcount(v)+1;
        sum+=x;
        g.add_edge(s,2*v,1,0);
        g.add_edge(2*v+1,t,1,0);
        g.add_edge(2*v,2*v+1,1,0);
        for(int j=0;j<n;j++)
            if(i!=j && ((kks[j]&v)==v))
            {
//                cout << i << ' ' << j << '\n';
                g.add_edge(2*v+1,2*kks[j],1,-x);
            }
    }

    sum--;
    g.to=1e9;
    bests.push_back(0);
    pii kk=g.max_flow(s,t);
    int mi=0;
    for(int i=0;i<bests.size();i++)
        mi=min(mi,bests[i]);
    int to=0;
    for(int i=0;i<bests.size();i++)
        if(bests[i]==mi)
            to=i;
    g.to=to;
    kk=g.max_flow(s,t);
//    cout << kk.f << ' ' << kk.s << '\n';
    sum+=kk.s;
//    db(sum)

    vector<vector<int>> ans;
    for(auto e : g.adj[s])
        if(e.flow==1)
        {
            int u=e.dst+1;
//            cout << u << "xxx\n";
            dfs(u,g,t);
            ans.push_back(tp);
            tp.clear();
        }

    db(sum)
    vector<char> res;
    for(int i=0;i<ans.size();i++)
    {
        if(i)
            res.push_back('R');
        for(int j=0;j<ans[i].size();j++)
        {
            if(j==0)
            {
                for(int k=0;k<d;k++)
                    if(ans[i][j]&(1<<k))
                        res.push_back('0'+k);
            }
            else
            {
                for(int k=0;k<d;k++)
                    if((ans[i][j-1]^ans[i][j])&(1<<k))
                        res.push_back('0'+k);
            }
        }
    }

    for(auto c : res)
        cout << c << ' ';
    cout << '\n';

    return 0;
}