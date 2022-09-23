#include <bits/stdc++.h>

using namespace std;

int A[55];
int cnt[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		for(int i = 1; i <= 2 * N; i++) cnt[i] = 0;
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			cnt[A[i]]++;
		}

		int ans = 0;
		for(int i = 2; i <= 2 * N; i++) {
			int s = 0;
			for(int j = 1; 2 * j < i; j++) {
				s += min(cnt[j], cnt[i - j]);
			}
			if(i % 2 == 0) s += cnt[i / 2] / 2;
			ans = max(ans, s);
		}
		printf("%d\n", ans);
	}
	return 0;
}