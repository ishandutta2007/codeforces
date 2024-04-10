#include <bits/stdc++.h>

using namespace std;

#define int long long

int Supply[10005], Demand[10005], DP[10005];

int32_t main() {
	int n, m;
	cin >> n >> m;

	for(int i = 1; i <= n; ++i) {
		cin >> Supply[i];
	}
	for(int i = 1; i <= n; ++i) {
		cin >> Demand[i];
	}


	fill(DP + 1, DP + n + 1, 1e18);

	for(int i = 1; i <= n; ++i) {
		for(int j = i; j >= 0; --j) {
			if(j < i)
				DP[j] = DP[j] + Supply[i] + j * m;
			if(j >= 1)
				DP[j] = min(DP[j], DP[j - 1] + Demand[i]);
		}
	}

	int ans = 1e18;
	for(int i = 0; i <= n; ++i) {
		ans = min(ans, DP[i]);
	}
	cout << ans << endl;

	return 0;
}