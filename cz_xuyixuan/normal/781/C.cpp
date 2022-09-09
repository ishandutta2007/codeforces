#include<bits/stdc++.h>
using namespace std;
const int MAXN = 400005;
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
int n, m, k;
int f[MAXN];
int len, ans[MAXN];
vector <int> a[MAXN];
int F(int x) {
	if (f[x] == x) return x;
	else return f[x] = F(f[x]);
}
void work(int pos, int fa) {
	ans[++len] = pos;
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i] != fa) {
			work(a[pos][i], pos);
			ans[++len] = pos;
		}
}
int main() {
	read(n), read(m), read(k);
	for (int i = 1; i <= n; i++)
		f[i] = i;
	for (int i = 1; i <= m; i++) {
		int x, y; read(x), read(y);
		if (F(x) != F(y)) {
			a[x].push_back(y);
			a[y].push_back(x);
			f[F(x)] = F(y);
		}
	}
	work(1, 0);
	int limit = min(2 * n / k + (2 * n % k != 0), len), now = 0;
	for (int i = 1; i <= k; i++) {
		int r = min(len, limit + now);
		int l = r - limit + 1;
		printf("%d ", limit);
		for (int j = l; j <= r; j++)
			printf("%d ", ans[j]);
		printf("\n");
		now = r;
	}
	return 0;
}