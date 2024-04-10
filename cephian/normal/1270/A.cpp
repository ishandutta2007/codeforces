#include <bits/stdc++.h>
using namespace std;

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, a, b, k;
		cin >> n >> a >> b;
		bool ans = true;
		for(int i = 0; i < a; ++i) {
			cin >> k;
		}
		for(int i = 0; i < b; ++i) {
			cin >> k;
			if(k == n) ans = false;
		}
		if(ans) cout << "YES\n";
		else cout << "NO\n";
	}
}