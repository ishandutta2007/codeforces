#include <bits/stdc++.h>

using namespace std;

int N;
int A[303030];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		int mx = 0;
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			mx = max(mx, A[i]);
		}
		A[0] = A[N + 1] = 1010101010;
		int ans = -1;
		for(int i = 1; i <= N; i++) {
			if(A[i] == mx && (A[i] > A[i - 1] || A[i] > A[i + 1])) { ans = i; break; }
		}
		printf("%d\n", ans);
	}
	return 0;
}