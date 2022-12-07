#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector <int> a(n), b(n);
		for(int i = 0; i < n; i++) cin >> a[i];
		for(int i = 0; i < n; i++) cin >> b[i];
		long long ans = 0;
		for(int i = 0; i < n; i++) ans += a[i] + b[i];
		ans -= *max_element(b.begin(), b.end());
		cout << ans << '\n';
	}
	
	return 0;
}