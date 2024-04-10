#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
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
int n, m, k, d[MAXN], x[MAXN], y[MAXN], res[MAXN];
bool vis[MAXN], del[MAXN];
vector <int> a[MAXN], b[MAXN];
int main() {
	read(n), read(m), read(k);
	for (int i = 1; i <= m; i++) {
		read(x[i]), read(y[i]);
		a[x[i]].push_back(y[i]);
		b[x[i]].push_back(i);
		a[y[i]].push_back(x[i]);
		b[y[i]].push_back(i);
		d[x[i]]++, d[y[i]]++;
	}
	static int q[MAXN];
	int l = 0, r = -1, ans = n;
	for (int i = 1; i <= n; i++)
		if (d[i] < k) {
			vis[i] = true;
			q[++r] = i;
			ans--;
		}
	for (int j = m; j >= 1; j--) {
		while (l <= r) {
			int tmp = q[l++];
			for (unsigned i = 0; i < a[tmp].size(); i++)
				if (!del[b[tmp][i]]) {
					del[b[tmp][i]] = true;
					d[tmp]--, d[a[tmp][i]]--;
					if (!vis[a[tmp][i]] && d[a[tmp][i]] < k) {
						vis[a[tmp][i]] = true;
						q[++r] = a[tmp][i];
						ans--;
					}
				}
		}
		res[j] = ans;
		if (!del[j]) {
			del[j] = true;
			d[x[j]]--, d[y[j]]--;
			if (!vis[x[j]] && d[x[j]] < k) {
				vis[x[j]] = true;
				q[++r] = x[j];
				ans--;
			}
			if (!vis[y[j]] && d[y[j]] < k) {
				vis[y[j]] = true;
				q[++r] = y[j];
				ans--;
			}
		}
	}
	for (int i = 1; i <= m; i++)
		writeln(res[i]);
	return 0;
}