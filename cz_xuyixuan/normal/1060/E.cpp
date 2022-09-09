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
struct info {
	int odd, even;
	ll sum;
};
info operator + (info a, int b) {
	a.sum += a.even;
	swap(a.odd, a.even);
	return a;
}
info operator + (info a, info b) {
	a.even += b.even;
	a.odd += b.odd;
	a.sum += b.sum;
	return a;
}
info operator - (info a, info b) {
	a.even -= b.even;
	a.odd -= b.odd;
	a.sum -= b.sum;
	return a;
}
int n; ll ans;
info down[MAXN];
vector <int> a[MAXN];
void dfs(int pos, int fa) {
	down[pos] = (info) {0, 1, 0};
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i] != fa) {
			dfs(a[pos][i], pos);
			down[pos] = down[pos] + (down[a[pos][i]] + 1);
		}
}
void work(int pos, int fa, info tmp) {
	tmp = tmp + down[pos];
	ans += tmp.sum;
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i] != fa) {
			info tnp = (tmp - (down[a[pos][i]] + 1)) + 1;
			work(a[pos][i], pos, tnp);
		}
}
int main() {
	read(n);
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	work(1, 0, (info) {0, 0, 0});
	writeln(ans / 2);
	return 0;
}