#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
#define MAXN 105
#define oo2 ((ll)(1e9+7))
#define MAXM 100005

ll d[MAXN][MAXN];
vector<pii> bs[MAXN];
ll mbs[MAXN][MAXM],pl[MAXM],pp[MAXM][4];

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

    ll n,m,u,v;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            d[i][j]=oo2;
    for(ll i=0;i<m;i++)
    {
        cin >> u >> v;
        u--,v--;
        d[u][v]=d[v][u]=1;
    }

    for(int i=0;i<n;i++)
        d[i][i]=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                d[j][k]=min(d[j][k],d[j][i]+d[i][k]);

    ll s,b,k,gg,de;
    cin >> s >> b >> k;
    for(ll i=0;i<s;i++)
    {
        cin >> pp[i][0] >> pp[i][1] >> pp[i][2] >> pp[i][3];
        pp[i][0]--;
        pl[i]=-(oo2*oo2);
    }
    for(int i=0;i<b;i++)
    {
        cin >> u >> de >> gg;
        u--;
        bs[u].push_back(pii(de,gg));
    }

    for(int i=0;i<n;i++)
    {
        sort(bs[i].begin(),bs[i].end());
        ll ma=0;
        for(ll j=0;j<bs[i].size();j++)
        {
            ma=max(ma,bs[i][j].second);
            mbs[i][j]=ma;
        }
    }

    dinic<ll> g(2+s);
    ll s1=0;
    for(int i=0;i<s;i++)
    {
        ll ma=0;
        bool ok=0;
        for(int j=0;j<n;j++)
        {
            if(d[j][pp[i][0]]>pp[i][2])
                continue;
            ll pos=upper_bound(bs[j].begin(),bs[j].end(),pii(pp[i][1],oo2))-bs[j].begin();
            if(pos)
                ma=max(ma,mbs[j][pos-1]),ok=1;
        }
        if(ok)
            pl[i]=ma-pp[i][3];
        if(pl[i]>0)
        {
            g.add_edge(0,i+1,pl[i]);
            s1+=pl[i];
        }
        if(pl[i]<0)
            g.add_edge(i+1,s+1,-pl[i]);
    }

    for(ll i=0;i<k;i++)
    {
        cin >> u >> v;
        g.add_edge(u,v,oo2*oo2);
    }

    db(s1-g.max_flow(0,s+1))

    return 0;
}