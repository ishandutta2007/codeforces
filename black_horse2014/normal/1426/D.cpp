#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> a(n);
	long long sum = 0;
	map<long long, int> H;
	H[0] = 0;
	vector<pair<int, int>> b;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		if (H.count(sum)) {
			b.emplace_back(H[sum] + 1, i + 1);
		}
		H[sum] = i + 1;
	}
	sort(b.begin(), b.end(), [&](pair<int, int> lhs, pair<int, int> rhs) {
		return lhs.second < rhs.second;
	});
	int last = 0;
	int ans = 0;
	for (auto t : b) {
		if (t.first >= last) {
			ans++;
			last = t.second;
		}
	}
	cout << ans << '\n';
	return 0;
}