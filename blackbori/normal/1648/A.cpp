#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll X0[101010], X1[101010], Y0[101010], Y1[101010];
ll n, m, a;

void tc() {
	ll i, j;
	cin >> n >> m; a = 0;
	vector<vector<ll>> A(n + 1, vector<ll>(m + 1, 0));
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			cin >> A[i][j];
			X0[A[i][j]]++; X1[A[i][j]] += i;
			a += X0[A[i][j]] * i - X1[A[i][j]];
		}
	}
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			Y0[A[j][i]]++; Y1[A[j][i]] += i;
			a += Y0[A[j][i]] * i - Y1[A[j][i]];
		}
	}
	cout << a << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

//	cin >> t;

	for (; t--; ) {
		tc();
	}

	return 0;
}