#include <bits/stdc++.h>

using namespace std;

char S[101010];
char T[101010];

int nxt[30][101010];
int bef;

int N, M;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%s", S + 1);
		scanf("%s", T + 1);

		N = strlen(S + 1); M = strlen(T + 1);

		for(int i = 0; i < 26; i++) {
			bef = 0;
			for(int j = 1; j <= N; j++) {
				if(S[j] != i + 'a') continue;
				for(int k = bef; k < j; k++) nxt[i][k] = j;
				bef = j;
			}
			for(int k = bef; k <= N; k++) nxt[i][k] = N + 1;
		}

		int p = 0;
		int ans = 1;
		int cnt = 0;
		for(int i = 1; i <= M; i++) {
			p = nxt[T[i] - 'a'][p];
			// printf("%d %d\n", i, p);
			if(p == N + 1) {
				ans++; p = 0;
				i--; cnt++;
				if(cnt > 1) { ans = -1; break; }
			}
			else cnt = 0;
		}
		printf("%d\n", ans);

		for(int i = 0; i < 26; i++) for(int j = 1; j <= N; j++) nxt[i][j] = 0;
	}
	return 0;
}