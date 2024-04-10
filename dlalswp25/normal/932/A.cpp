#include <stdio.h>

char A[1005];

int main() {
	scanf("%s", A);
	int N = 0;
	for(int i = 0; A[i]; i++) {
		N++; printf("%c", A[i]);
	}
	for(int i = N - 1; i >= 0; i--) {
		printf("%c", A[i]);
	}
	return 0;
}