#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int P = 1e9 + 7;
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
ll n; int k, num[MAXN];
int m, ans, val[MAXN], inv[MAXN];
int dp[MAXN][100], p[MAXN][100]; 
int power(int x, int y) {
	if (y == 0) return 1;
	int tmp = power(x, y / 2);
	if (y % 2 == 0) return 1ll * tmp * tmp % P;
	else return 1ll * tmp * tmp % P * x % P;
}
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
void getans(int pos, int sum, int pro) {
	if (pos == m + 1) {
		update(ans, 1ll * sum * pro % P);
		return;
	}
	for (int i = 0; i <= num[pos]; i++) {
		getans(pos + 1, sum, 1ll * pro * p[pos][i] % P);
		sum = 1ll * sum * val[pos] % P;
	}
}
int main() {
	read(n), read(k);
	for (ll i = 2; i * i <= n; i++)
		if (n % i == 0) {
			int cnt = 0;
			while (n % i == 0) n /= i, cnt++;
			num[++m] = cnt;
			val[m] = i;
		}
	if (n != 1) {
		num[++m] = 1;
		val[m] = n % P;
	}
	for (int i = 1; i <= 64; i++)
		inv[i] = power(i, P - 2);
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= k; j++)
		for (int l = 0; l <= num[i]; l++)
			dp[j][l] = 0;
		dp[0][num[i]] = 1;
		for (int j = 1; j <= k; j++)
		for (int l = 0; l <= num[i]; l++) {
			for (int o = 0; o <= l; o++)
				update(dp[j][o], 1ll * dp[j - 1][l] * inv[l + 1] % P);
		}
		for (int j = 0; j <= num[i]; j++)
			p[i][j] = dp[k][j];
	}
	getans(1, 1, 1);
	writeln(ans);
	return 0;
}