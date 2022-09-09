#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
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
int n, m, now;
bool vis[MAXN], del[MAXN];
vector <int> a[MAXN], ans;
void work() {
	while (now <= n && del[now]) now++;
	if (now > n) return;
	int pos = now; del[pos] = true;
	for (unsigned i = 0; i < a[pos].size(); i++)
		del[a[pos][i]] = true;
	work();
	if (!vis[pos]) {
		vis[pos] = true;
		for (unsigned i = 0; i < a[pos].size(); i++)
			vis[a[pos][i]] = true;
		ans.push_back(pos);
	}
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
	}
	now = 1, work();
	writeln(ans.size());
	for (unsigned i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);
	return 0;
}