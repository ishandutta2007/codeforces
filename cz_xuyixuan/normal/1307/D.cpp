#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int f[MAXN], g[MAXN];
int n, m, k, key[MAXN];
vector <int> a[MAXN];
void bfs(int pos, int *dist) {
	static int q[MAXN];
	for (int i = 1; i <= n; i++)
		dist[i] = -1;
	dist[pos] = 0;
	int l = 0, r = 0; q[0] = pos;
	while (l <= r) {
		int tmp = q[l++];
		for (auto x : a[tmp])
			if (dist[x] == -1) {
				dist[x] = dist[tmp] + 1;
				q[++r] = x;
			}
	}
}
int main() {
	read(n), read(m), read(k);
	for (int i = 1; i <= k; i++)
		read(key[i]);
	for (int i = 1; i <= m; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	bfs(1, f);
	bfs(n, g);
	sort(key + 1, key + k + 1, [&] (int x, int y) {return f[x] > f[y]; });
	int Max = 0, Nax = 0, ans = 0;
	for (int i = 1; i <= k; i++) {
		int pos = key[i];
		if (g[pos] > Max) {
			Nax = Max;
			Max = g[pos];
		} else chkmax(Nax, g[pos]);
		if (i != 1) chkmax(ans, f[pos] + Nax + 1);
	}
	chkmin(ans, f[n]);
	cout << ans << endl;
	return 0;
}