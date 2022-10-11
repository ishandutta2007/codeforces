#include <iostream>
#include <algorithm>
using namespace std;

int N;
long double p[100][100], prob[100][100][100], dp[100][100][100];

void dfs(int cl, int cr) {
	if (cr - cl == 1) { prob[cl][cr][cl] = 1.0; return; }

	int mid = ((cl + cr) >> 1);
	dfs(cl, mid);
	dfs(mid, cr);

	for (int i = cl; i < mid; i++) {
		for (int j = mid; j < cr; j++) {
			prob[cl][cr][i] += prob[cl][mid][i] * prob[mid][cr][j] * p[i][j];
			prob[cl][cr][j] += prob[cl][mid][i] * prob[mid][cr][j] * p[j][i];
		}
	}
}

long double solve(int cl, int cr, int decided) {
	if (dp[cl][cr][decided] >= 0.5) return dp[cl][cr][decided] - 1.0;
	if (cr - cl == 1) return 0.0;

	int mid = ((cr + cl) >> 1);
	long double ans = 0.0;
	if (decided < mid) {
		long double a1 = solve(cl, mid, decided);
		for (int i = mid; i < cr; i++) {
			long double a2 = solve(mid, cr, i);
			long double a3 = 0.5 * (cr - cl) * prob[cl][cr][decided];
			ans = max(ans, a1 + a2 + a3);
		}
	}
	else {
		long double a1 = solve(mid, cr, decided);
		for (int i = cl; i < mid; i++) {
			long double a2 = solve(cl, mid, i);
			long double a3 = 0.5 * (cr - cl) * prob[cl][cr][decided];
			ans = max(ans, a1 + a2 + a3);
		}
	}
	dp[cl][cr][decided] = ans + 1.0;
	return ans;
}

int main() {
	cin >> N;
	for (int i = 0; i < (1 << N); i++) {
		for (int j = 0; j < (1 << N); j++) {
			cin >> p[i][j]; p[i][j] *= 0.01L;
		}
	}
	dfs(0, (1 << N));
	long double ans = 0;
	for (int i = 0; i < (1 << N); i++) {
		long double ret = solve(0, (1 << N), i);
		ans = max(ans, ret);
	}
	printf("%.12Lf\n", ans);
	return 0;
}