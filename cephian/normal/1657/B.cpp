#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n, b, x, y;
	cin >> n >> b >> x >> y;

	ll elem = 0, sum = 0;
	for(int i = 1; i <= n; ++i) {
		if(elem+x > b) elem -=y;
		else elem += x;
		sum += elem;
	}
	cout << sum << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}