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
	int n; cin >> n;
	vector<pair<long long, long long>> E;
	for (int i = 0; i < n; i++) {
		long long a, b, t; cin >> a >> b >> t;
		E.emplace_back(a, -t);
		E.emplace_back(b - t, t);
	}
	sort(E.begin(), E.end());
	multiset<long long> S;
	const long long inf = 1LL << 60;
	long long s = 0;
	long long d = inf;
	long long ans = 0;
	for (auto t : E) {
		if (t.first >= s + d) {
			ans++;
			s += d;
			if (!S.empty()) {
				d = *S.begin();
				ans += (t.first - s) / d;
				s += (t.first - s) / d * d;
			} else {
				d = inf;
			}
		}
		if (t.second < 0) {
			if (t.first - t.second < s + d) {
				s = t.first;
				d = -t.second;
			}
			S.insert(-t.second);
		} else {
			S.erase(S.find(t.second));
		}
	}
	if (d != inf) {
		ans++;
	}
	cout << ans << '\n';
	return 0;
}