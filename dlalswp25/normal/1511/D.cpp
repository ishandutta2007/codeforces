#include <bits/stdc++.h>

using namespace std;

char S[1010];

int main() {
	int N, K; scanf("%d%d", &N, &K);
	S[0] = 'a';
	int p = 1;
	for(int i = 1; i < K; i++) {
		S[p++] = 'a' + i;
		for(int j = i - 1; j >= 0; j--) {
			S[p++] = 'a' + i;
			S[p++] = 'a' + j;
		}
	}

	int q = 0;
	printf("a");
	for(int i = 1; i < N; i++) {
		printf("%c", S[q++]);
		if(q >= p) q -= p;
	}
	puts("");

	return 0;
}