#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	// we are trying to guess x
	ll offset = 1;
	const int MAX = 30;
	for (int i = 1; i <= MAX; ++i) {
		ll jump = 1LL << i;
		cout << "? " << offset << " " << offset + jump << endl;
		ll res = 0;
		cin >> res;
		if (res % jump != 0) {
			offset += jump / 2;
		}
	}
	cout << "! " << (1LL << MAX) - offset << '\n';
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}