#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
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
ll gcd(ll x, ll y) {
	if (y == 0) return x;
	else return gcd(y, x % y);
}
int n, p[MAXN], cnt[MAXN], dp[MAXN];
ll a[MAXN];
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 2; i <= n; i++)
		read(p[i]);
	for (int i = n; i >= 2; i--)
		a[p[i]] += a[i];
	for (int i = 1; i <= n; i++) {
		ll tmp = a[1] / gcd(a[i], a[1]);
		if (tmp <= n) cnt[tmp]++;
	}
	for (int i = n; i >= 1; i--)
	for (int j = 2 * i; j <= n; j += i)
		cnt[j] += cnt[i];
	int ans = 0; dp[1] = 1;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] != i) continue;
		update(ans, dp[i]);
		for (int j = 2 * i; j <= n; j += i)
			if (cnt[j] == j) update(dp[j], dp[i]);
	}
	writeln(ans);
	return 0;
}