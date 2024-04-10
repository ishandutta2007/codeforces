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
ll n; int k;
unsigned seed;
unsigned Rand() {
	seed = seed * seed + rand();
	return seed;
}
int main() {
	read(n), read(k);
	ll l = 1, r = n;
	while (true) {
		if (r - l + 1 <= 4 * k + 5) {
			int len = r - l + 1;
			int tmp = Rand() % len;
			cout << l + tmp << ' ' << l + tmp << endl;
			string res; cin >> res;
			if (res == "Yes") return 0;
			l = max(l - k, 1ll);
			r = min(r + k, n);
		} else {
			ll mid = (l + r) / 2;
			cout << l << ' ' << mid << endl;
			string res; cin >> res;
			if (res == "Yes") {
				l = max(l - k, 1ll);
				r = min(mid + k, n);
			} else {
				l = max(mid + 1 - k, 1ll);
				r = min(r + k, n);
			}
		}
	}
	return 0;
}