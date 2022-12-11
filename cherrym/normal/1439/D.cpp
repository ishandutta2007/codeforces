#include <bits/stdc++.h>

const int N = 505;

int n, m, EI, f[N], g[N], h[N][N], t[N][N], C[N][N];

int main()
{
	std::cin >> n >> m >> EI;
	for (int i = 0; i <= n; i++) C[i][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % EI;
	f[0] = 1;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= i; j++)
		{
			f[i] = (1ll * C[i - 1][j - 1] * f[j - 1] % EI
				* f[i - j] % EI * (i + 1) + f[i]) % EI;
			g[i] = ((1ll * g[j - 1] * f[i - j] + 1ll * f[j - 1]
				* g[i - j]) % EI * C[i - 1][j - 1] % EI * (i + 1) + g[i]) % EI;
			g[i] = (1ll * C[i - 1][j - 1] * f[j - 1] % EI * f[i - j] % EI
				* (j * (j - 1) / 2 + (i - j) * (i - j + 1) / 2) + g[i]) % EI;
		}
	h[0][0] = 1;
	for (int i = 1; i <= n + 1; i++)
		for (int j = 0; j <= m; j++)
			for (int k = i - 1; k >= 0 && i - k - 1 <= j; k--)
			{
				int c = C[j][i - k - 1], p = j - (i - k - 1);
				h[i][j] = (1ll * c * f[i - k - 1] % EI * h[k][p] + h[i][j]) % EI;
				t[i][j] = (1ll * c * f[i - k - 1] % EI * t[k][p] + t[i][j]) % EI;
				t[i][j] = (1ll * c * g[i - k - 1] % EI * h[k][p] + t[i][j]) % EI;
			}
	return std::cout << t[n + 1][m] << std::endl, 0;
}