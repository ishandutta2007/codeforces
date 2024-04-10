#include <bits/stdc++.h>

using namespace std;

int A[101010];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N; scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

		int mx1 = 0, mx2 = 0;
		for(int i = 1; i <= N; i++) {
			if(mx1 <= A[i]) { mx2 = mx1; mx1 = A[i]; }
			else mx2 = max(mx2, A[i]);
		}

		printf("%d\n", min(mx2 - 1, N - 2));
	}
	return 0;
}