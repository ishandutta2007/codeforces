#include <bits/stdc++.h>
using namespace std;

bool is_sorted(int n, vector<int> p) {
	for (int i = 1; i <= 2*n; i++) {
		if (p[i-1] != i) return 0;
	}
	return 1;
}

vector<int> op1(int n, vector<int> a) {
	for (int i = 0; i < 2*n; i += 2) {
		swap(a[i], a[i+1]);
	}
	return a;
}

vector<int> op0(int n, vector<int> a) {
	for (int i = 0; i < n; i++) {
		swap(a[i], a[i+n]);
	}
	return a;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<int> p(2*n);
	for (int i = 0; i < 2*n; i++) {
		cin >> p[i];
	}
	if (is_sorted(n, p)) {
		cout << "0\n"; exit(0);
	}

	int ans = 10000;

	vector<int> a = p;
	int pr = 0;
	for (int op = 1; op <= 3000; op++) {
		if (pr) a = op1(n, a);
		else a = op0(n, a);

		if (is_sorted(n, a)) {
			ans = min(ans, op);
		}
		pr ^= 1;
	}

	pr = 1;
	a = p;
	for (int op = 1; op <= 3000; op++) {
		if (pr) a = op1(n, a);
		else a = op0(n, a);

		if (is_sorted(n, a)) {
			ans = min(ans, op);
		}
		pr ^= 1;
	}

	if (ans == 10000) cout << "-1\n";
	else cout << ans << '\n';

	return 0;
}