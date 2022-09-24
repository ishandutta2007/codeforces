#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair <ll, ll>;

priority_queue<pll> P;

void tc() {
	ll n, m, x, i, h;
	cin >> n >> m >> x;
	for (i = 1; i <= m; i++) {
		P.emplace(0, i);
	}

	cout << "YES\n";
	for (; n--; ) {
		cin >> h;
		auto [t, j] = P.top();
		P.pop(); P.emplace(t - h, j);
		cout << j << " ";
	}
	cout << "\n";

	for (; !P.empty(); P.pop());
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

	cin >> t;

	for (; t--; ) tc();

	return 0;
}