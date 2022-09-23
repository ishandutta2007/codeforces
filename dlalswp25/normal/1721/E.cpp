#include <bits/stdc++.h>

using namespace std;

int N, M, Q;
char S[1010101];
int fail[1010101];
char T[15];
int nxt[1010101][26];

int main() {
	scanf("%s", S + 1);
	N = strlen(S + 1);
	int p = 0;
	for(int i = 2; i <= N; i++) {
		while(p && S[p + 1] != S[i]) p = fail[p];
		if(S[p + 1] == S[i]) p++;
		fail[i] = p;
	}

	nxt[0][S[1] - 'a'] = 1;
	for(int i = 1; i <= N; i++) {
		for(int j = 0; j < 26; j++) {
			if(S[i + 1] == j + 'a') nxt[i][j] = i + 1;
			else nxt[i][j] = nxt[fail[i]][j];
		}
	}

	scanf("%d", &Q);
	while(Q--) {
		scanf("%s", T + 1);
		M = strlen(T + 1);
		int p = fail[N];
		for(int i = 1; i <= M; i++) {
			p = nxt[p][T[i] - 'a'];
			printf("%d ", p);
			fail[N + i] = p;
			for(int j = 0; j < 26; j++) {
				if(T[i] == j + 'a') nxt[N + i - 1][j] = N + i;
				else nxt[N + i - 1][j] = nxt[fail[N + i - 1]][j];
			}
		}
		puts("");
	}
	return 0;
}