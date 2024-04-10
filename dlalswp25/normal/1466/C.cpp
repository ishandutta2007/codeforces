#include <bits/stdc++.h>

using namespace std;

char A[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%s", A + 1);
		int N = strlen(A + 1);
		A[N + 2] = A[N + 3] = 0;
		int ans = 0;
		for(int i = 1; i <= N; i++) {
			if(A[i] == A[i - 1] || (i > 1 && A[i] == A[i - 2])) {
				ans++;
				A[i] = 'A';
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}