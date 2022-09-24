#include <bits/stdc++.h>

using namespace std;

int A[101010], B[101010], C[101010];

void solve() {
	int i, j, a, n, m, l, r, t;
	cin >> n >> m;
	a = 0;
	for (i = 0; i < n * m; i++) {
		cin >> A[i];
		B[i] = A[i] = A[i] * 2;
	}
	sort(B, B + n * m);
	fill(C, C + n * m, 0);
	for (i = 0; i < n * m; i++) {
		j = lower_bound(B, B + n * m, A[i]) - B;
		C[j] = A[i]; B[j]--; t = j / m;
		for (l = t * m; l < j; l++) {
			if (C[l] && C[l] != A[i]) a++;
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