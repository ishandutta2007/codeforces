//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<pair<int, int>> ans;
	vector<int> bits, link(n + 1);
	for (int i = 0; i <= 20; i++) {
		if (n & (1 << i)) {
			bits.push_back(1 << i);
		}
	}
	int temp = 1, ind = 0;
	for (auto k : bits) {
		for (int i = 1; i < k; i <<= 1) {
			for (int j = 0; j < k; j++) {
				if ((j / i) % 2 == 0) {
					ans.emplace_back(j + temp, j + i + temp);
				}
			}
		}
		for (int i = 0; i < k; i++) {
			link[i + temp] = ind;
		}
		ind++;
		temp += k;
	}
	int mxid = ind - 1;
	for (int i = 1; i + 1 < bits.size(); i++) {
		for (int k = bits[i - 1]; k < bits[i]; k <<= 1) {
			int sp1 = 0, sp2 = 0, c1 = 0, c2 = 0;
			vector <int> fst, snd;
			for (int j = 1; j <= n; j++) {
				if (link[j] == i - 1) {
					fst.push_back(j);
					if (++c1 == k) {
						break;
					}
				}
			}
			for (int j = 1; j <= n; j++) {
				if (link[j] == mxid) {
					link[j] = i - 1;
					snd.push_back(j);
					if (++c2 == k) {
						break;
					}
				}
			}
			for (int j = 0; j < k; j++) {
				ans.emplace_back(fst[j], snd[j]);
			}
		}
		int c1 = 0, c2 = 0;
		vector <int> fst, snd;
		for (int j = 1; j <= n; j++) {
			if (link[j] == i) {
				fst.push_back(j);
				if (++c1 == bits[i]) {
					break;
				}
			}
		}
		for (int j = 1; j <= n; j++) {
			if (link[j] == i - 1) {
				link[j] = i;
				snd.push_back(j);
				if (++c2 == bits[i]) {
					break;
				}
			}
		}
		for (int j = 0; j < bits[i]; j++) {
			ans.emplace_back(fst[j], snd[j]);
		}
		bits[i] <<= 1;
	}
	cout << ans.size() << "\n";
	for (auto k : ans) {
		cout << k.first << " " << k.second << "\n";
	}
	return 0;
}