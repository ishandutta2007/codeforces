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

const int N = 2e5 + 5, EI = 998244353;

int n, k, a[N], b[N], p[N];
bool vis[N];

void work()
{
	read(n); read(k); int ans = 1;
	for (int i = 1; i <= n; i++) read(a[i]), vis[i] = 0, p[a[i]] = i;
	for (int i = 1; i <= k; i++) read(b[i]), vis[b[i]] = 1;
	std::set<int> orz;
	for (int i = 1; i <= n; i++) orz.insert(i);
	for (int i = 1; i <= k; i++)
	{
		std::set<int>::iterator it = orz.find(p[b[i]]), ti = it, tmp = it;
		int cnt = 0;
		if (it != orz.begin() && !vis[a[*--it]]) cnt++;
		if ((++ti) != orz.end() && !vis[a[*ti]]) cnt++;
		ans = 1ll * ans * cnt % EI; orz.erase(tmp);
	}
	printf("%d\n", ans);
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}