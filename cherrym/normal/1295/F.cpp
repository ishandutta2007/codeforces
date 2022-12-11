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

const int N = 55, M = N << 1, rqy = 998244353;

int n, l[N], r[N], m, real[M], inv[N], C[M][N], f[N][M], ans, di = 1;

int qpow(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = 1ll * res * a % rqy;
		a = 1ll * a * a % rqy;
		b >>= 1;
	}
	return res;
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++)
		read(l[i]), read(r[i]), real[++m] = l[i], real[++m] = r[i] + 1;
	std::sort(real + 1, real + m + 1);
	m = std::unique(real + 1, real + m + 1) - real - 1;
	for (int i = 1; i <= n; i++)
	{
		di = 1ll * di * qpow(r[i] - l[i] + 1, rqy - 2) % rqy;
		l[i] = std::lower_bound(real + 1, real + m + 1, l[i]) - real;
		r[i] = std::lower_bound(real + 1, real + m + 1, r[i] + 1) - real - 1;
	}
	m--;
	inv[1] = 1;
	for (int i = 2; i <= n; i++)
		inv[i] = 1ll * (rqy - rqy / i) * inv[rqy % i] % rqy;
	for (int i = 1; i <= m; i++)
	{
		int len = real[i + 1] - real[i]; C[i][0] = 1;
		for (int j = 1; j <= n; j++)
			C[i][j] = 1ll * C[i][j - 1] * inv[j] % rqy * (len + j - 1) % rqy;
	}
	f[0][m + 1] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int k = i; k >= 1; k--)
			{
				if (j < l[k] || j > r[k]) break;
				for (int h = j + 1; h <= m + 1; h++)
					f[i][j] = (1ll * f[k - 1][h] * C[j][i - k + 1] + f[i][j]) % rqy;
			}
	for (int i = 1; i <= m; i++) ans = (ans + f[n][i]) % rqy;
	return std::cout << 1ll * ans * di % rqy << std::endl, 0;
}