#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target ("sse,sse2,sse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;



int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> v(n), u;
	for(int i = 0; i < n; ++i) {
		cin >> v[i];
		if(i) {
			u.push_back(v[i] - v[i-1]);
		}
	}
	sort(u.rbegin(), u.rend());
	int ans = 0;
	for(int i = k-1; i < (int)u.size(); ++i)
		ans += u[i];
	cout << ans << '\n';
}