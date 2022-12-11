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

int n, a[N], p[N], l[N], r[N];
bool vis[N];
std::multiset<int> orz;

void work()
{
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]), p[a[i]] = i;
	for (int i = 0; i <= n + 1; i++) vis[i] = 0; orz.clear();
	for (int i = 1; i <= n; i++)
	{
		int x = p[i], mx;
		if (vis[n]) orz.erase(orz.find(n - l[n] + 1));
		mx = orz.empty() ? 1 : (*--orz.end()) + 1;
		if (vis[n]) orz.insert(n - l[n] + 1);
		int len = vis[x - 1] ? x - l[x - 1] + 1 : 1;
		if (len != mx) return (void) puts("No");
		int le = vis[x - 1] ? l[x - 1] : x, ri = vis[x + 1] ? r[x + 1] : x;
		if (vis[x - 1]) orz.erase(orz.find(x - l[x - 1]));
		if (vis[x + 1]) orz.erase(orz.find(r[x + 1] - x));
		orz.insert(ri - le + 1); vis[x] = 1; r[le] = ri; l[ri] = le;
	}
	puts("Yes");
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}