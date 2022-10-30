#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	int chops = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		chops += a - 1;
	}
	if (chops % 2 == 0)
		cout << "maomao90\n";
	else
		cout << "errorgorn\n";
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}