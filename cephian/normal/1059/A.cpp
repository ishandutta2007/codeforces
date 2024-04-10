#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	ll n, L, a;
	cin >> n >> L >> a;
	ll prev = 0;
	ll amt = 0;
	for(int i = 0; i < n; ++i) {
		ll t, l;
		cin >> t >> l;
		amt += (t-prev) / a;
		prev = t+l;
	}
	amt += (L-prev)/a;
	cout << amt << "\n";
}