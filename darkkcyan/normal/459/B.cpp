#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int mi = INT_MAX;
	int ma = INT_MIN;
	long long mic, mac;
	for (int i = 0; i < n; ++i) {
		int a; cin >> a;
		if (a < mi) {
			mi = a;
			mic = 1;
		} else if (a == mi) ++mic;
		if (a > ma) {
			ma = a;
			mac = 1;
		} else if (a == ma) ++mac;
	}
	cout << (ma - mi) << ' ' << (ma == mi ? mic * (mic - 1) / 2 : (mic * mac));
	return 0;
}