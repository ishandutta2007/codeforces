#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;



int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n, mx = -1;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i) {
		cin >> v[i];
		mx = max(mx, v[i]);
	}
	for(int i = 0; i < n; ++i) {
		if(v[i] != mx) continue;
		for(int j = i-1; j >= 0; --j) {
			if(v[j] > v[j+1]) {
				cout << "NO\n";
				return 0;
			}
		}
		for(int j = i+1; j < n; ++j) {
			if(v[j] > v[j-1]) {
				cout << "NO\n";
				return 0;
			}
		}
		cout << "YES\n";
		return 0;
	}
}