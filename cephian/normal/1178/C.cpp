#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;

ll M = 998244353;

ll pw(ll a, ll b) {
	if(b == 0) return 1;
	if(b&1) return a * pw(a, b-1) % M;
	ll t = pw(a, b/2);
	return t * t % M;
}


int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	ll a, b;
	cin >> a >> b;
	cout << pw(2, a+b);
}