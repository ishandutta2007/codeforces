#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
const int P = 998244353;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int n, fac[MAXN], inv[MAXN], dp[MAXN][MAXN];
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
	read(n), fac[0] = inv[0] = dp[0][0] = dp[1][0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = 1ll * fac[i - 1] * i % P;
		inv[i] = power(fac[i], P - 2);
	}
	for (int i = 1; i <= n; i++)
	for (int j = 0; j <= i - 1; j++) {
		update(dp[i + 1][j], 1ll * dp[i][j] * (j + 1) % P);
		update(dp[i + 1][j + 1], 1ll * dp[i][j] * (i - j) % P);
	}
	for (int i = 1; i <= n; i++) {
		int ans = 0;
		for (int j = 1; j <= n; j++)
			update(ans, 1ll * fac[n] * inv[j] % P * dp[j][i - 1] % P);
		printf("%d ", ans);
	}
	printf("\n");
	return 0;
}