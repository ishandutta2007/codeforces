/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

void solve() {
	int p, q, pc, qc;
	cin >> p >> q;
	if (p % q) {
		cout << p << '\n';
		return;
	}
	pc = p, qc = q;
	map <int, int> mp;
	for (int i = 2; i * i <= q; i++) {
		if (qc % i)
			continue;
		while (qc % i == 0) {
			mp[i]--;
			qc /= i;
		}
		while (pc % i == 0) {
			mp[i]++;
			pc /= i;
		}
	}
	if (pc != 1 && qc != 1) {
		while (pc % qc == 0) {
			mp[qc]++;
			pc /= qc; 
		}
	}
	if (qc != 1) {
		mp[qc]--;
		qc = 1; 
	}
	int mn = LLONG_MAX;
	for (auto [x, y] : mp) {
		int po = pow(x, y + 1);
		mn = min(mn, po);
	}
	cout << p / mn << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}