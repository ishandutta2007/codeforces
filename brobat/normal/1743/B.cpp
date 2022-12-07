#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int t = 1;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cout << "1 " << n << " ";
		for(int i = 2; i < n; i++) cout << i << ' ';
		cout << '\n';
	}
	
	return 0;
}