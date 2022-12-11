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

int n, a[N], b[N], tot[N], pos[N][3], op[N][3], seq[N], pt[N], ox[N];
bool vis[N];

void work()
{
	read(n);
	for (int i = 1; i <= n; i++) tot[i] = 0, vis[i] = 0;
	for (int i = 1; i <= n; i++) read(a[i]), pos[a[i]][++tot[a[i]]] = i,
		op[a[i]][tot[a[i]]] = 0;
	for (int i = 1; i <= n; i++) read(b[i]), pos[b[i]][++tot[b[i]]] = i,
		op[b[i]][tot[b[i]]] = 1;
	for (int i = 1; i <= n; i++) if (tot[i] != 2) return (void) puts("-1");
	int ans = 0;
	for (int i = 1; i <= n; i++) if (!vis[i])
	{
		if (a[i] == b[i]) {vis[i] = 1; continue;}
		int u = i, o = 1, cnt = 0, len = 0;
		while (!vis[u])
		{
			vis[u] = 1; int nu, no, val = o ? b[u] : a[u];
			if (pos[val][1] == u) nu = pos[val][2], no = op[val][2];
			else nu = pos[val][1], no = op[val][1];
			pt[++len] = u; ox[len] = o;
			u = nu; o = no ^ 1; if (!o) cnt++;
		}
		if (len - cnt < cnt)
		{
			for (int i = 1; i <= len; i++) ox[i] ^= 1;
			cnt = len - cnt;
		}
		for (int i = 1; i <= len; i++) if (!ox[i]) seq[++ans] = pt[i];
	}
	printf("%d\n", ans);
	for (int i = 1; i <= ans; i++) printf("%d ", seq[i]);
	puts("");
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}