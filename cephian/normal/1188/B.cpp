#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef vector<ll> poly;

map<ll,ll> m;

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	ll n, p, k;
	cin >> n >> p >> k;
	for(int i = 0; i < n; ++i) {
		ll a;
		cin >> a;
		ll q = (a*a % p) * (a*a % p) % p - k * a;
		q %= p;
		if(q < 0) q += p;
		++m[q];
	}
	ll ans = 0;
	for(auto x : m) {
		ans += x.second * (x.second-1) / 2;
	}
	cout << ans << "\n";
}