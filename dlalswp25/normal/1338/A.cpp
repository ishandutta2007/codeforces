#include <bits/stdc++.h>

using namespace std;

int N;
int A[101010];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		int mx = A[1];

		int ans = 0;
		for(int i = 2; i <= N; i++) {
			if(mx <= A[i]) {
				mx = A[i];
				continue;
			}
			int diff = mx - A[i];

			int c = 0;
			while(diff > 0) {
				diff >>= 1;
				c++;
			}
			ans = max(ans, c);
		}
		printf("%d\n", ans);
	}
	return 0;
}