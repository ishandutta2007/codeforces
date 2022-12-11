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

const int N = 22, C = (1 << 18) + 5, INF = 0x3f3f3f3f;

int n, m, Cm, a[N], f[C], st[C], d[N], fi[C], suma[C], ans[N], cnt;
bool w[N][N];

int main()
{
	int x, y, z;
	read(n); read(m); Cm = 1 << n;
	while (m--) read(x), read(y), read(z), w[x][y] = 1, a[x] += z, a[y] -= z;
	for (int S = 0; S < Cm; S++) for (int i = 1; i <= n; i++)
		if (S & (1 << i - 1)) suma[S] += a[i];
	memset(f, INF, sizeof(f));
	for (int S = Cm - 1; S >= 0; S--)
	{
		memset(d, 0, sizeof(d));
		for (int u = 1; u <= n; u++) if (S & (1 << u - 1))
			for (int v = 1; v <= n; v++)
			{
				if (!w[u][v]) continue;
				if (S & (1 << v - 1)) d[v]++;
			}
		for (int i = 1; i <= n; i++) if (!d[i])
			fi[S] |= 1 << i - 1;
	}
	f[0] = 0;
	for (int S = 0; S < Cm - 1; S++)
	{
		if (f[S] >= INF) continue;
		int U = Cm - 1 ^ S;
		for (int T = U; T; T = (T - 1) & U)
			if ((T & fi[S | T]) == T && f[S] + suma[U] < f[S + T])
				f[S + T] = f[S] + suma[U], st[S + T] = T;
	}
	for (int S = Cm - 1; S; S ^= st[S])
	{
		cnt++;
		for (int i = 1; i <= n; i++) if (S & (1 << i - 1))
			ans[i] = cnt;
	}
	for (int i = 1; i <= n; i++) printf("%d ", cnt - ans[i] + 1);
	return puts(""), 0;
}