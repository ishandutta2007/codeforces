#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int t = 1;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		vector <int> v(n);
		int x = 0;
		for(int i = 0; i < n; i++) {
			cin >> v[i];
			if(v[i] == 1) x++;
		}
		cout << (x > 0 ? "YES" : "NO") << '\n';
	}
	
	return 0;
}