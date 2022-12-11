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

const int N = 2e5 + 5;

int n, m, a[N], vis[N], tot, ans[N];
std::vector<int> nxt[N];

void work()
{
	int x, y;
	read(n); read(m); tot = 0;
	for (int i = 1; i <= n; i++) nxt[i].clear();
	while (m--) read(x), read(y), nxt[y].push_back(x);
	for (int i = 1; i <= n; i++)
	{
		bool is1 = 0, is2 = 0;
		for (int j = 0; j < nxt[i].size(); j++)
			if (vis[nxt[i][j]]) (vis[nxt[i][j]] == 2 ? is2 : is1) = 1;
		if (is2) ans[++tot] = i, vis[i] = 0;
		else vis[i] = is1 ? 2 : 1;
	}
	printf("%d\n", tot);
	for (int i = 1; i <= tot; i++) printf("%d ", ans[i]);
	puts("");
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}