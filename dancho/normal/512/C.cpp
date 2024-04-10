#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;

const int MAXN = 512;
const int INF = 1000000000;
 
struct edge {
	int a, b, cap, flow;
};
 
int n, s, t, d[MAXN], ptr[MAXN], q[MAXN];
vector<edge> e;
vector<int> g[MAXN];
 
void add_edge (int a, int b, int cap) {
	//~ printf("ED %d %d %d\n", a + 1, b + 1, cap);
	edge e1 = { a, b, cap, 0 };
	edge e2 = { b, a, 0, 0 };
	g[a].push_back ((int) e.size());
	e.push_back (e1);
	g[b].push_back ((int) e.size());
	e.push_back (e2);
}
 
bool bfs() {
	int qh=0, qt=0;
	q[qt++] = s;
	memset (d, -1, n * sizeof d[0]);
	d[s] = 0;
	while (qh < qt && d[t] == -1) {
		int v = q[qh++];
		for (size_t i=0; i<g[v].size(); ++i) {
			int id = g[v][i],
				to = e[id].b;
			if (d[to] == -1 && e[id].flow < e[id].cap) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[t] != -1;
}
 
int dfs (int v, int flow) {
	if (!flow)  return 0;
	if (v == t)  return flow;
	for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
		int id = g[v][ptr[v]],
			to = e[id].b;
		if (d[to] != d[v] + 1)  continue;
		int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
		if (pushed) {
			e[id].flow += pushed;
			e[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}
 
int dinic() {
	int flow = 0;
	for (;;) {
		if (!bfs())  break;
		memset (ptr, 0, n * sizeof ptr[0]);
		while (int pushed = dfs (s, INF))
			flow += pushed;
	}
	return flow;
}

bool us[MAXN];
vector<int> buf;

void dfs(int v)
{
	if (us[v])
		return;
	us[v] = 1;
	buf.push_back(v);
	for (int i = 0; i < (int) g[v].size(); ++i)
	{
		if (e[g[v][i]].flow)
		{
			int u = e[g[v][i]].b;
			if (u < n - 2)
				dfs(u);
		}
	}
}

bool isp(int x)
{
	for (int i = 2; i * i <= x; ++i)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}

int a[MAXN];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (isp(a[i] + a[j]))
			{
				if (a[i] % 2 == 0)
					add_edge(i, j, 1);
				else
					add_edge(j, i, 1);
			}
		}
	}

	++n;
	int od, ev;
	od = 0;
	ev = 0;
	for (int i = 0; i < n-1; ++i)
	{
		if ((a[i] % 2) == 0)
		{
			++ev;
			add_edge(n - 1, i, 2);
		}
	}

	++n;
	for (int i = 0; i < n-2; ++i)
	{
		if ((a[i] % 2) == 1)
		{
			++od;
			add_edge(i, n - 1, 2);
		}
	}

	s = n - 2;
	t = n - 1;
	//~ printf("%d : %d %d\n", dinic(), od, ev);
	if (dinic() != (n - 2))
	{
		printf("Impossible\n");
		return 0;
	}

	memset(us, 0, sizeof(us));
	vector<vector<int>> sl;
	for (int i = 0; i < n - 2; ++i)
	{
		buf.clear();
		dfs(i);
		if (buf.size())
		{
			sl.push_back(buf);
		}
	}

	printf("%d\n", (int) sl.size());
	for (int i = 0; i < (int) sl.size(); ++i)
	{
		printf("%d", (int) sl[i].size());
		for (int j = 0; j < (int) sl[i].size(); ++j)
		{
			printf(" %d", sl[i][j] + 1);
		}
		printf("\n");
	}

	return 0;
}