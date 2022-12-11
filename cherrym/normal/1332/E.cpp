#include <bits/stdc++.h>

typedef long long ll;

const int djq = 998244353;

int n, m, L, R, c0, c1;

struct matrix
{
	int n, m, a[2][2];
	
	matrix() {}
	matrix(int _n, int _m) :
		n(_n), m(_m) {memset(a, 0, sizeof(a));}
	
	friend inline matrix operator * (matrix a, matrix b)
	{
		matrix res = matrix(a.n, b.m);
		for (int i = 0; i < a.n; i++) for (int j = 0; j < b.m; j++)
			for (int k = 0; k < a.m; k++)
				res.a[i][j] = (1ll * a.a[i][k] * b.a[k][j] + res.a[i][j]) % djq;
		return res;
	}
	
	friend inline matrix operator ^ (matrix a, ll b)
	{
		matrix res = matrix(a.n, a.m);
		for (int i = 0; i < res.n; i++) res.a[i][i] = 1;
		while (b)
		{
			if (b & 1) res = res * a;
			a = a * a;
			b >>= 1;
		}
		return res;
	}
} F, A;

int main()
{
	std::cin >> n >> m >> L >> R;
	c0 = (R >> 1) - (L - 1 >> 1); c1 = (R + 1 >> 1) - (L >> 1);
	A = matrix(2, 2); F = matrix(2, 1);
	A.a[0][0] = A.a[1][1] = c0; A.a[1][0] = A.a[0][1] = c1;
	F.a[0][0] = 1;
	F = (A ^ 1ll * n * m) * F;
	if (n * m & 1) std::cout << (F.a[0][0] + F.a[1][0]) % djq << std::endl;
	else std::cout << F.a[0][0] << std::endl;
	return 0;
}