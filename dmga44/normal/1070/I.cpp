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
//#define oo (ll)(0x3f3f3f3f3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(4e5+5)

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

    int t;
    cin >> t;
    while(t--)
    {
        int n,m,k;
        cin >> n >> m >> k;
        dinic<int> g(2+n+m);
        vector<int> cant(n);
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin >> u >> v;
            u--,v--;
            g.add_edge(i+1,m+u+1,1);
            g.add_edge(i+1,m+v+1,1);
            cant[u]++;
            cant[v]++;
            g.add_edge(0,i+1,1);
        }

        int sum=0;
        for(int i=0;i<n;i++)
        {
            g.add_edge(m+i+1,n+m+1,max(0,2*(cant[i]-k)));
            sum+=max(0,2*(cant[i]-k));
        }
        int x=g.max_flow(0,n+m+1);
        if(x==sum)
        {
            vector<bool> mk(m);
            vector<int> res(m);
            vector<int> ps[n];
            int cont=1;
            for(int i=0;i<m;i++)
                for(auto y : g.adj[i+1])
                    if(y.flow==1)
                        ps[y.dst-m-1].push_back(i);

            for(int i=0;i<n;i++)
            {
                for(int j=0;j<ps[i].size();j+=2)
                {
                    mk[ps[i][j]]=mk[ps[i][j+1]]=1;
                    res[ps[i][j]]=res[ps[i][j+1]]=cont;
                    cont++;
                }
            }
            for(int i=0;i<m;i++)
            {
                if(!mk[i])
                {
                    res[i]=cont;
                    cont++;
                }
                cout << res[i] << ' ';
            }
            cout << '\n';
        }
        else
        {
            for(int i=0;i<m;i++)
                cout << 0 << ' ';
            cout << '\n';
        }
    }

    return 0;
}
/**
3
3 3 2
1 2
2 3
3 1
4 5 2
1 2
1 3
1 4
2 3
2 4
4 6 2
1 2
1 3
1 4
2 3
2 4
3 4
**/