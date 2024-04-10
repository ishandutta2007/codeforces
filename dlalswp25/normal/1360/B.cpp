#include <bits/stdc++.h>

using namespace std;

int A[55];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N; scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		sort(A + 1, A + N + 1);
		int ans = 1010101010;
		for(int i = 1; i < N; i++) ans = min(ans, A[i + 1] - A[i]);
		printf("%d\n", ans);
	}
	return 0;
}