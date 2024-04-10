#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[5][1010101];

char S[1010101];

int main() {
	scanf("%d%d", &N, &M);

	if(min(N, M) >= 4) { puts("-1"); return 0; }

	for(int i = 1; i <= N; i++) {
		scanf("%s", S + 1);
		if(N > M) {
			for(int j = 1; j <= M; j++) {
				A[j][i] = S[j] - '0';
			}
		}
		else {
			for(int j = 1; j <= M; j++) {
				A[i][j] = S[j] - '0';
			}
		}
	}

	if(N > M) swap(N, M);
	if(N == 1) { puts("0"); return 0; }
	if(N == 2) {
		int o = 0, e = 0;
		for(int i = 1; i <= M; i++) {
			int s = A[1][i] + A[2][i];
			if(i & 1) {
				if(~s & 1) o++;
				else e++;
			}
			else {
				if(s & 1) o++;
				else e++;
			}
		}
		printf("%d\n", min(o, e));
		return 0;
	}

	int ans = 1010101010;
	for(int i = 0; i < 4; i++) {

		int tmp = 0;
		for(int j = 1; j <= M; j++) {
			int s1 = A[1][j] + A[2][j] & 1;
			int s2 = A[2][j] + A[3][j] & 1;

			int t = s1 << 1 | s2;
			if(j & 1) {
				if(i != t) tmp++;
			}
			else {
				if(i != (3 - t)) tmp++;
			}
		}
		ans = min(ans, tmp);
	}
	printf("%d\n", ans);

	return 0;
}