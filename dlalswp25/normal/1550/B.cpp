#include <bits/stdc++.h>

using namespace std;

char S[105];
int N, A, B;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d%d", &N, &A, &B);
		scanf("%s", S + 1);
		if(B >= 0) printf("%d\n", N * (A + B));
		else {
			int x = 1;
			for(int i = 1; i < N; i++) {
				if(S[i] != S[i + 1]) x++;
			}
			printf("%d\n", N * A + B * (x / 2 + 1));
		}
	}
	return 0;
}