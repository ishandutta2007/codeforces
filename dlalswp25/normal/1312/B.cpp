#include <bits/stdc++.h>

using namespace std;

int A[105];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N; scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		sort(A + 1, A + N + 1);
		reverse(A + 1, A + N + 1);
		for(int i = 1; i <= N; i++) printf("%d ", A[i]); puts("");
	}
	return 0;
}