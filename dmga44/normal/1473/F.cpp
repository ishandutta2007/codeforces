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
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(3e3+5)

template<typename flow_type>
struct dinic
{
	struct edge
	{
		int src, dst, rev;
		flow_type flow, cap;
	};

	int n;
	vector<vector<edge>> adj;

	dinic(int n) : n(n), adj(n), level(n), q(n), it(n) {}

	void add_edge(int src, int dst, flow_type cap, flow_type rcap = 0)
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

int last[MAXN][101];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=1;i<=100;i++)
        last[0][i]=-1;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        for(int j=1;j<=100;j++)
            last[i+1][j]=last[i][j];
        last[i+1][a[i]]=i;
    }
    for(int i=0;i<n;i++)
        cin >> b[i];

    dinic<int> g(n*100+2);
    int t=n*100;
    int s=n*100+1;
    int sum=0;
    for(int i=n-1;i>=0;i--)
    {
        if(b[i]>=0)
        {
            g.add_edge(s,100*i+a[i]-1,b[i]);
            for(int j=1;j<=a[i] && i;j++)
                if(a[i]%j==0)
                {
                    int bb=last[i][j];
                    if(bb!=-1)
                        g.add_edge(100*i+a[i]-1,100*(bb)+j-1,b[i]);
                }
            sum+=b[i];
        }
        else
            g.add_edge(100*i+a[i]-1,t,-b[i]);
        if(i)
            for(int j=0;j<100;j++)
            {
                int bb=last[i][j+1];
                if(bb!=-1 && j+1==a[i])
                    g.add_edge(100*i+j,100*(bb)+j,1e9);
            }
    }
    db(sum-g.max_flow(s,t))

    return 0;
}