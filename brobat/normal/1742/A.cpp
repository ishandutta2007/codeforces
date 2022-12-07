#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int t;
	cin >> t;
	while(t--) {
		vector <int> v(3);
		for(int i = 0; i < 3; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		cout << (v[2] == v[1] + v[0] ? "YES" : "NO") << '\n';
	}
	
	return 0;
}