#include <bits/stdc++.h>

const int mod = 1000000007;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
int remod(LL x) { x %= mod; return x + (x >> 63 & mod); }
int U, L, D, R;
int n;
const int MAXN = 110;
int map[MAXN][MAXN], idx;
const int MAXP = MAXN * MAXN;
int coef[MAXP], mat[MAXP][MAXN * 2];
const int dta = MAXN;
inline int & get(int a, int b) {
	return mat[a][b - a + dta];
}
inline int pw(int x) { return x * x; }
int pr[4];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 0; i < 4; ++i) std::cin >> pr[i];
	const int iv = pow(pr[0] + pr[1] + pr[2] + pr[3], mod - 2);
	for (int i = 0; i < 4; ++i) pr[i] = mul(pr[i], iv);
	const int X = 51, Y = 51;
	for (int i = 0; i != MAXN; ++i)
		for (int j = 0; j != MAXN; ++j)
			if (pw(i - X) + pw(j - Y) <= n * n)
				map[i][j] = ++idx;
	int O = map[X][Y];
	const int dx[4] = {-1, 0, 1, 0};
	const int dy[4] = {0, -1, 0, 1};
	for (int i = 0; i != MAXN; ++i)
		for (int j = 0; j != MAXN; ++j)
			if (int t = map[i][j]) {
				get(t, t) = coef[t] = mod - 1;
				for (int k = 0; k != 4; ++k)
					if (int q = map[i + dx[k]][j + dy[k]])
						get(t, q) = pr[k];
			}
	const int R = n * 2 + 3;
	for (int i = 1; i <= idx; ++i) {
		assert(get(i, i) != 0); // ???
		for (int j = i + 1; j <= i + R && j <= idx; ++j)
			if (get(j, i)) {
				const int V = pow(get(i, i), mod - 2, get(j, i));
				for (int k = i; k <= i + R && k <= idx; ++k)
					reduce(get(j, k) -= mul(get(i, k), V));
				reduce(coef[j] -= mul(coef[i], V));
			}
	}
	for (int i = idx; i; --i) {
		for (int j = i + 1; j <= i + R && j <= idx; ++j)
			if (int t = get(i, j))
				reduce(coef[i] -= mul(get(j, j), t));
		get(i, i) = pow(get(i, i), mod - 2, coef[i]);
	}
	std::cout << get(O, O) << std::endl;
	return 0;
}