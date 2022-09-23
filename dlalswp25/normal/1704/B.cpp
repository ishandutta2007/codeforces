#include <bits/stdc++.h>

using namespace std;

int N, X;
int A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &X);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		int ans = 0;
		int l = 1;
		while(l <= N) {
			ans++;
			int mx = 0, mn = 1010101010;
			for(int i = l; i <= N + 1; i++) {
				mx = max(mx, A[i]);
				mn = min(mn, A[i]);
				if(i > N || mx - mn > 2 * X) { l = i; break; }
			}
		}
		printf("%d\n", ans - 1);
	}
	return 0;
}