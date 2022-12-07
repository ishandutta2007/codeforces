#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int t = 1;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		deque <int> o, z;
		for(int i = 0; i < n; i++) {
			int x; cin >> x;
			if(x == 1) o.push_back(i);
			else z.push_back(i);
		}
		reverse(z.begin(), z.end());
		int ans = 0;
		while(!o.empty() && !z.empty()) {
			int x = o.front();
			int y = z.front();
			o.pop_front();
			z.pop_front();
			if(x < y) ans++;
		}
		cout << ans << '\n';
	}
	
	return 0;
}