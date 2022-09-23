#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		map<int, int> mp;
		int N, M; scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) {
			int x; scanf("%d", &x);
			mp[x]++;
		}
		int ans = 0;
		for(int i = 1; i <= M; i++) {
			int x; scanf("%d", &x);
			if(mp[x]) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}