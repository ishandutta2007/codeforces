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

const int N = 105;

int n, p[N], tot, ans[N];
bool vis[N];

void work()
{
	read(n); tot = 0;
	for (int i = 1; i <= (n << 1); i++) read(p[i]);
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= (n << 1); i++) if (!vis[p[i]])
		vis[p[i]] = 1, ans[++tot] = p[i];
	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	puts("");
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}