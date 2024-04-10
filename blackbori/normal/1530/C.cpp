#include <bits/stdc++.h>

using namespace std;

int A[101010], B[101010];
int n;

void tc() {
	int i, s, e, m;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> A[i];
	}
	sort(A + 1, A + n + 1);
	reverse(A + 1, A + n + 1);
	for (i = 1; i <= n; i++) {
		cin >> B[i];
	}
	sort(B + 1, B + n + 1);
	reverse(B + 1, B + n + 1);

	for (i = 1; i <= n; i++) {
		A[i] += A[i - 1];
		B[i] += B[i - 1];
	}

	auto check = [&](int k) {
		int a, b, t;
		t = (n + k) - (n + k) / 4;
		if (t <= k) a = 100 * t;
		else a = 100 * k + A[t - k];
		if (t < n) b = B[t];
		else b = B[n];
		return a >= b;
	};

	for (s = 0, e = 1e7; s <= e; ) {
		m = (s + e) / 2;
		if (check(m)) e = m - 1;
		else s = m + 1;
	}
	cout << e + 1 << "\n";
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