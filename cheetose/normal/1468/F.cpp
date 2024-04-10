#include <bits/stdc++.h>
#define y1 y12
using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	map<pair<int, int>,int> M;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		x2 -= x1, y2 -= y1;
		if (x2 == 0) {
			y2 /= abs(y2);
		}
		else if (y2 == 0) {
			x2 /= abs(x2);
		}
		else {
			int g = abs(gcd(x2, y2));
			x2 /= g, y2 /= g;
		}
		M[{x2, y2}]++;
	}
	long long ans = 0;
	for (auto [P, x]:M) {
		if (P.first == 0 && P.second < 0)continue;
		if (P.first < 0)continue;
		if (M.find({ -P.first,-P.second }) == M.end())continue;
		ans += 1ll * x * M[{-P.first, -P.second}];
	}
	printf("%lld\n", ans);
}
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--)solve();
}