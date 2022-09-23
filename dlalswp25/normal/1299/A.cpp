#include <bits/stdc++.h>

using namespace std;

int A[101010];
int N;

int L[101010];
int R[101010];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

	for(int i = 1; i <= N; i++) L[i] = L[i - 1] | A[i];
	for(int i = N; i >= 1; i--) R[i] = R[i + 1] | A[i];

	int mx = -1, mxi;
	for(int i = 1; i <= N; i++) {
		int t = L[i - 1] | R[i + 1];
		if(mx < (A[i] & (~t))) {
			mx = A[i] & (~t);
			mxi = i;
		}
	}
	printf("%d ", A[mxi]);
	for(int i = 1; i <= N; i++) if(i != mxi) printf("%d ", A[i]); puts("");
	return 0;
}