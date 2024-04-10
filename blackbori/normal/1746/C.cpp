#include <bits/stdc++.h>

using namespace std;

int A[101010], B[101010];

void tc() {
	vector<pair<int, int>> V;
	int n, i;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> A[i];
		if (i > 1 && A[i - 1] > A[i]) {
			V.emplace_back(A[i - 1] - A[i], i);
		}
		B[i] = 1;
	}
	sort(V.rbegin(), V.rend());
	for (i = 1; i <= n; i++) {
		if (i - 1 < V.size()) B[i] = V[i - 1].second;
	}
	for (i = n; i >= 1; i--) {
		cout << B[i] << " ";
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;
	
	cin >> t;

	for (; t--; ) {
		tc();
	}

	return 0;
}