#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;



int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		ll x, y;
		cin >> x >> y;
		if(y < x) swap(x, y);
		int b = y-x;
		x -= b;
		y -= 2*b;
		if(x == y && x >= 0 && x%3 == 0) {
			cout << "YES\n";
		} else cout << "NO\n";
	}
}