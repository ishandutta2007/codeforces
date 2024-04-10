#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int P = 1e9 + 7;
const int inv2 = (P + 1) / 2;
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
int a[MAXN], b[MAXN];
long long power(long long x, long long y) {
	if (y == 0) return 1;
	long long tmp = power(x, y / 2);
	if (y % 2 == 0) return tmp * tmp % P;
	else return tmp * tmp % P * x % P;
}
int main() {
	int n, m;
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= n; i++)
		read(b[i]);
	long long ans = 0, now = 1, inv = power(m, P - 2);
	for (int i = 1; i <= n; i++) {
		if (a[i] != 0 && b[i] != 0) {
			if (a[i] > b[i]) {
				ans += now;
				ans %= P;
				break;
			}
			if (a[i] < b[i]) break;
			continue;
		}
		now = now * inv % P;
		if (a[i] != 0 && b[i] == 0) {
			ans += now * (a[i] - 1);
			ans %= P;
			continue;
		}
		if (a[i] == 0 && b[i] != 0) {
			ans += now * (m - b[i]);
			ans %= P;
			continue;
		}
		ans += now * (m - 1) % P * inv2;
		ans %= P;
	}
	cout << ans << endl;
	return 0;
}