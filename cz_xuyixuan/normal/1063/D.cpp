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
ll check(ll a, ll b, ll sum, ll x, ll la, ll ra, ll lb, ll rb) {
	ll y = sum - a * x;
	if (b != 0) assert(y % b == 0), y /= b;
	else assert(y == 0), y = rb;
	if (x >= la && x <= ra && y >= lb && y <= rb) return x + y;
	else return -1;
}
int main() {
	ll n, k, l, r, len;
	read(n), read(l), read(r), read(k);
	if (l <= r) len = r - l + 1;
	else len = n - l + 1 + r;
	if (n <= 1e7) {
		for (int i = n; i >= 0; i--) {
			ll tmp = k % (n + i);
			if (tmp == 0) tmp = n + i;
			if (tmp >= len && tmp >= 2 * len - (n - i + 1) && tmp <= 2 * len && tmp <= len + i) {
				writeln(i);
				return 0;
			}
		}
		printf("-1\n");
	} else {
		ll ans = -1;
		for (int i = 0; i * n <= k; i++) {
			ll sum = k - (i + 1) * len - i * (n - len), tmp;
			if (i != 0) {
				tmp = sum % i;
				chkmax(ans, check(i + 1, i, sum, tmp, 0, len, 0, n - len));
				chkmax(ans, check(i + 1, i, sum, tmp + (len - tmp) / i * i, 0, len, 0, n - len));
			}
			tmp = (-sum % (i + 1) + (i + 1)) % (i + 1);
			chkmax(ans, check(i, i + 1, sum, tmp, 0, n - len, 0, len));
			chkmax(ans, check(i, i + 1, sum, tmp + (n - len - tmp) / (i + 1) * (i + 1), 0, n - len, 0, len));
			sum++;
			if (i != 0) {
				tmp = sum % i;
				chkmax(ans, check(i + 1, i, sum, tmp + (tmp != 0) * i, 1, len, 0, n - len));
				chkmax(ans, check(i + 1, i, sum, tmp + (len - tmp) / i * i, 1, len, 0, n - len));
			}
			tmp = (-sum % (i + 1) + (i + 1)) % (i + 1);
			chkmax(ans, check(i, i + 1, sum, tmp, 0, n - len, 1, len));
			chkmax(ans, check(i, i + 1, sum, tmp + (n - len - tmp) / (i + 1) * (i + 1), 0, n - len, 1, len));
		}
		writeln(ans);
	}
	return 0;
}