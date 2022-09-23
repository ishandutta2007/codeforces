#include <bits/stdc++.h>

using namespace std;

int N;
map<int, int> mp;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		mp.clear();
		scanf("%d", &N);
		int mx = 0;
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			mp[a]++;
			mx = max(mx, mp[a]);
		}
		int ans = 0;
		while(mx < N) {
			ans = ans + 1 + min(N - mx, mx);
			mx <<= 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}