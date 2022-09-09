#include<bits/stdc++.h>
using namespace std;
#define MAXN	100005
#define MAXC	1000000
#define MAXD	1000005
#define INF	1e18
struct info {int d, s, t, c; };
info a[MAXN];
int used, n, m, k;
long long now[MAXN], pred[MAXD], succ[MAXD];
bool cmp(info x, info y) {
	return x.d < y.d;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
		cin >> a[i].d >> a[i].s >> a[i].t >> a[i].c;
	sort(a + 1, a + m + 1, cmp);
	int pos = 1, used = 0;
	long long sum = 0;
	for (int i = 1; i <= n; i++)
		now[i] = 0;
	for (int i = 1; i <= MAXC; i++) {
		while (pos <= m && a[pos].d <= i) {
			if (a[pos].s == 0) {
				pos++;
				continue;
			}
			int tmp = a[pos].s;
			if (now[tmp] == 0) {
				now[tmp] = a[pos].c;
				sum += a[pos].c;
				used++;
			} else {
				if (a[pos].c < now[tmp]) {
					sum -= now[tmp];
					sum += a[pos].c;
					now[tmp] = a[pos].c;
				}
			}
			pos++;
		}
		if (used == n) pred[i] = sum;
		else pred[i] = INF;
	}
	pos = m, used = 0; sum = 0;
	for (int i = 1; i <= n; i++)
		now[i] = 0;
	for (int i = MAXC; i >= 1; i--) {
		while (pos >= 1 && a[pos].d >= i) {
			if (a[pos].t == 0) {
				pos--;
				continue;
			}
			int tmp = a[pos].t;
			if (now[tmp] == 0) {
				now[tmp] = a[pos].c;
				sum += a[pos].c;
				used++;
			} else {
				if (a[pos].c < now[tmp]) {
					sum -= now[tmp];
					sum += a[pos].c;
					now[tmp] = a[pos].c;
				}
			}
			pos--;
		}
		if (used == n) succ[i] = sum;
		else succ[i] = INF;
	}
	long long ans = INF;
	for (int i = 1, j = k + 2; j <= MAXC; i++, j++)
		ans = min(ans, pred[i] + succ[j]);
	if (ans == INF) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}