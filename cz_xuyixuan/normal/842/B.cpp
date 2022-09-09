#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
#define EPS	1e-6
int sqr(int x) {
	return x * x;
}
int main() {
	ios::sync_with_stdio(false);
	int R, d, n;
	cin >> R >> d;
	d = R - d;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int x, y, r;
		cin >> x >> y >> r;
		double dist = sqrt(sqr(x) + sqr(y));
		if (dist - r + EPS >= d && dist + r - EPS <= R) ans++;
	}
	cout << ans << endl;
	return 0;
}