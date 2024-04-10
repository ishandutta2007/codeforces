#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))

const double PI = acos(-1.0);
const LL INF = 1e9;
const LL LINF = 1e18;

namespace MaxFlow
{
	const int MAX = 1 << 20;
	struct edge
	{
		int from;
		int to;
		LL cap;
		LL flow;
	};

	int n;
	int source;
	int sink;
	int d[MAX];
	int ptr[MAX];
	vector<edge> e;
	VI g[MAX];

	void add(int u, int v, LL w)
	{
		g[u].push_back(SZ(e));
		e.PB({ u, v, w, 0 });
		g[v].push_back(SZ(e));
		e.PB({v, u, 0, 0});
	}

	bool bfs()
	{
		queue<int> q;
		q.push(source);
		FOR(i, 0, n)
			d[i] = -1;

		d[source] = 0;
		while (!q.empty())
		{
			int v = q.front();
			q.pop();

			for (auto i : g[v])
			{
				int to = e[i].to;
				if (d[to] != -1)
					continue;

				if (e[i].flow == e[i].cap)
					continue;

				q.push(to);
				d[to] = d[v] + 1;
			}
		}

		return d[sink] != -1;
	}

	LL dfs(int v, LL flow)
	{
		if (!flow)
			return 0;

		if (v == sink)
			return flow;

		while (1)
		{
			if (ptr[v] == SZ(g[v]))
				break;

			int id = g[v][ptr[v]];
			int to = e[id].to;

			if (d[to] != d[v] + 1)
			{
				++ptr[v];
				continue;
			}

			LL push = dfs(to, min(flow, e[id].cap - e[id].flow));
			if (push == 0)
			{
				++ptr[v];
				continue;
			}

			e[id].flow += push;
			e[id ^ 1].flow -= push;
			return push;
		}

		return 0;
	}

	LL dinic()
	{
		cerr << "Don't forget about constant: " << MAX << endl;
		cerr << "Check n: " << n << endl;
		
		LL flow = 0;
		while (1)
		{
			if (!bfs())
				break;

			FOR(i, 0, n)
				ptr[i] = 0;

			while (LL push = dfs(source, LINF))
				flow += push;
		}

		return flow;
	}
};

const int MAX = 100;
int n, m;
int a[MAX], b[MAX], c[MAX], l[MAX], r[MAX];

int node(int i, int pos)
{
	return 205 * (i + 1) + pos - (l[i] - 1);
}

int F(int i, int j)
{
	return a[i] * j * j + b[i] * j + c[i];
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n >> m;
	FOR(i, 0, n)
		cin >> a[i] >> b[i] >> c[i];
	
	FOR(i, 0, n)
		cin >> l[i] >> r[i];
	
	MaxFlow::source = 0;
	MaxFlow::sink = 50 * 210;
	MaxFlow::n = 50 * 210 + 1;
	
	FOR(i, 0, n)
	{
		MaxFlow::add(MaxFlow::source, node(i, l[i] - 1), LINF);
		MaxFlow::add(node(i, r[i]), MaxFlow::sink, LINF);
		
		FOR(j, l[i] - 1, r[i])
			MaxFlow::add(node(i, j), node(i, j + 1), INF - F(i, j + 1));
	}
	
	int u, v, w;
	FOR(i, 0, m)
	{
		cin >> u >> v >> w;
		--u; --v;
		
		FOR(j, l[u] - 1, r[u] + 1)
		{
			int x = j - w;
			if (l[v] - 1 <= x && r[v] >= x)
				MaxFlow::add(node(u, j), node(v, x), LINF);
		}
	}
	
	LL Flow = MaxFlow::dinic();
	LL ans = n * INF;
	//cout << ans << endl;
	ans -= Flow;
	cout << ans << endl;
	cerr << "Time elapsed: " << clock() / (double) CLOCKS_PER_SEC << endl;
	return 0;
}