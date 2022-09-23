#include <bits/stdc++.h>

using namespace std;

int N;
int A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		int mn = N, mx = 0;
		for(int i = 1; i < N; i++) {
			if(A[i] == A[i + 1]) {
				mn = min(mn, i);
				mx = max(mx, i);
			}
		}
		if(mn == N || mn == mx) { puts("0"); continue; }
		if(mn + 1 == mx) puts("1");
		else printf("%d\n", mx - mn - 1);
	}
	return 0;
}