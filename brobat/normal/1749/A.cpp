#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		for(int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
		}
		cout << (n > m ? "YES" : "NO") << '\n';
	}
	
	return 0;
}