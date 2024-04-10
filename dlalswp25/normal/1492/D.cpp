#include <bits/stdc++.h>

using namespace std;

char X[202020];
char Y[202020];

int main() {
	int A, B, K; scanf("%d%d%d", &A, &B, &K);

	if(!K) {
		puts("Yes");
		for(int t = 0; t < 2; t++) {
			for(int i = 0; i < B; i++) printf("1");
			for(int i = 0; i < A; i++) printf("0"); puts("");
		}
		return 0;
	}
	if(B == 1 || A == 0) { puts("No"); return 0; }
	if(K >= A + B - 1) { puts("No"); return 0; }
	puts("Yes");
	X[1] = Y[1] = '1';
	X[A + B] = '0';
	Y[A + B] = '1';
	X[A + B - K] = '1';
	Y[A + B - K] = '0';
	int ta = A - 1, tb = B - 2;
	for(int i = 2; i <= A + B; i++) {
		if(X[i]) continue;
		if(ta) { X[i] = Y[i] = '0'; ta--; }
		else { X[i] = Y[i] = '1'; tb--; }
	}
	printf("%s\n", X + 1);
	printf("%s\n", Y + 1);

	return 0;
}