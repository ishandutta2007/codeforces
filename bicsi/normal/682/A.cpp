#include <bits/stdc++.h>

using namespace std;

int tot1[5], tot2[5];

int main() {
	int n, m;
	cin >> n >> m;

	for(int i = 1; i <= n; ++i)
		tot1[i % 5] += 1;
	for(int i = 1; i <= m; ++i)
		tot2[i % 5] += 1;

	long long ans = 0;
	for(int i = 0; i < 5; ++i) {
		ans += 1LL * tot1[i] * tot2[(5 - i) % 5];
	}
	cout << ans;
	return 0;
}