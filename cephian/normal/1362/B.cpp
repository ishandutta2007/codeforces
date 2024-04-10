#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		bitset<1024> b;
		vector<int> S;
		for(int i = 0; i < n; ++i) {
			int s;
			cin >> s;
			S.push_back(s);
			b[s] = 1;
		}
		int ans = 5000;
		for(int i = 1; i < n; ++i) {
			int diff = S[0] ^ S[i];
			for(int j = 0; j < n; ++j) {
				if(!b[S[j] ^ diff]) {
					diff = -1;
					break;
				}
			}
			if(diff != -1) {
				ans = min(diff,ans);
			}
		}
		if(ans == 5000) ans = -1;
		cout << ans << '\n';
	}
}