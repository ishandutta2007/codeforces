#include <bits/stdc++.h>

using namespace std;

int N;
char S[2020];
int D[2020][2020];

int f(int l, int r, char a, char b) {
	if(D[l][r] == 1) return 1;
	if(D[l][r] == -1) return -1;
	return a < b ? 1 : (a == b ? 0 : -1);
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%s", S + 1);
		N = strlen(S + 1);
		for(int i = 1; i < N; i++) {
			if(S[i] == S[i + 1]) D[i][i + 1] = 0;
			else D[i][i + 1] = 1;
		}
		for(int i = 3; i < N; i += 2) {
			for(int j = 1; i + j <= N; j++) {
				int l = j, r = i + j;
				D[l][r] = -1;

				int x = 1;
				x = min(x, f(l + 2, r, S[l], S[l + 1]));
				x = min(x, f(l + 1, r - 1, S[l], S[r]));
				D[l][r] = max(D[l][r], x);

				x = 1;
				x = min(x, f(l, r - 2, S[r], S[r - 1]));
				x = min(x, f(l + 1, r - 1, S[r], S[l]));
				D[l][r] = max(D[l][r], x);
			}
		}
		puts(D[1][N] == 1 ? "Alice" : (D[1][N] == 0 ? "Draw" : "Bob"));
	}
	return 0;
}