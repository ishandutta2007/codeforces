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

const int N = 1e4 + 5, M = 1005, INF = 0x3f3f3f3f;

int n, a[N], g, r, f[N][M], T, ans = INF;
bool vis[N][M];

struct elem
{
	int u, f;
	
	friend inline bool operator < (elem a, elem b)
	{
		return a.f > b.f;
	}
};

std::priority_queue<elem> pq;

int enc(int x, int y) {return (x - 1) * (g + 1) + y;}

int main()
{
	read(n); read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	std::sort(a + 1, a + n + 1);
	read(g); read(r);
	memset(f, INF, sizeof(f));
	f[1][g] = 0; pq.push((elem) {enc(1, g), 0});
	while (!pq.empty())
	{
		elem st = pq.top(); pq.pop();
		int u = st.u / (g + 1) + 1, i = st.u % (g + 1);
		if (vis[u][i]) continue; vis[u][i] = 1;
		if (!i && f[u][0] + r < f[u][g])
			pq.push((elem) {enc(u, g), f[u][g] = f[u][0] + r});
		if (u > 1)
		{
			int len = a[u] - a[u - 1];
			if (i >= len && f[u][i] + len < f[u - 1][i - len])
				pq.push((elem) {enc(u - 1, i - len),
					f[u - 1][i - len] = f[u][i] + len});
		}
		if (u < n)
		{
			int len = a[u + 1] - a[u];
			if (i >= len && f[u][i] + len < f[u + 1][i - len])
				pq.push((elem) {enc(u + 1, i - len),
					f[u + 1][i - len] = f[u][i] + len});
		}
	}
	for (int i = 0; i <= g; i++) ans = std::min(ans, f[n][i]);
	return printf("%d\n", ans == INF ? -1 : ans), 0;
}