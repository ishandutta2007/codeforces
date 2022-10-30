#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const double EPS = 1e-12;

int side_line(ll x, ll y, ll a, ll b, ll c) {
	return a*x + b*y + c < 0;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll x,y,z,w,n;
	cin >> x >> y >> z >> w >> n;
	int q = 0;
	while(n--) {
		ll a,b,c;
		cin >> a >> b >> c;
		q += side_line(x,y,a,b,c) != side_line(z,w,a,b,c);
	}
	cout << q << "\n";
	return 0;
}