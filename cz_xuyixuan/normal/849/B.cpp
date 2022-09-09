#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
#define EPS	1e-6
double a[MAXN], b[MAXN], c[MAXN];
bool equal(double x, double y) {
	return fabs(x - y) <= EPS;
}
int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	if (n <= 1) {
		cout << "No" << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 2; i <= n; i++) {
		double k = (a[i] - a[1]) / (i - 1);
		int cnt = 0;
		for (int j = 2; j <= n; j++)
			if (!equal(a[1] + k * (j - 1), a[j])) {
				++cnt;
				b[cnt] = a[j];
				c[cnt] = j;
			}
		if (cnt == 0) {
			cout << "No" << endl;
			return 0;
		}
		if (cnt == 1) {
			cout << "Yes" << endl;
			return 0;
		}
		bool flg = true;
		for (int j = 2; j <= cnt; j++)
			if (!equal(b[1] + k * (c[j] - c[1]), b[j])) {
				flg = false;
				break;
			}
		if (flg) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	if (n == 2) {
		cout << "Yes" << endl;
		return 0;
	}
	double k = a[3] - a[2];
	for (int i = 3; i <= n; i++)
		if (!equal(a[2] + k * (i - 2), a[i])) {
			cout << "No" << endl;
			return 0;
		}
	cout << "Yes" << endl;
	return 0;
}