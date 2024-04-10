#include <bits/stdc++.h>

using namespace std;

int bef[202020];
int cnt[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		for(int i = 1; i <= N; i++) bef[i] = cnt[i] = 0;
		for(int i = 1; i <= N; i++) {
			int x; scanf("%d", &x);
			if(bef[x] != i - 1) cnt[x]++;
			bef[x] = i;
		}
		for(int i = 1; i <= N; i++) if(bef[i] > 0 && bef[i] != N) cnt[i]++;
		int ans = N;
		for(int i = 1; i <= N; i++) if(bef[i] > 0) ans = min(ans, cnt[i]);
		printf("%d\n", ans);
	}
	return 0;
}