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

int n, m, k;
char s[N][N];
bool a[N][N];

struct res
{
	int x1, y1, x2, y2, x3, y3;
} ans[N * N];

void work()
{
	read(n); read(m); k = 0;
	for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
		a[i][j] = s[i][j] - '0';
	for (int i = 1; i <= n - 2; i++)
		for (int j = 1; j <= m; j++)
		{
			int y1 = j, y2 = j + 1; if (j == m) y1--, y2--;
			if (a[i][j]) a[i][j] = 0, a[i + 1][y1] ^= 1,
				a[i + 1][y2] ^= 1, ans[++k] = (res) {i, j, 
					i + 1, y1, i + 1, y2};
		}
	for (int i = 1; i <= m - 2; i++)
		for (int j = n - 1; j <= n; j++)
			if (a[j][i]) a[j][i] = 0, a[n - 1][i + 1] ^= 1,
				a[n][i + 1] ^= 1, ans[++k] = (res) {j, i,
					n - 1, i + 1, n, i + 1};
	int ia = a[n - 1][m - 1], ib = a[n - 1][m], ic = a[n][m - 1],
		id = a[n][m];
	for (int S = 0; S < 16; S++)
	{
		int cnt = 0, na = ia, nb = ib, nc = ic, nd = id;
		if (S & 1) cnt++, na ^= 1, nb ^= 1, nc ^= 1,
			ans[++k] = (res) {n - 1, m - 1, n - 1, m, n, m - 1};
		if ((S >> 1) & 1) cnt++, na ^= 1, nb ^= 1, nd ^= 1,
			ans[++k] = (res) {n - 1, m - 1, n - 1, m, n, m};
		if ((S >> 2) & 1) cnt++, na ^= 1, nc ^= 1, nd ^= 1,
			ans[++k] = (res) {n - 1, m - 1, n, m - 1, n, m};
		if ((S >> 3) & 1) cnt++, nb ^= 1, nc ^= 1, nd ^= 1,
			ans[++k] = (res) {n - 1, m, n, m - 1, n, m};
		if (!na && !nb && !nc && !nd)
		{
			printf("%d\n", k);
			for (int i = 1; i <= k; i++)
			{
				printf("%d %d %d %d %d %d\n", ans[i].x1, ans[i].y1,
					ans[i].x2, ans[i].y2, ans[i].x3, ans[i].y3);
				a[ans[i].x1][ans[i].y1] ^= 1;
				a[ans[i].x2][ans[i].y2] ^= 1;
				a[ans[i].x3][ans[i].y3] ^= 1;
			}
			return;
		}
		else k -= cnt;
	}
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}