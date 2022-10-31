#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	vector<long long> a(n + 1, 0);
	const long long inf = 1LL<<61;
	a[n] = inf;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	vector<long long> b(n, 0);
	for (int i = 0; i < n; i++) b[i] = (a[i + 1] - a[i]);
	sort(b.begin(), b.end());
	vector<long long> s(n + 1, 0);
	for (int i = 0; i < n; i++) s[i + 1] = s[i] + b[i];
	int q; cin >> q;
	while (q--) {
		long long l, r; cin >> l >> r; r -= l;
		int k = upper_bound(b.begin(), b.end(), r) - b.begin();
		printf("%lld\n", (r + 1) * (n - k) + s[k]);
	}
	return 0;
}