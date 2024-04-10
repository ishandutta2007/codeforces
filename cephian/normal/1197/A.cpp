#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int T, n;
	cin >> T;
	while(T--) {
		cin >> n;
		vector<int> v(n);
		for(int& a : v)
			cin >> a;
		sort(v.rbegin(),v.rend());
		cout << max(0, min(v[1]-1, n-2)) << '\n';
	}
}