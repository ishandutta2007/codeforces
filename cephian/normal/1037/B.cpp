#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;



int main() {	
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n, s;
	cin >> n >> s;
	vector<int> v(n);
	for(int i = 0; i < n; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());
	ll ans = abs(v[n/2] - s);
	for(int i = 0; i < n/2; ++i) {
		ans += max(0, v[i] - s);
		ans += max(0, s - v[n-1-i]);
	}
	cout << ans << "\n";

}