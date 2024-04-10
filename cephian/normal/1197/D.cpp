#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;



int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<ll> d(n+1), as(n+1);
	for(int i = 1; i <= n; ++i) {
		cin >> as[i];
		as[i] += as[i-1];
		d[i] = 0;
		if(i >= m) {
			d[i] = d[i-m] + as[i]-as[i-m] - k;
			if(d[i] < 0)
				d[i] = 0;
		}
	}
	ll best = 0;
	for(int i = 0; i <= n; ++i) {
		best = max(best, d[i]);
		for(int j = 1; j < m && i+j <= n; ++j) {
			best = max(best, d[i] + as[i+j]-as[i] - k);
		}
	}
	cout << best << '\n';
}