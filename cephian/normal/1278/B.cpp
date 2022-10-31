#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;



int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		ll a, b;
		cin >> a >> b;
		ll c = abs(a-b);
		ll ans = 0;
		while(c > 0 || c % 2 != 0) {
			++ans;
			c -= ans;
		}
		cout << ans << '\n';
	}
}