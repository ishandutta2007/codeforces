#include <bits/stdc++.h>
using namespace std;

int main() {
	int ncase;
	for (cin >> ncase; ncase--; ) {
		long long n, t; cin >> n >> t;
		vector<long long> vec;
		for (int k = 0; k <= min(60ll, n); k++) {
			long long val = (1LL << (k + 1)) - k - 2;
			if (val > t) break;
			if (n > 100) {
				vec.push_back(n - k);
				continue;
			}
			long double v = (pow(2, k+1) - 2 + (pow(2, n) - pow(2, n-k)) * (pow(2, n) - pow(2, n-k))) / 3;
			if (v > 1.1e18) {
				vec.push_back(n - k);
				continue;
			}
			long long vl = ((1LL << (k+1)) - 2 + ((1LL << n) - (1LL << (n-k))) * ((1LL << n) - (1LL << (n-k)))) / 3;
			if (vl >= t) {
				vec.push_back(n - k);
				continue;
			}
		}
		if (vec.empty()) puts("NO");
		else printf("YES %lld\n",  vec.back());
	}
}