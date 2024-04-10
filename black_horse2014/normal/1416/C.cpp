#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	vector<long long> cnt(30);
	vector<long long> tot(30);
	for (int i = 29; i >= 0; i--) {
		for (int j = 0, k; j < n; j = k) {
			for (k = j; k < n && (a[j].first >> i + 1) == (a[k].first >> i + 1); k++);
			if ((a[j].first >> i) != (a[k - 1].first >> i)) {
				int x = a[j].first >> i;
				ordered_set<int> S;
				for (int l = j; l < k; l++) {
					if ((a[l].first >> i) == x) {
						S.insert(a[l].second);
					} else {
						cnt[i] += S.size() - S.order_of_key(a[l].second);
						tot[i] += S.size();
					}
				}
			}
		}
	}
	int ans = 0;
	long long ret = 0;
	for (int i = 29; i >= 0; i--) {
		if (cnt[i] * 2 > tot[i]) {
			ans ^= 1 << i;
		}
		ret += min(cnt[i], tot[i] - cnt[i]);
	}
	cout << ret << ' ' << ans << '\n';
	return 0;
}