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
int n, k, x, y, ans[MAXN], d[MAXN];
int tot, rk[MAXN];
vector <int> a[MAXN];
void dfsc(int pos, int fa, int c) {
	ans[pos] = c;
	for (auto x : a[pos])
		if (x != fa) dfsc(x, pos, 3 - c);
}
void dfsd(int pos, int fa, int dist) {
	d[pos] = dist;
	for (auto x : a[pos])
		if (x != fa) dfsd(x, pos, dist + 1);
}
bool findpath(int pos, int fa) {
	if (pos == y) {
		rk[pos] = ++tot;
		return true;
	}
	for (auto x : a[pos])
		if (x != fa && findpath(x, pos)) {
			rk[pos] = ++tot;
			return true;
		}
	return false;
}
int maxdepth(int pos, int fa, int d) {
	int res = d;
	for (auto x : a[pos])
		if (x != fa && ans[x] == 0) chkmax(res, maxdepth(x, pos, d + 1));
	return res;
}
void colour(int pos, int fa, int cur, int d) {
	ans[pos] = cur;
	cur += d;
	if (cur > k) cur -= k;
	if (cur < 1) cur += k;
	for (auto x : a[pos])
		if (x != fa && ans[x] == 0) colour(x, pos, cur, d);
}
int main() {
	read(n), read(k);
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	if (k == 2) {
		puts("Yes");
		dfsc(1, 0, 1);
		for (int i = 1; i <= n; i++)
			printf("%d ", ans[i]);
		return 0;
	}
	dfsd(1, 0, 1);
	for (int i = 1; i <= n; i++)
		if (d[i] > d[x]) x = i;
	dfsd(x, 0, 1);
	for (int i = 1; i <= n; i++)
		if (d[i] > d[y]) y = i;
	findpath(x, 0);
	for (int i = 1; i <= n; i++)
		if (rk[i]) ans[i] = rk[i] % k + 1;
	for (int i = 1; i <= n; i++)
		if (rk[i]) {
			int d = maxdepth(i, 0, 0);
			if (d != 0) {
				if (d + rk[i] >= k && d + tot - rk[i] + 1 >= k) {
					puts("No");
					return 0;
				}
				if (d + rk[i] >= k) colour(i, 0, ans[i], 1);
				else colour(i, 0, ans[i], -1);
			}
		}
	puts("Yes");
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	return 0;
}