#include <bits/stdc++.h>

using namespace std;

int N;
int A[101010];
int B[101010];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	sort(A + 1, A + N + 1);

	int idx = 1;
	for(int i = 2; i <= N; i += 2) {
		B[i] = A[idx++];
	}
	for(int i = 1; i <= N; i += 2) {
		B[i] = A[idx++];
	}

	int ans = 0;
	for(int i = 2; i < N; i++) {
		if(B[i] < B[i - 1] && B[i] < B[i + 1]) ans++;
	}
	printf("%d\n", ans);
	for(int i = 1; i <= N; i++) printf("%d ", B[i]); puts("");

	return 0;
}