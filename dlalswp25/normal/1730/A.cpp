#include <bits/stdc++.h>

using namespace std;

int N, C;
int cnt[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		for(int i = 0; i <= 100; i++) cnt[i] = 0;
		scanf("%d%d", &N, &C);
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			cnt[a]++;
		}
		int ans = 0;
		for(int i = 0; i <= 100; i++) ans += min(cnt[i], C);
		printf("%d\n", ans);
	}
	return 0;
}