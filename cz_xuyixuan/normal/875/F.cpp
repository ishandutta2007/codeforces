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
int f[MAXN], v[MAXN], e[MAXN];
pair <int, pair <int, int>> a[MAXN];
int F(int x) {
	if (f[x] == x) return x;
	else return f[x] = F(f[x]);
}
int main() {
	int n, m; read(n), read(m);
	for (int i = 1; i <= n; i++)
		f[i] = i, v[i] = 1;
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		read(x), read(y), read(z);
		a[i] = make_pair(z, make_pair(x, y));
	}
	sort(a + 1, a + m + 1);
	reverse(a + 1, a + m + 1);
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		int x = F(a[i].second.first);
		int y = F(a[i].second.second);
		if (x == y) {
			if (e[x] < v[x]) {
				e[x]++;
				ans += a[i].first;
			}
		} else if (e[x] < v[x] || e[y] < v[y]) {
			ans += a[i].first;
			f[y] = x, v[x] += v[y];
			e[x] += e[y] + 1;
		}
	}
	writeln(ans);
	return 0;
}