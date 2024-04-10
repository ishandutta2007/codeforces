#include <bits/stdc++.h>

using namespace std;

int cnt[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		for(int i = 0; i <= 100; i++) cnt[i] = 0;
		int N; scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			cnt[a]++;
		}

		int ans = 0;
		for(int i = 0; i <= N; i++) {
			if(cnt[i] < 2) {
				ans += i;
				break;
			}
		}
		for(int i = 0; i <= N; i++) {
			if(cnt[i] < 1) {
				ans += i;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}