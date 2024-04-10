#include <bits/stdc++.h>

using namespace std;

char S[202020];
int N, K;

int main() {
	scanf("%d%d", &N, &K);
	scanf("%s", S + 1);

	int t = 0;
	for(int i = K + 1; i <= N; i++) {
		if(t != 0) break;
		if(S[i] < S[(i - 1) % K + 1]) t = 1;
		if(S[i] > S[(i - 1) % K + 1]) t = -1;
	}

	if(t >= 0) {
		printf("%d\n", N);
		for(int i = 1; i <= N; i++) printf("%c", S[(i - 1) % K + 1]);
		puts("");
		return 0;
	}

	S[K]++;

	for(int i = K; i >= 1; i--) {
		if(S[i] <= '9') break;
		S[i] = '0'; S[i - 1]++;
	}

	if(S[0] > 0) {
		printf("%d\n", N + 1);
		for(int i = 1; i <= N + 1; i++) {
			if(i % K == 1) printf("1");
			else printf("0");
		}
		puts("");
		return 0;
	}

	printf("%d\n", N);
	for(int i = 1; i <= N; i++) printf("%c", S[(i - 1) % K + 1]); puts("");

	return 0;
}