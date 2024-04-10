#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
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
int n, m, nxt[MAXN];
int cnt, now, ans[MAXN];
int l, r, q[MAXN];
vector <int> a[MAXN];
int main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 0; i <= n - 1; i++)
		nxt[i] = i + 1;
	for (int i = 1; i <= n; i++)
		sort(a[i].begin(), a[i].end());
	l = 0, r = 0, now = 1;
	q[0] = 1, nxt[0] = 2;
	while (nxt[0] != 0) {
		if (l > r) {
			ans[++cnt] = now;
			now = 1; l = r = 0;
			q[0] = nxt[0], nxt[0] = nxt[nxt[0]];
			continue;
		}
		int tmp = q[l++], p = nxt[0], last = 0;
		unsigned pos = 0;
		while (p != 0) {
			while (pos < a[tmp].size() && p > a[tmp][pos]) pos++;
			if (pos >= a[tmp].size() || p < a[tmp][pos]) {
				q[++r] = p; now++;
				nxt[last] = nxt[p];
				p = nxt[p];
			} else last = p, p = nxt[p];
		}
	}
	ans[++cnt] = now;
	sort(ans + 1, ans + cnt + 1);
	writeln(cnt);
	for (int i = 1; i <= cnt; i++)
		printf("%d ", ans[i]);
	return 0;
}