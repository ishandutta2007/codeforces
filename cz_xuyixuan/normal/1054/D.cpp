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
map <int, int> mp;
int n, k, a[MAXN];
int main() {
	read(n), read(k);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	int goal = (1 << k) - 1;
	ll ans = n * (n + 1ll) / 2;
	for (int i = 1; i <= n; i++) {
		a[i] ^= a[i - 1], mp[a[i - 1]]++;
		int tmp = min(mp[a[i]], mp[goal ^ a[i]]);
		ans -= tmp; if (tmp == mp[goal ^ a[i]]) a[i] ^= goal;
	}
	writeln(ans);
	return 0;
}