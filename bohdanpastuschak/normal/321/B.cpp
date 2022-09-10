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
		
		return flow;
	}
};

const int N = 1 << 7;
int n, m;

int ne_vsi(VI b, VI c)
{		
	int ans = -1;
	FOR(i, 0, SZ(b))
	{
		if (i >= SZ(c))
			break;
			
		int curr = 0;
		bool ok = 1;
		FOR(j, 0, i + 1)
		{
			if (b[j] > c[SZ(c) - j - 1])
				ok = 0;
				
			curr -= b[j];
			curr += c[SZ(c) - j - 1];
		}
		
		if (ok)
			ans = max(ans, curr);
	}
	
	return ans;
}

VI a, b, c;

int vsi()
{
	multiset<int> mt(ALL(c));
	for(auto i: a)
	{
		auto it = mt.upper_bound(i);
		if (it == mt.end())
			return 0;
		
		mt.erase(it);
	}
	
	VI cc(ALL(mt));
	for(auto i: b)
	{
		auto it = mt.lower_bound(i);
		if (it == mt.end())
			return 0;
		
		mt.erase(it);
	}
		
	int ans = 0;
	for(auto i: cc)
		ans += i;
	for(auto i: b)	
		ans -= i;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	cin >> n >> m;
	FOR(i, 0, n)
	{
		string s;
		cin >> s;
		int x;
		cin >> x;
		if (s == "ATK")
			b.PB(x);
		else
			a.PB(x);
	}
	
	sort(ALL(a));
	sort(ALL(b));
	c.resize(m);
	FOR(i, 0, m)
		cin >> c[i];
	sort(ALL(c));
	
	int ans = 0;
	ans = max(ans, vsi());
	ans = max(ans, ne_vsi(b, c));	
	cout << ans << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}