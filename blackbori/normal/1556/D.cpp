#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll D[101010];

ll ask(ll a, ll b) {
	ll x, y;
	cout << "and " << a << " " << b << "\n";
	cout.flush();
	cin >> x;
	cout << "or " << a << " " << b << "\n";
	cout.flush();
	cin >> y;
	return x + y;
}

void tc() {
	ll n, k, ab, bc, ca, i, t;
	cin >> n >> k;
	ab = ask(1, 2);
	bc = ask(2, 3);
	ca = ask(3, 1);
	ll abc = ab + bc + ca >> 1;
	D[1] = abc - bc; D[2] = abc - ca; D[3] = abc - ab;
	for (i = 4; i <= n; i++) {
		t = ask(1, i); D[i] = t - D[1];
	}
	sort(D + 1, D + n + 1);
	cout << "finish " << D[k] << "\n";
	cout.flush();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

//	cin >> t;

	for (; t--; ) {
		tc();
	}

	return 0;
}