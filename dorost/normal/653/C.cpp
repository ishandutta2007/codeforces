/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 150123;
int a[N], n;
vector <int> gcand;

bool ok(int i) {
	if (i < 0 || i >= n - 1)
		return true;
	if (i % 2) {
		if (a[i] > a[i + 1]) {
			return true;
		}
	} else {
		if (a[i] < a[i + 1]) {
			return true;
		}
	}
	return false;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> n;
	int ans = 0;
	vector <int> cand;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if (i < n - 1) {
			if (i % 2) {
				if (!ok(i)) {
					cand.push_back(i);
					cand.push_back(i + 1);
					gcand.push_back(i);
					gcand.push_back(i + 1);
					gcand.push_back(i - 1);
				}
			} else {
				if (!ok(i)) {
					cand.push_back(i);
					cand.push_back(i + 1);
					gcand.push_back(i);
					gcand.push_back(i + 1);
					gcand.push_back(i - 1);
				}
			}
		}
	}
	if (cand.size() > 8) {
		cout << 0;
		return 0;
	}
	sort(cand.begin(), cand.end());
	cand.erase(unique(cand.begin(), cand.end()), cand.end());
	sort(gcand.begin(), gcand.end());
	gcand.erase(unique(gcand.begin(), gcand.end()), gcand.end());
	set <int> st;
	for (auto x : cand)
		st.insert(x);
	for (auto i : cand) {
		for (int j = 0; j < n; j++) {
			if (i == j)
				continue;
			if (st.count(i) && st.count(j) && i > j)
				continue;
			swap(a[i], a[j]);
			bool f = true;
			gcand.push_back(j - 1);
			gcand.push_back(j);
			for (auto k : gcand) {
				if (!ok(k))
					f = false;
			}
			gcand.pop_back();
			gcand.pop_back();
			ans += f;
			swap(a[i], a[j]);
		}
	}
	cout << ans;
}