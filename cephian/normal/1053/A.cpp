#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
	ll n, m, k;
	cin >> n >> m >> k;
	if((n*m)%k == 0) {
		ll g = gcd(n, k);
		n /= g;
		k /= g;
		m /= k;
		if(g > 1) n *= 2;
		else m *= 2;
		cout << "YES\n0 0\n" << n << " 0\n0 " << m << "\n";
	} else if((n*m*2)%k == 0) {
		ll g = gcd(n, k);
		n /= g;
		k /= g;
		g = gcd(m, k);
		m /= g;
		k /= g;
		assert(k == 2);
		cout << "YES\n0 0\n" << n << " 0\n0 " << m << "\n";
	} else {
		cout << "NO\n";
	}
}