#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int t;
	cin >> t;
	while(t--) {
		int n = 8;
		vector<vector<char>> v(n, vector<char>(n));
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cin >> v[i][j];
			}
		}
		bool red = false;
		for(int i = 0; i < n; i++) {
			int cnt = 0;
			for(int j = 0; j < n; j++) {
				if(v[i][j] == 'R') cnt++;
			}
			if(cnt == n) red = true;
		}
		cout << (red ? "R" : "B") << '\n';
	}
	
	return 0;
}