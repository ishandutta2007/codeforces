#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<double> VD;
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
#define debug(a) cout << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace MaxFlow
{
	const int MAX = 1 << 7;

	struct edge
	{
		int from;
		int to;
		int cap;
		int flow;
	};

	int n;
	int source;
	int sink;
	int d[MAX];
	int ptr[MAX];
	vector<edge> e;
	VI g[MAX];

	void add(int u, int v, int w)
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

	int dfs(int v, int flow)
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

			int push = dfs(to, min(flow, e[id].cap - e[id].flow));
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
		LL flow = 0;
		while (1)
		{
			if (!bfs())
				break;

			FOR(i, 0, n)
				ptr[i] = 0;

			while (int push = dfs(source, INF))
				flow += push;
		}

		
		e.clear();
		FOR(i, 0, n)
			g[i].clear();
		
		return flow;
	}
};

const int N = 1 << 7;
int n, m;
int a[N];
VI p;
vector<PII> tut[N];
vector<PII> e;

vector<PII> fact(int x)
{
	vector<PII> v;
	for(int i = 2; i * i <= x; ++i)
		if (x % i == 0)
		{
			int cnt = 0;
			while(x % i == 0)
				cnt++, x/= i;
			v.PB({i, cnt});
			p.PB(i);
		}
		
	if (x > 1)
	{
		p.PB(x);
		v.PB({x, 1});
	}
	
	return v;
}

int cnt[N];

int solve(int x)
{
	FILL(cnt, 0);
	FOR(i, 0, n)
		for(auto j: tut[i])
			if (j.X == x)
				cnt[i] = j.Y;
	
	MaxFlow::source = n;
	MaxFlow::sink = n + 1;
	MaxFlow::n = n + 2;
	
	
	for(int i = 0; i < n; i += 2)
		MaxFlow::add(MaxFlow::source, i, cnt[i]);
	for(int i = 1; i < n; i += 2)
		MaxFlow::add(i, MaxFlow::sink, cnt[i]);
	for(auto i: e)
		MaxFlow::add(i.X, i.Y, INF);
	
	return MaxFlow::dinic();
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	cin >> n >> m;
	FOR(i, 0, n)
	{
		cin >> a[i];
		tut[i] = fact(a[i]);
	}
	
	FOR(i, 0, m)
	{
		int u, v;
		cin >> u >> v;
		--u; --v;
		if (u & 1)	
			swap(u, v);
		e.PB({u, v});
	}
	
	sort(ALL(p));
	p.resize(unique(ALL(p)) - p.begin());
	int ans = 0;
	for(auto i: p)
		ans += solve(i);
		
	cout << ans << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}