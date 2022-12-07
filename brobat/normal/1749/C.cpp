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
		for(int i = 0; i < n; i++) cin >> v[i];
		sort(v.begin(), v.end());
		int ans = 0;
		for(int k = 1; k <= n; k++) {
			// is it possible for Alice to win with this val of k?
			auto w = v;
			int done = 0;
			while(!w.empty()) {
				if(w.back() > k - done) {
					w.pop_back();
					continue;
				}
				w.pop_back();
				if(!w.empty()) w.front() += k - done;
				sort(w.begin(), w.end());
				done++;
			}
			if(done == k) ans = done;
			else break;
		}
		cout << ans << '\n';
	}
	
	return 0;
}