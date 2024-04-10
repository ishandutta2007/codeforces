#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--) {
		ll p, q, b;
		cin >> p >> q >> b;
		ll gd = gcd(p,q);
		p /= gd;
		q /= gd;
		ll lk = gcd(q,b);
		while (lk != 1) {
			while (q%lk == 0) q /= lk;
			lk = gcd(q,b);
		}
		if (p and q > 1) cout << "Infinite" << '\n';
		else cout << "Finite" << '\n';
	}
}