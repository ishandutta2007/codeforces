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

const int N = 305;

int n, m, a[N][N], b[N][N];

void work()
{
	read(n); read(m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			read(a[i][j]), b[i][j] = (i > 1) + (i < n) + (j > 1) + (j < m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i][j] > b[i][j]) return (void) puts("NO");
	puts("YES");
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) printf("%d ", b[i][j]);
		puts("");
	}
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}