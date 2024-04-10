#include <bits/stdc++.h>

using namespace std;

int A[202020];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N; scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

		sort(A + 1, A + N + 1);

		int ans = 0;
		for(int i = 1; i <= N; i++) {
			if(i >= A[i]) ans = i;
		}
		printf("%d\n", ans + 1);
	}
	return 0;
}