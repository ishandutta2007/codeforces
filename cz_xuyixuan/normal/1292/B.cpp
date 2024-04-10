#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
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
ll x[MAXN], y[MAXN], ax, ay, bx, by, sx, sy, t;
ll absll(ll x) {
	if (x < 0) return -x;
	else return x;
}
int main() {
	int n = 1; read(x[1]), read(y[1]);
	read(ax), read(ay), read(bx), read(by);
	read(sx), read(sy), read(t);
	while (x[n] <= sx + t && y[n] <= sy + t) {
		n++;
		x[n] = ax * x[n - 1] + bx;
		y[n] = ay * y[n - 1] + by;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	for (int j = i; j <= n; j++) {
		ll dis = absll(x[i] - x[j]) + absll(y[i] - y[j]);
		ll lft = t - dis;
		if (lft >= 0) {
			if (absll(sx - x[i]) + absll(sy - y[i]) <= lft) chkmax(ans, j - i + 1);
			if (absll(sx - x[j]) + absll(sy - y[j]) <= lft) chkmax(ans, j - i + 1);
		}
	}
	cout << ans << endl;
	return 0;
}