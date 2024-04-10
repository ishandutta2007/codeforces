#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;



int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n;
	cin >> n;
	vector<string> g(n);
	for(int i = 0; i < n; ++i)
		cin >> g[i];
	ll ans = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(g[i][j] != 'C') continue;
			for(int k = i+1; k < n; ++k) {
				
				ans += g[k][j] == 'C';
			}
			for(int k = j+1; k < n; ++k) {
				ans += g[i][k] == 'C';
			}
		}
	}
	cout << ans << '\n';
}