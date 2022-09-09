#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
const long long INF = 1e18;
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
int n, m, p[MAXN], c[MAXN];
vector <int> a[MAXN];
long long calc(int cnt) {
	int lft = cnt - a[1].size();
	long long ans = 0;
	int tot = 0;
	static int val[MAXN];
	for (int i = 2; i <= m; i++) {
		int tmp = 0;
		if (a[i].size() >= cnt) tmp = a[i].size() - cnt + 1;
		if (tmp > lft) return INF;
		lft -= tmp;
		for (unsigned j = 0; j < tmp; j++)
			ans += a[i][j];
		for (unsigned j = tmp; j < a[i].size(); j++)
			val[++tot] = a[i][j];
	}
	sort(val + 1, val + tot + 1);
	for (int i = 1; i <= lft; i++)
		ans += val[i];
	return ans;
}
int main() {
	long long ans = INF;
	read(n), read(m);
	for (int i = 1; i <= n; i++) {
		read(p[i]), read(c[i]);
		a[p[i]].push_back(c[i]);
	}
	for (int i = 1; i <= m; i++)
		sort(a[i].begin(), a[i].end());
	for (int cnt = a[1].size(); cnt <= n; cnt++)
		chkmin(ans, calc(cnt));
	writeln(ans);
	return 0;
}