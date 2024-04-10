#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

const int N = 200005;
ll a[N] = {};
set<ll> seen;

map<ll, ll> amt;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	ll n, k;
	cin >> n;
	cin >> k;
	ll MASK = (1LL<<k)-1;
	++amt[0];
	for(int i = 1; i <= n; ++i) {
		int b;
		cin >> b;
		a[i] = b ^ a[i-1];
		++amt[min(a[i], a[i]^MASK)];
	}
	ll eq0 = 0;
	for(auto x : amt) {
		ll y = x.second/2;
		ll z = x.second - y;
		eq0 += y * (y-1) / 2;
		eq0 += z * (z-1) / 2;
	}
	cout << ((1LL * n * (n+1) / 2) - eq0) << "\n";

}