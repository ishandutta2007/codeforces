#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	if (bo) res = ~res + 1;
}

typedef long long ll;

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

const int N = 2e5 + 5, INF = 0x3f3f3f3f, EI = 998244353, Z = 1e6;

int n, m, f[N][23][2], ans = INF;
std::vector<int> G1[N], G2[N];
bool vis[N][23][2], vi[N][2];
ll g[N][2];

struct elem1
{
	int u, i, col;
};

std::queue<elem1> que1;

struct elem2
{
	int u, col; ll dis;

	friend inline bool operator < (elem2 a, elem2 b)
	{
		return a.dis > b.dis;
	}
};

std::priority_queue<elem2> pq;

void extend1(int u, int i, int col, int dis)
{
	if (i > 20 || vis[u][i][col]) return;
	que1.push((elem1) {u, i, col}); f[u][i][col] = dis;
	vis[u][i][col] = 1;
}

void extend2(int u, int col, ll dis)
{
	if (dis < g[u][col]) g[u][col] = dis, pq.push((elem2) {u, col, dis});
}

int main()
{
	int x, y;
	read(n); read(m);
	while (m--) read(x), read(y), G1[x].push_back(y),
		G2[y].push_back(x);
	memset(f, INF, sizeof(f));
	que1.push((elem1) {1, 0, 0}); f[1][0][0] = 0;
	vis[1][0][0] = 1;
	while (!que1.empty())
	{
		elem1 x = que1.front(); que1.pop();
		int u = x.u, i = x.i, col = x.col, dis = f[u][i][col] + 1;
		for (int ind = 0; ind < G1[u].size(); ind++)
			extend1(G1[u][ind], i + (col == 1), 0, dis);
		for (int ind = 0; ind < G2[u].size(); ind++)
			extend1(G2[u][ind], i + (col == 0), 1, dis);
	}
	for (int i = 0; i <= 20; i++)
		ans = Min(ans, Min(f[n][i][0], f[n][i][1]) + (1 << i) - 1);
	if (ans < INF) return std::cout << ans << std::endl, 0;
	memset(g, INF, sizeof(g));
	pq.push((elem2) {1, 0, 0}); g[1][0] = 0;
	while (!pq.empty())
	{
		elem2 x = pq.top(); pq.pop();
		int u = x.u, col = x.col; if (vi[u][col]) continue;
		vi[u][col] = 1;
		for (int ind = 0; ind < G1[u].size(); ind++)
			extend2(G1[u][ind], 0, x.dis + 1 + Z * (col == 1));
		for (int ind = 0; ind < G2[u].size(); ind++)
			extend2(G2[u][ind], 1, x.dis + 1 + Z * (col == 0));
	}
	ll res = Min(g[n][0], g[n][1]); ans = res % Z; res /= Z; int oz = 1;
	while (res--) oz = (oz << 1) % EI;
	return std::cout << (ans + oz - 1) % EI << std::endl, 0;
}