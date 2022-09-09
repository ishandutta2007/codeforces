#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
#define P	acos(-1)
#define EPS	1e-6
int a[MAXN], b[MAXN], c[MAXN], d[MAXN], e[MAXN];
int cross(int i, int j, int k) {
	return (a[j] - a[i]) * (a[k] - a[i]) + (b[j] - b[i]) * (b[k] - b[i]) + (c[j] - c[i]) * (c[k] - c[i]) + (d[j] - d[i]) * (d[k] - d[i]) + (e[j] - e[i]) * (e[k] - e[i]);
}
int sqr(int x) {
	return x * x;
}
double dot(int i, int j) {
	return sqrt(sqr(a[j] - a[i]) + sqr(b[j] - b[i]) + sqr(c[j] - c[i]) + sqr(d[j] - d[i]) + sqr(e[j] - e[i]));
}
int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];
	static int ans[MAXN], cnt = 0;
	for (int i = 1; i <= n; i++) {
		bool flg = true;
		for (int j = 1; j <= n; j++) {
			if (j == i) continue;
			if (flg == false) break;
			for (int k = 1; k <= n; k++) {
				if (k == i || k == j) continue;
				if (flg == false) break;
				if (acos(cross(i, j, k) / dot(i, j) / dot(i, k)) + EPS < P / 2) {
					flg = false;
					break;
				}
			}
		}
		if (flg) ans[++cnt] = i;
	}
	cout << cnt << endl;
	for (int i = 1; i <= cnt; i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}