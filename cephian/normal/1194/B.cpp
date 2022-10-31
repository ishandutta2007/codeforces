#include <bits/stdc++.h>
using namespace std;


int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		vector<string> g(n);
		vector<int> br(n), bc(m);
		for(int i = 0;  i < n; ++i) {
			cin >> g[i];
			for(int j = 0; j < m; ++j) {
				if(g[i][j] == '.') {
					++br[i];
					++bc[j];
				}
			}
		}
		int ans = n * m;
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				int need = br[i] + bc[j];
				if(g[i][j] == '.')
					--need;
				ans = min(ans, need);
			}
		}
		cout << ans << '\n';
	}
}