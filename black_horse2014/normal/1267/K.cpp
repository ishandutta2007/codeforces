#include <bits/stdc++.h>

#ifdef LOCAL
#include "E:\\Competitive-Programming\\Template\\Standard Template Codes\\debug-template.hpp"
#endif

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int ncase;
	for (cin >> ncase; ncase--; ) {
		long long n; cin >> n;
		int d = 2;
		vector<int> a;
		int cnt = 0;
		while (n) {
			a.push_back(n % d);
			cnt += n % d == 0;
			n /= d;
			d++;
		}
		sort(a.begin(), a.end(), greater<int>());
		int m = a.size();
		long long ans = 1;
		for (int i = 0; i < a.size(); i++) {
			ans *= max(0, m - max(0, a[i] - 1) - i);
		}
		if (cnt) {
			a.pop_back();
			long long cur = 1;
			for (int i = 0; i < a.size(); i++) {
				cur *= max(0, m - 1 - max(0, a[i] - 1) - i);
			}
			ans -= cur * cnt;
			a.push_back(0);
		}
		for (int i = 0, j = 0; i < a.size(); i = j) {
			for (j = i; j < a.size() && a[i] == a[j]; j++) {
				ans /= j - i + 1;
			}
		}
		cout << ans - 1 << '\n';
	}
	return 0;
}