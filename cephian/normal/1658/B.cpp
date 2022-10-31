#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 998244353;

void solve() {
	int n;
	cin >> n;
	if (n % 2 == 1) {
		cout << "0\n";
	} else {
		ll fc = 1;
		for (int i = 1; i <= n / 2; ++i) {
			fc = (fc * i) % mod;
		}
		cout << fc * fc % mod << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}