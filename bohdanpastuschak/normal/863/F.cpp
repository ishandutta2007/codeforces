#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")

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
const int MAX = 1e5 + 47;

namespace MinCostMaxFlow
{
	struct edge
	{
		int x, y;
		int cap, flow;
		LL price;
	};

	int n;
	int source;
	int sink;
	vector<edge> E;
	VI g[MAX];
	char used[MAX];
	LL d[MAX];
	int parent[MAX];

	void add(int x, int y, int cap, LL price)
	{
		g[x].PB(SZ(E));
		E.PB({x, y, cap, 0, price});
		g[y].PB(SZ(E));
		E.PB({y, x, 0, 0, -price});
	}

	void clear()
	{
		E.clear();
		FOR(i, 0, n)
			g[i].clear();
	}

	pair<int, LL> Flow()
	{
		int flow = 0;
		LL price = 0;

		while(1)
		{
			FOR(i, 0, n)
			{
				d[i] = LINF;
				parent[i] = -1;
				used[i] = 0;
			}

			deque<int> q;
			q.PB(source);

			d[source] = 0;

			while(!q.empty())
			{
				int v = q.front();
				q.pop_front();
				used[v] = 1;

				FOR(i, 0, SZ(g[v]))
				{
					int e = g[v][i];
					if (E[e].cap == E[e].flow)
						continue;

					int to = E[e].y;
					LL len = E[e].price;

					if (d[to] > d[v] + len)
					{
						d[to] = d[v] + len;
						parent[to] = e;

						if (used[to] == 0)
							q.PB(to);
						else
							if (used[to] == 2)
								q.push_front(to);
					}
				}

				used[v] = 2;
			}

			if (parent[sink] == -1)
				break;


			int x = sink;
			int f = INF;
			LL p = 0;

			while(x != source)
			{
				int e = parent[x];
				f = min(f, E[e].cap - E[e].flow);
				p += E[e].price;
				x = E[e].x;
			}

			x = sink;
			while(x != source)
			{
				int e = parent[x];
				E[e].flow += f;
				E[e ^ 1].flow -= f;
				x = E[e].x;
			}

			flow += f;
			price += p * f;
		}

		return MP(flow, price);
	}
};

int n, q;
int ma[MAX];
int mi[MAX];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("Out.txt", "w", stdout);

	cin >> n >> q;
	int t, l, r, v;
	FOR(i, 1, n + 1)
		mi[i] = 1, ma[i] = n;

	while(q--)
	{
		cin >> t >> l >> r >> v;
		if (t == 1)
		{
			FOR(i, l, r + 1)
				mi[i] = max(mi[i], v);
		}
		else
		{
			FOR(i, l, r + 1)
				ma[i] = min(ma[i], v);
		}
	}

	MinCostMaxFlow::source = 0;
	MinCostMaxFlow::sink = 2 * n + 1;
	MinCostMaxFlow::n = 2 * n + 2;

	FOR(i, 1, n + 1)
		MinCostMaxFlow::add(MinCostMaxFlow::source, i, 1, 0);

	FOR(i, 1, n + 1)
		FOR(j, mi[i], ma[i] + 1)
			MinCostMaxFlow::add(i, j + n, 1, 0);

	FOR(i, 1, n + 1)
		FOR(j, 1, n + 1)
			MinCostMaxFlow::add(i + n, MinCostMaxFlow::sink, 1, 2 * j - 1);

	pair<int, LL> f = MinCostMaxFlow::Flow();
	if (f.X < n)
		cout << - 1 << endl;
	else
		cout << f.Y << endl;

	return 0;
}