#include <bits/stdc++.h>

using namespace std;

int N, Q;
char A[202020];
int S0[202020];
int S1[202020];

int main() {
	scanf("%d%d", &N, &Q);
	scanf("%s", A + 1);
	for(int i = 1; i < N; i++) {
		S0[i] = S0[i - 1] + (A[i] == '0' && A[i + 1] == '0');
		S1[i] = S1[i - 1] + (A[i] == '1' && A[i + 1] == '1');
	}
	while(Q--) {
		int l, r; scanf("%d%d", &l, &r);
		int t = max(S0[r - 1] - S0[l - 1], S1[r - 1] - S1[l - 1]);
		printf("%d\n", t + 1);
	}
	return 0;
}