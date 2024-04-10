#include <bits/stdc++.h>

using namespace std;

int N;
char A[2][101010];
int D[101010];

int mex(int l, int r) {
	bool zero = false, one = false;
	for(int i = l; i <= r; i++) {
		if(A[0][i] == '0' || A[1][i] == '0') zero = true;
		if(A[0][i] == '1' || A[1][i] == '1') one = true;
	}
	if(zero && one) return 2;
	if(zero) return 1;
	return 0;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", A[0] + 1);
		scanf("%s", A[1] + 1);
		for(int i = 1; i <= N; i++) {
			D[i] = D[i - 1] + mex(i, i);
			if(i > 1) D[i] = max(D[i], D[i - 2] + mex(i - 1, i));
		}
		printf("%d\n", D[N]);
	}
	return 0;
}