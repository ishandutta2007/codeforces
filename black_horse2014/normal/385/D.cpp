#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1);

int x[44], y[44];

double a[44];
double dp[(1<<20)];

int main() {
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cout.setf(ios::fixed); cout << setprecision(10);
	int n, l, r; cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> a[i];
		a[i] /= 180;
		a[i] *= pi;
	}
	dp[0] = l;
	for (int i = 1; i < (1<<n); i++) {
	    dp[i] = -1e10;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				int ii = i ^ (1 << j);
				double ang = atan2(-y[j], dp[ii]-x[j]);
				ang += a[j];
				if (ang > -1e-12) {
					cout << r - l << endl;
					return 0;
				}
				ang *= -1;
				double dx = y[j] / tan(ang);
				dp[i] = max(dp[i], dx + x[j]);
				if (dp[i] > r - 1e-8) {
					cout << r - l << endl;
					return 0;
				}
			}
		}
	}
	cout << dp[(1<<n)-1] - l << endl;
}