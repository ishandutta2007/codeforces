#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector <int> v(n);
		for(int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		bool pos = true;
		for(int i = 1; i < n; i++) {
			if(v[i] == v[i - 1]) pos = false;
		}
		cout << (pos ? "YES" : "NO") << '\n';
	}
	
	return 0;
}