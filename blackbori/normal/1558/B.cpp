#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll D[4040404], S[4040404];
ll n, m, s, x;

void tc() {
	int i, j, t;
	cin >> n >> m;
	s = 1;
	for (i = 1; i <= n; i++) {
		S[i] = (S[i - 1] + S[i]) % m;
		x = (s + S[i]) % m;
		for (j = 2; j * i <= n; j++) {
			S[j * i] += x;
			S[j * i + j] += m - x;
		}
		if (i > 1) s = (s + x) % m;
	}
	cout << x << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie();

	int t = 1;

//	cin >> t;

	for (; t--; ) tc();

	return 0;
}