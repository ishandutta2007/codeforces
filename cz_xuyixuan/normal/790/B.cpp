#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
const int MAXK = 5;
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
vector <int> a[MAXN];
int n, k;
struct info {long long sum; int cnt[MAXK]; };
info operator + (info a, info b) {
	a.sum += b.sum;
	for (int i = 0; i < k; i++)
		a.cnt[i] += b.cnt[i];
	return a;
}
info operator - (info a, info b) {
	a.sum -= b.sum;
	for (int i = 0; i < k; i++)
		a.cnt[i] -= b.cnt[i];
	return a;
}
info vary(info a) {
	a.sum += a.cnt[0];
	int tmp = a.cnt[0];
	for (int i = 0; i < k - 1; i++)
		a.cnt[i] = a.cnt[i + 1];
	a.cnt[k - 1] = tmp;
	return a;
}
info dp[MAXN];
long long ans;
void dfs(int pos, int fa) {
	dp[pos].sum = 0;
	dp[pos].cnt[0] = 1;
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i] != fa) {
			dfs(a[pos][i], pos);
			dp[pos] = dp[pos] + vary(dp[a[pos][i]]);
		}
}
void work(int pos, int fa, info tmp) {
	tmp = dp[pos] + tmp;
	ans += tmp.sum;
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i] != fa) work(a[pos][i], pos, vary(tmp - vary(dp[a[pos][i]])));
}
int main() {
	read(n), read(k);
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	work(1, 0, (info) {0, {0}});
	writeln(ans / 2);
	return 0;
}