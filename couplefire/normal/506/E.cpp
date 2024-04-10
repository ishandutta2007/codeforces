#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;
const int mm = 10007;
const ll Cut = 1ll << 57;

ll ans = 0;

struct Matrix {
	int a[403][403];
}a, b;

int f[202][202][202];
char s[202];

int n, len, m, N, M;

int Dfs(int l, int r, int c) {
	if (c < 0) return 0;
	if (f[l][r][c] > -1) return f[l][r][c];
	if (l > r) {
		if (!c) return 1;
		return 0;
	}
	int &tmp = f[l][r][c];
	tmp = 0;
	if (s[l] == s[r]) tmp = Dfs(l + 1, r - 1, c);
	else tmp = Dfs(l + 1, r, c - 1) + Dfs(l, r - 1, c - 1);
	if (tmp >= mm) tmp -= mm;
	return tmp;
}

Matrix Mul(const Matrix &a, const Matrix &b) {
	Matrix c;
	long long x;
	for (int i = 1; i < M; ++i)
		for (int j = 1; j < M; ++j) {
			x = 0;
			for (int k = i; k <= j; ++k) {
				x += a.a[i][k] * b.a[k][j];
			}
			c.a[i][j] = x % mm;
		}
	return c;
}

Matrix ksm(Matrix x, int y) {
	Matrix r;
	memset(r.a, 0, sizeof(r.a));
	for (int i = 1; i < M; ++i) r.a[i][i] = 1;
	while (y) {
		if (y & 1) r = Mul(r, x);
		x = Mul(x, x);
		y >>= 1;
	}
	return r;
}

int main()
{
	//freopen("build.in", "r", stdin);
	//freopen("build.out", "w", stdout);
	scanf("%s", s+1);
	scanf("%d", &n);
	len = strlen(s+1);
	memset(f, -1, sizeof(f));
	for (int i = 0; i < len; ++i) {
		Dfs(1, len, i);
		if (f[1][len][i] < 0) f[1][len][i] = 0;
	}
	memset(a.a, 0, sizeof(a.a));
	for (int i = 1; i < len; ++i) a.a[i][i] = 24;
	m = (len - 1) / 2 + 1;
	for (int i = 0; i < m; ++i) {
		a.a[len + i][len + i] = 25; a.a[len + m + i][len + m + i] = 26;
		a.a[len + i][len + m + i] = 1;
	}
	for (int i = 2; i < len + m; ++i) a.a[i - 1][i] = 1;
	M = len + m + m;	N = (len + n - 1) / 2 + 1;
	if (n + len & 1) {
		b = ksm(a, N - 1);
		a = Mul(a, b);
	} else a = ksm(a, N);
	int v;
	for (int i = 0; i < len; ++i) {
		v = (len - i - 1) / 2 + 1;
		if (N - v - i < 0) continue;
		//cerr << v << " " << f[1][len][i] << endl;
		ans += f[1][len][i] * a.a[len - i][len + m + v - 1];
		if (ans >= Cut) ans %= mm;
		//if (ans >= mm) ans -= mm;
	}
	if (n + len & 1) {
		//for (int i = 0; i < m; ++i) b.a[len + m + i][len + m + i] = 0;
		for (int i = 0; i < len; ++i) {
			if (((len - i) & 1)) continue;
			v = (len - i - 1) / 2 + 1;
			ans -= f[1][len][i] * b.a[len - i][len + v - 1];
			if (ans < 0) ans += mm;
		}
	}
	ans %= mm;
	if (ans < 0) ans += mm;
	printf("%I64d\n", ans);
	//fclose(stdin); fclose(stdout);
}