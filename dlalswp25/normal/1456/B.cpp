#include <bits/stdc++.h>

using namespace std;

int N;
int A[101010];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

	if(N > 100) { puts("1"); return 0; }

	int ans = 10101010;
	for(int i = 1; i < N; i++) {
		int l = 0, r = 0;
		for(int j = i; j >= 1; j--) {
			l ^= A[j];
			r = 0;
			for(int k = i + 1; k <= N; k++) {
				r ^= A[k];
				if(l > r) ans = min(ans, (i - j) + (k - i - 1));
			}
		}
	}
	if(ans > N) puts("-1");
	else printf("%d\n", ans);
	return 0;
}