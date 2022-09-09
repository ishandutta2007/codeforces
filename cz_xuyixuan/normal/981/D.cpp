#include<bits/stdc++.h>
using namespace std;
const int MAXN = 55;
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
int n, k;
ll ans, s[MAXN], a[MAXN];
bool check(ll ans) {
	static bool dp[MAXN][MAXN];
	memset(dp, false, sizeof(dp));
	dp[0][0] = true;
	for (int i = 0; i <= n - 1; i++)
	for (int j = 0; j <= k - 1; j++)
		if (dp[i][j]) {
			for (int p = i + 1; p <= n; p++)
				if (((s[p] - s[i]) & ans) == ans) dp[p][j + 1] = true;
		}
	return dp[n][k];
}
int main() {
	read(n), read(k);
	for (int i = 1; i <= n; i++)
		read(a[i]), s[i] = s[i - 1] + a[i];
	for (int i = 60; i >= 0; i--) {
		ans += 1ll << i;
		if (!check(ans)) ans -= 1ll << i;
	}
	writeln(ans);
	return 0;
}