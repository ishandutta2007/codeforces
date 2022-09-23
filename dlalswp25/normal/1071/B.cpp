#include <bits/stdc++.h>

using namespace std;

char C[2005][2005];
int D[2005][2005];
bool B[2005][2005];
vector<char> ans;

int main() {
	int N, K; scanf("%d%d", &N, &K);
	for(int i = 1; i <= N; i++) {
		scanf("%s", C[i] + 1);
	}
	for(int i = 1; i <= N; i++) D[0][i] = D[i][0] = 987654321;
	D[0][1] = 0;

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			D[i][j] = min(D[i - 1][j], D[i][j - 1]) + (C[i][j] != 'a');
		}
	}
	/*
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			printf("%d ", D[i][j]);
		}
		puts("");
	}*/

	int m = 1;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(D[i][j] <= K) m = max(m, i + j);
		}
	}
	for(int i = 2; i <= m; i++) ans.push_back('a');
	B[0][1] = true;

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if(D[i][j] <= K && i + j == m) {
				B[i][j] = true;
			}
		}
	}
	for(int i = m + 1; i <= 2 * N; i++) {
		char c = 'z';
		for(int k = 1; k <= N; k++) {
			int x = k, y = i - x;
			if(y <= 0 || y > N) continue;

			if(!B[x - 1][y] && !B[x][y - 1]) continue;
			c = min(c, C[x][y]);
		}
		for(int k = 1; k <= N; k++) {
			int x = k, y = i - x;
			if(y <= 0 || y > N) continue;
			if(!B[x - 1][y] && !B[x][y - 1]) continue;

			if(C[x][y] == c) B[x][y] = true;
		}
		ans.push_back(c);
	}
	for(char i : ans) printf("%c", i); puts("");
	return 0;
}