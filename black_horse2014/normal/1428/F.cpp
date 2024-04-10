//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug-template.hpp"
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
	int n; string s; cin >> n >> s;
	map<long long, long long> H;
	long long sum = 0, ans = 0;
	long long last = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			while (last) {
				sum += last;
				H[last]++;
				last--;
			}
			last = 0;
			H[0]++;
		} else {
			last++;
			while (!H.empty()) {
				auto it = H.begin();
				auto t = *it;
				if (it->first < last) {
					H.erase(it);
					sum -= t.first * t.second;
					sum += last * t.second;
					H[last] += t.second;
				} else {
					break;
				}
			}
			ans += last * (last + 1) / 2;
		}
		ans += sum;
	}
	cout << ans << endl;
	return 0;
}