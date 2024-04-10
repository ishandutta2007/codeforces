#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for(int i = 0; i < n; i++) {
			cin >> v[i];
		}
		int curr = 0;
		for(int i = 0; i < min(n, 30); i++) {
			int temp = curr;
			int ind = i;
			for(int j = i; j < n; j++) {
				if(temp < (curr | v[j])) {
					temp = curr | v[j];
					ind = j;
				}
			}
			swap(v[ind], v[i]);
			curr = temp;
		}
		for(int i = 0; i < n; i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}