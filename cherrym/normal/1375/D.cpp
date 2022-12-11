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

int n, a[N], tot, ans[N << 1];
bool vis[N], siv[N];

int getmex()
{
	for (int i = 0; i <= n; i++) vis[i] = 0;
	for (int i = 1; i <= n; i++) vis[a[i]] = 1;
	int res = 0;
	while (vis[res]) res++;
	return res;
}

void work()
{
	memset(siv, 0, sizeof(siv));
	read(n); tot = 0;
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++)
	{
		int cur = getmex(), pos; bool is = 0;
		for (int j = 1; j <= n; j++) if (!siv[j])
		{
			pos = j; if (j - 1 == cur) is = 1;
		}
		if (!is) ans[++tot] = pos, a[pos] = getmex();
		cur = getmex();
		ans[++tot] = cur + 1; a[cur + 1] = getmex();
		siv[cur + 1] = 1;
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