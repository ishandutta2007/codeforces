#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double solve(ll a, ll b, ll c) {
	ll disc = b*b-4*a*c;
	if(disc < 0) return -1;
	return (-b + sqrt(disc)) / (2*a);
}

int main() {	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cout << setprecision(12) << fixed;
	int T;
	cin >> T;
	while(T--) {
		ll d;
		double a;
		cin >> d;
		a = solve(1, -d, d);
		if(a < -1e-9) cout << "N\n";
		else cout << "Y " << a << " " << a/(a-1) << "\n";
	}
}