#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
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
typedef pair<int,int> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<int,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(998244353);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

template<typename flow_type>
struct dinic
{
	struct edge
	{
		size_t src, dst, rev;
		flow_type flow, cap;
	};

	int n;
	vector<vector<edge>> adj;

	dinic(int n) : n(n), adj(n), level(n), q(n), it(n) {}

	void add_edge(size_t src, size_t dst, flow_type cap, flow_type rcap = 0)
	{
		adj[src].push_back({src, dst, adj[dst].size(), 0, cap});
		if (src == dst) adj[src].back().rev++;
		adj[dst].push_back({dst, src, adj[src].size() - 1, 0, rcap});
	}

	vector<int> level, q, it;

	bool bfs(int source, int sink)
	{
		fill(level.begin(), level.end(), -1);
		for (int qf = level[q[0] = sink] = 0, qb = 1; qf < qb; ++qf)
		{
			sink = q[qf];
			for (edge &e : adj[sink])
			{
				edge &r = adj[e.dst][e.rev];
				if (r.flow < r.cap && level[e.dst] == -1)
					level[q[qb++] = e.dst] = 1 + level[sink];
			}
		}
		return level[source] != -1;
	}

	flow_type augment(int source, int sink, flow_type flow)
	{
		if (source == sink) return flow;
		for (; it[source] != adj[source].size(); ++it[source])
		{
			edge &e = adj[source][it[source]];
			if (e.flow < e.cap && level[e.dst] + 1 == level[source])
			{
				flow_type delta = augment(e.dst, sink,
								  min(flow, e.cap - e.flow));
				if (delta > 0)
				{
					e.flow += delta;
					adj[e.dst][e.rev].flow -= delta;
					return delta;
				}
			}
		}
		return 0;
	}

	flow_type max_flow(int source, int sink)
	{
		for (int u = 0; u < n; ++u)
			for (edge &e : adj[u]) e.flow = 0;
		flow_type flow = 0;
		flow_type oo = numeric_limits<flow_type>::max();

		while (bfs(source, sink))
		{
			fill(it.begin(), it.end(), 0);
			for (flow_type f; (f = augment(source, sink, oo)) > 0;)
				flow += f;

		} // level[u] = -1 => source side of min cut
		return flow;
	}
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    map<pii,int> f;
    vector<int> cost(n);
    vector<pii> ps;
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        int x,y,c;
        cin >> x >> y >> c;
        sum+=c;
        cost[i]=c;
        f[pii(x,y)]=i+1;
        ps.push_back(pii(x,y));
    }

    dinic<ll> g(2+2*n);
    int source=2*n;
    int sink=2*n+1;
    for(int i=0;i<n;i++)
    {
        int x=ps[i].f;
        int y=ps[i].s;
        int bx=1^(abs(x)&1);
        int by=abs(y)&1;
        int t=(by^bx)+by+by;
//        cout << t <<' ' << x << ' ' << y << '\n';
        g.add_edge(2*i,2*i+1,cost[i]);
        if(t==0)
        {
            g.add_edge(source,2*i,1e9);
            pii p1=pii(x-1,y);
            pii p2=pii(x+1,y);
            if(f[p1])
                g.add_edge(2*i+1,2*f[p1]-2,1e9);
            if(f[p2])
                g.add_edge(2*i+1,2*f[p2]-2,1e9);
        }
        if(t==1)
        {
            pii p1=pii(x,y-1);
            pii p2=pii(x,y+1);
            if(f[p1])
                g.add_edge(2*i+1,2*f[p1]-2,1e9);
            if(f[p2])
                g.add_edge(2*i+1,2*f[p2]-2,1e9);
        }
        if(t==2)
        {
            pii p1=pii(x-1,y);
            pii p2=pii(x+1,y);
            if(f[p1])
                g.add_edge(2*i+1,2*f[p1]-2,1e9);
            if(f[p2])
                g.add_edge(2*i+1,2*f[p2]-2,1e9);
        }
        if(t==3)
            g.add_edge(2*i+1,sink,1e9);
    }
    db(sum-g.max_flow(source,sink))

    return 0;
}