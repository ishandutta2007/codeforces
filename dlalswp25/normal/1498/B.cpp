#include <bits/stdc++.h>

using namespace std;

int N, W;
int A[101010];
int cnt[1010101];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &W);
		for(int i = 1; i <= N; i++) { scanf("%d", &A[i]); cnt[A[i]]++; }
		int ans = 0;

		while(1) {
			int sum = 0;
			for(int i = 1 << 19; i >= 1; i >>= 1) {
				while(cnt[i] && sum + i <= W) { cnt[i]--; sum += i; }
			}
			if(sum) ans++;
			else break;
		}
		printf("%d\n", ans);

		for(int i = 1; i <= N; i++) cnt[A[i]] = 0;
	}
	return 0;
}