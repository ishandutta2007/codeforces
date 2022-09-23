#include <bits/stdc++.h>

using namespace std;

int N;
int cnt[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		for(int i = 0; i <= 100; i++) cnt[i] = 0;
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			cnt[abs(a)]++;
		}
		int ans = min(cnt[0], 1);
		for(int i = 1; i <= 100; i++) {
			ans += min(cnt[i], 2);
		}
		printf("%d\n", ans);
	}
	return 0;
}