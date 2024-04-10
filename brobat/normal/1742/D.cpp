#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int t;
	cin >> t;
	while(t--) {
		int N = 1005;
		int p[N];
		for(int i = 0; i < N; i++) {
			p[i] = -1000000000;
		}
		int n;
		cin >> n;
		vector <int> one;
		for(int i = 0; i < n; i++) {
			int x;
			cin >> x;
			p[x] = i + 1;
		}
		int ans = -1;
		for(int i = 1; i < N; i++) {
			for(int j = 1; j <= i; j++) {
				if(__gcd(i, j) == 1) {
					ans = max(ans, p[i] + p[j]);
				}
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}