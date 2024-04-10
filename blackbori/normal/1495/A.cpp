#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

void tc() {
	vector<ll> X, Y;
	ll n, i, x, y;

	cin >> n;

	for (i = 0; i < n + n; i++) {
		cin >> x >> y;
		if (x < 0) x = -x;
		if (y < 0) y = -y;
		if (x) X.push_back(x);
		else Y.push_back(y);
	}

	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());

	ld a = 0;
	for (i = 0; i < n; i++) {
		a += sqrtl(X[i] * X[i] + Y[i] * Y[i]);
	}
	cout << a << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.precision(30);

	int t;
//*
	cin >> t;
/*/
	t = 1;
//*/
	for (; t--; tc());

	return 0;
}