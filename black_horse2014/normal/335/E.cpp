#include <bits/stdc++.h>
using namespace std;

double pw[33], p[33];
double f[33000][33], g[33000][33], q[33000][33], r[33000][33];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	string who; cin >> who; int n, h; cin >> n >> h;
	for (int j = 0; j <= h + 1; j++) pw[j] = j == 0 ? 1 : pw[j - 1] * 0.5;
	for (int j = 0; j <= h + 1; j++) p[j] = j == h + 1 ? pw[h] : pw[j];
	n--;
	if (who[0] == 'A') {
		double ans = 0;
		for (int i = 1; i <= h + 1; i++) {
			q[0][i] = p[i];
			for (int j = 1; j <= n; j++) {
				f[j][i] = f[j][i - 1] / p[i - 1] * p[i];
				q[j][i] = q[j][i - 1] / p[i - 1] * p[i];
			}
			for (int j = 0; j <= n; j++) {
				g[j][i] = f[j][i];
				r[j][i] = q[j][i];
			}
			int k = i - 1;
			double prob = p[k + 1], sum = 0;
			for (int j = 1; j <= n; j++) {
				f[j][i] += (sum + (1 << k) * prob) * p[i];
				q[j][i] += p[i] * prob;
				sum *= 1 - p[k], sum += f[j][k + 1];
				prob *= 1 - p[k], prob += q[j][k + 1];
			}
			for (int j = 0; j <= n; j++) {
				ans += f[j][i] * r[n - j][i] / p[i] + g[n - j][i] * q[j][i] / p[i];
			}
		}
		printf("%.15lf\n", ans + 1);
	} else {
		double ans = 0, prob = 0;
		for (int i = 1; i <= h + 1; i++) {
			q[0][i] = p[i];
			for (int k = 0; k < i; k++) {
				if (k == i - 1) {
					for (int j = 0; j <= n; j++) {
						g[j][i] = f[j][i];
						r[j][i] = q[j][i];
					}
				}
				for (int j = 1 << k; j <= n; j++) {
					f[j][i] += (f[j - (1 << k)][k + 1] + (1 << k) * q[j - (1 << k)][k + 1]) * p[i];
					q[j][i] += q[j - (1 << k)][k + 1] * p[i];
				}
			}
			for (int j = 0; j <= n; j++) {
				prob += q[j][i] * r[n - j][i] / p[i];
				ans += f[j][i] * r[n - j][i] / p[i] + g[n - j][i] * q[j][i] / p[i];
			}
		}
		printf("%.15lf\n", ans / prob + 1);
	}
	return 0;
}