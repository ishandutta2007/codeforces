#include <bits/stdc++.h>

using namespace std;

int N;
int A[202020];
int L[202020];
int R[202020];

int main() {
	int tc = 1;
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) { L[i] = N + 1; R[i] = 0; }
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			L[A[i]] = min(L[A[i]], i);
			R[A[i]] = max(R[A[i]], i);
		}

		int ans = 0;
		int l = 1;
		while(l <= N) {
			int r = R[A[l]];
			ans++;
			if(l == r) { l = r + 1; continue; }
			int t = l;
			while(1) {
				ans++;
				int nxt_r = r;
				for(int i = t; i <= r; i++) {
					nxt_r = max(nxt_r, R[A[i]]);
				}
				if(nxt_r <= r) { l = r + 1; break; }
				t = r + 1; r = nxt_r;
			}
		}
		printf("%d\n", N - ans);
	}
	return 0;
}