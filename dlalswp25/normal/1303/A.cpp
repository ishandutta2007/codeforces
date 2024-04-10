#include <bits/stdc++.h>

using namespace std;

char S[105];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%s", S + 1);
		int N = strlen(S + 1);
		int z = 0;
		for(int i = 1; i <= N; i++) if(S[i] == '0') z++;
		if(z == N) { puts("0"); continue; }
		for(int i = 1; i <= N; i++) {
			if(S[i] == '1') break;
			z--;
		}
		for(int i = N; i >= 1; i--) {
			if(S[i] == '1') break;
			z--;
		}
		printf("%d\n", z);
	}
	return 0;
}