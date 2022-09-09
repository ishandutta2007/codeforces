#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 5;
const int MAXM = 1e3 + 5;
const int MAXP = 1e7 + 5;
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
int n, m, g, b, a[MAXN];
int dist[MAXN][MAXM];
int main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++)
		read(a[i]);
	read(g), read(b);
	sort(a + 1, a + m + 1);
	memset(dist, -1, sizeof(dist));
	static pair <int, int> q[MAXP * 2];
	int l = MAXP, r = MAXP;
	dist[1][0] = 0, q[l] = make_pair(1, 0);
	while (l <= r) {
		pair <int, int> tmp = q[l++];
		int pos = tmp.first, rem = tmp.second, dis = dist[pos][rem];
		if (pos != 1) {
			int len = a[pos] - a[pos - 1];
			if (len + rem < g) {
				if (dist[pos - 1][len + rem] == -1 || dist[pos - 1][len + rem] > dis) {
					dist[pos - 1][len + rem] = dis;
					q[--l] = make_pair(pos - 1, len + rem);
				}
			} else if (len + rem == g) {
				if (dist[pos - 1][0] == -1) {
					dist[pos - 1][0] = dis + 1;
					q[++r] = make_pair(pos - 1, 0);
				}
			}
		}
		if (pos != m) {
			int len = a[pos + 1] - a[pos];
			if (len + rem < g) {
				if (dist[pos + 1][len + rem] == -1 || dist[pos + 1][len + rem] > dis) {
					dist[pos + 1][len + rem] = dis;
					q[--l] = make_pair(pos + 1, len + rem);
				}
			} else if (len + rem == g) {
				if (dist[pos + 1][0] == -1) {
					dist[pos + 1][0] = dis + 1;
					q[++r] = make_pair(pos + 1, 0);
				}
			}
		}
	}
	int ans = INT_MAX;
	if (dist[m][0] != -1) ans = dist[m][0] * g + (dist[m][0] - 1) * b;
	for (int i = 1; i <= g - 1; i++)
		if (dist[m][i] != -1) chkmin(ans, dist[m][i] * (b + g) + i);
	if (ans == INT_MAX) puts("-1");
	else cout << ans << endl;
	return 0;
}