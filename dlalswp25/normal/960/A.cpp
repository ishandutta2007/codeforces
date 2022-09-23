#include <stdio.h>

char S[5005];
int A, B, C;

int main() {
	scanf("%s", S);
	int N = 0; for(N = 0; S[N]; N++);
	if(S[0] != 'a') {
		puts("NO"); return 0;
	}
	A++;
	for(int i = 1; i < N; i++) {
		if(S[i] != S[i - 1]) {
			if(S[i] != S[i - 1] + 1) {
				puts("NO"); return 0;
			}
		}
		if(S[i] == 'a') A++;
		if(S[i] == 'b') B++;
		if(S[i] == 'c') C++;
	}
	if((A != C && B != C) || !A || !B) {
		puts("NO"); return 0;
	}
	puts("YES");
	return 0;
}