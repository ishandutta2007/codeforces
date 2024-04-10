#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#pragma warning(disable: 4996)

int n, m, s, d, a[200009], dp[200009], dp2[200009];
int main() {
	cin >> n >> m >> s >> d;
	for (int i = 1; i <= n; i++)scanf("%d", &a[i]);
	sort(a + 1, a + n + 1); a[n + 1] = m + 1;
	if (a[1] <= s) { cout << "IMPOSSIBLE" << endl; return 0; }
	dp[1] = 1; dp2[1] = 1;
	for (int i = 2; i <= n + 1; i++) {
		if (!(a[i] - a[i - 1] <= s + 1 && i <= n)) {
			int pos1 = lower_bound(a, a + n + 2, (a[i - 1] + 1) - d + 1) - a;
			if (dp2[i - 1] - dp2[pos1 - 1] >= 1) { dp[i] = 1; }
		}
		dp2[i] = dp2[i - 1] + dp[i];
	}
	if (dp[n + 1] == 0) { cout << "IMPOSSIBLE" << endl; return 0; }
	vector<pair<int, int>>X;
	int cx = n + 1;
	for (int i = n; i >= 1; i--) {
		if (dp[i] == 1) {
			X.push_back(make_pair(1, (a[cx] - 1) - (a[cx - 1] + 1)));
			X.push_back(make_pair(2, (a[cx - 1] + 1) - (a[i] - 1)));
			cx = i;
		}
	}
	X.push_back(make_pair(1, a[1] - 1));
	reverse(X.begin(), X.end());
	for (int i = 0; i < X.size(); i++) {
		if (X[i].first == 1 && X[i].second >= 1)printf("RUN %d\n", X[i].second);
		if (X[i].first == 2 && X[i].second >= 1)printf("JUMP %d\n", X[i].second);
	}
	return 0;
}