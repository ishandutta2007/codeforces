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

const int N = 1e5 + 5;

int n, x, y, E, b[N], ans[N], fis[N];
std::vector<int> occ[N];
bool vis[N], ty[N];

struct elem
{
	int col, fis;
	
	friend inline bool operator < (elem a, elem b)
	{
		return a.fis < b.fis;
	}
};

std::priority_queue<elem> pq;

void work()
{
	read(n); read(x); read(y);
	for (int i = 1; i <= n; i++) read(b[i]);
	for (int i = 1; i <= n + 1; i++) vis[i] = ty[i] = 0, fis[i] = 0, occ[i].clear();
	for (int i = 1; i <= n; i++) vis[b[i]] = 1, occ[b[i]].push_back(i);
	for (int i = 1; i <= n + 1; i++) if (!vis[i]) E = i;
	int cnt = 0, bas = (2 * (n - x) - (y - x)) / 2;
	for (int i = 1; i <= n + 1; i++)
	{
		if (cnt == n - x) break;
		for (int j = 0; j < occ[i].size() && j < bas; j++)
		{
			ty[occ[i][fis[i]]] = 1; fis[i]++; cnt++;
			if (cnt == n - x) break;
		}
	}
	if (cnt < n - x) return (void) puts("NO");
	for (int i = 1; i <= n; i++) if (!ty[i]) ans[i] = b[i];
	while (!pq.empty()) pq.pop();
	for (int i = 1; i <= n + 1; i++) pq.push((elem) {i, fis[i]});
	cnt = n - y; int nowc = n - x;
	for (int i = 1; i <= n - y; i++)
	{
		elem tmp = pq.top(); if (tmp.fis * 2 <= nowc) break;
		pq.pop(); int col = tmp.col, fis = tmp.fis; cnt--; nowc--;
		ans[occ[col][--fis]] = E; pq.push((elem) {col, fis});
	}
	for (int i = 1; i <= (nowc >> 1); i++)
	{
		elem u = pq.top(); pq.pop();
		elem v = pq.top(); pq.pop();
		if ((nowc & 1) && i == (nowc >> 1))
		{
			elem w = pq.top();
			ans[occ[u.col][0]] = v.col; ans[occ[v.col][0]] = w.col;
			ans[occ[w.col][0]] = u.col;
			break;
		}
		u.fis--; v.fis--;
		ans[occ[u.col][u.fis]] = v.col; ans[occ[v.col][v.fis]] = u.col;
		pq.push(u); pq.push(v);
	}
	for (int i = 1; i <= n; i++) if (cnt && ty[i] && ans[i] != E)
		cnt--, ans[i] = E;
	puts("YES");
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	puts("");
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}