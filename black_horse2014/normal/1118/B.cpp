#include <bits/stdc++.h>
using namespace std;

const int N = 220000;

int sum[2][N], a[N];

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		for (int j : {0, 1}) sum[j][i+1] = sum[j][i];
		sum[i&1][i+1] += a[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int odd = sum[0][i] + sum[1][n] - sum[1][i+1];
		if (odd * 2 == sum[0][n] + sum[1][n] - a[i]) ans++;
	}
	cout << ans << endl;
	return 0;
}