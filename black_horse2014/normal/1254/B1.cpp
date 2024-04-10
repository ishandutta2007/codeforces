#include <bits/stdc++.h>
using namespace std;

const int N = 1100000;

int a[N];
long long sum[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	long long tmp = sum[n];
	vector<long long> v;
	for (int i = 2; i * 1LL * i <= tmp; i++) {
		if (tmp % i == 0) {
			v.push_back(i);
			while (tmp % i == 0) tmp /= i;
		}
	}
	if (tmp != 1) v.push_back(tmp);
	long long ans = LLONG_MAX;
	for (long long x : v) {
		long long cur = 0;
		for (int i = 1; i < n; i++) cur += min(sum[i] % x, (sum[n] - sum[i]) % x);
		ans = min(ans, cur);
	}
	if (ans == LLONG_MAX) ans = -1;
	cout << ans << "\n";
	return 0;
}