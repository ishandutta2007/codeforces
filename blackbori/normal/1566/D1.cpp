#include <bits/stdc++.h>

using namespace std;

int A[101010];

void solve() {
	int i, j, a, n, m;
	cin >> n >> m;
	a = 0;
	for (i = 1; i <= n * m; i++) {
		cin >> A[i];
		for (j = 1; j < i; j++) {
			if (A[j] < A[i]) a++;
		}
	}
	cout << a << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc = 1;

	cin >> tc;

	for (; tc--; ) solve();

	return 0;
}