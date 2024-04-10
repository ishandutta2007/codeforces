#include<bits/stdc++.h>
using namespace std;
const int MAXN = 4005;
const int P = 998244353;
const int inv2 = (P + 1) / 2; 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
int cur[MAXN], ans[MAXN];
int binom[MAXN][MAXN];
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
int power(int x, int y) {
	if (y == 0) return 1;
	int tmp = power(x, y / 2);
	if (y % 2 == 0) return 1ll * tmp * tmp % P;
	else return 1ll * tmp * tmp % P * x % P;
}
int main() {
	int n, k, l;
	read(n), read(k), read(l);
	for (int i = 0; i <= n; i++) {
		binom[i][0] = 1;
		for (int j = 1; j <= i; j++)
			binom[i][j] = (binom[i - 1][j] + binom[i - 1][j - 1]) % P;
	}
	cur[n] = power(2, n);
	for (int i = 1; i <= n; i++) {
		for (int j = 2 * n; j >= 1; j--)
			cur[j] = (cur[j - 1] - cur[j] + P) % P;
		for (int j = 0; j <= 2 * n; j++)
			cur[j] = (P - cur[j]) % P;
	}
	for (int i = n; i >= k; i--) {
		for (int j = 0; j <= 2 * n; j++)
			update(ans[j], 1ll * cur[j] * binom[n][i] % P);
		for (int j = 0; j <= 2 * n; j++)
			cur[j] = 1ll * cur[j + 1] * inv2 % P;
		for (int j = 0; j <= 2 * n - 1; j++)
			update(cur[j + 1], cur[j]);
		static int tmp[MAXN];
		memset(tmp, 0, sizeof(tmp));
		for (int j = 0; j <= 2 * n - 2; j++) {
			update(tmp[j], cur[j]);
			update(tmp[j + 1], P - 2 * cur[j] % P);
			update(tmp[j + 2], 2 * cur[j] % P);
		}
		memcpy(cur, tmp, sizeof(tmp));
	}
	int res = 0;
	for (int i = 0; i <= 2 * n; i++)
		update(res, 1ll * ans[i] * power(i + 1, P - 2) % P);
	writeln(1ll * res * l % P);
	return 0;
}