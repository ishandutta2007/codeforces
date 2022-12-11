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

const int N = 1005;

int n, a[N], b[N];
bool vis[N];

inline bool comp(int x, int y)
{
	return a[x] > a[y] || (a[x] == a[y] && x > y);
}

void dfs(int dep)
{
	if (dep == n) return (void) (vis[b[dep]] = 1);
	dfs(dep + 1);
	for (int i = n; i > b[dep]; i--) if (vis[i])
		printf("%d %d\n", b[dep], i);
	vis[b[dep]] = 1;
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]), b[i] = i;
	std::sort(b + 1, b + n + 1, comp);
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			ans += a[i] > a[j];
	std::cout << ans << std::endl;
	dfs(1);
	return 0;
}