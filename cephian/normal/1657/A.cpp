#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_sq(ll a) {
	ll sqr = sqrt(a);
	return sqr*sqr == a;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		ll a, b;
		cin >> a >> b;
		if(a == 0 && b == 0) cout << "0\n";
		else if(is_sq(a*a+b*b)) cout << "1\n";
		else cout << "2\n";
	}

}