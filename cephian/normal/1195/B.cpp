#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;



int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	ll n, k;
	cin >> n >> k;
	ll lo = 0, hi = n;
	while(hi-lo > 1) {
		ll md = (lo+hi)/2;
		ll left = md*(md+1)/2 - (n-md);
		if(left < k) lo = md;
		else hi = md;
	}
	cout << n-hi << '\n';
}