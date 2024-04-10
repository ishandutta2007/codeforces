#include <bits/stdc++.h>

using namespace std;

char A[45];
char B[45];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		scanf("%s", A + 1);
		for(int i = 1; i <= N; i++) B[i] = A[i];
		sort(B + 1, B + N + 1);
		int ans = 0;
		for(int i = 1; i <= N; i++) ans += A[i] != B[i];
		printf("%d\n", ans);
	}
	return 0;
}