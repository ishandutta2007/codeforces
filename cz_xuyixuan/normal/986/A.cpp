#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int MAXK = 105;
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
int n, m, k, s, type[MAXN];
vector <int> a[MAXN];
int dist[MAXN][MAXK];
int main() {
	read(n), read(m), read(k), read(s);
	for (int i = 1; i <= n; i++)
		read(type[i]);
	for (int i = 1; i <= m; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	memset(dist, -1, sizeof(dist));
	for (int i = 1; i <= k; i++) {
		static int q[MAXN];
		int l = 0, r = -1;
		for (int j = 1; j <= n; j++)
			if (type[j] == i) {
				q[++r] = j;
				dist[j][i] = 0;
			}
		while (l <= r) {
			int tmp = q[l++];
			for (unsigned j = 0; j < a[tmp].size(); j++)
				if (dist[a[tmp][j]][i] == -1) {
					dist[a[tmp][j]][i] = dist[tmp][i] + 1;
					q[++r] = a[tmp][j];
				}
		}
	}
	for (int i = 1; i <= n; i++) {
		sort(dist[i] + 1, dist[i] + k + 1);
		int ans = 0;
		for (int j = 1; j <= s; j++)
			ans += dist[i][j];
		printf("%d ", ans);
	}
	return 0;
}