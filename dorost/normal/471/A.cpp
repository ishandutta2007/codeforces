/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int cnt[10] = {};
	for (int i = 0; i < 6; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	bool f = false, h = false;
	for (int i = 0; i < 10; i++) {
		if (cnt[i] >= 4)
			f = true;
		if (cnt[i] == 2)
			h = true;
		if (cnt[i] == 6)
			h = true;
	}
	if (!f) {
		cout << "Alien\n";
		return;
	}
	if (h) {
		cout << "Elephant";
	} else {
		cout << "Bear";
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	while (t--) {
		solve();
	}
}