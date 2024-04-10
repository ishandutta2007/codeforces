#include <bits/stdc++.h>

using namespace std;

const int M = 52;

int N;
char S[15][202];
int A[15][202];
int B[15][202];
int len[15];
int loc[15][55][2];
int cnt[55];
int D[55][1050];
int pathX[55][1050];
int pathY[55][1050];
int pos[15];
int nxt[55];
bool ok[55];

int f(int x, int y) {
	int& ret = D[x][y];
	if(ret != -2) return ret;
	for(int i = 0; i < N; i++) {
		pos[i] = loc[i][x][y >> i & 1];
		if(!pos[i]) return ret = -1;
	}

	ret = 1; pathX[x][y] = pathY[x][y] = 0;

	for(int i = 1; i <= M; i++) nxt[i] = cnt[i] = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 1; j <= M; j++) ok[j] = false;
		for(int j = 1; j < pos[i]; j++) {
			ok[A[i][j]] = true;
			nxt[A[i][j]] |= B[i][j] << i;
		}
		for(int j = 1; j <= M; j++) if(ok[j]) cnt[j]++;
	}

	// for(int i = 0; i < N; i++) printf("%d ", pos[i]); puts("");
	// for(int i = 1; i <= M; i++) printf("%d ", cnt[i]); puts("");
	int tmp[55];
	int tmp2[55];
	for(int i = 1; i <= M; i++) tmp[i] = nxt[i];
	for(int i = 1; i <= M; i++) tmp2[i] = cnt[i];

	for(int i = 1; i <= M; i++) {
		if(tmp2[i] < N) continue;
		int t = f(i, tmp[i]) + 1;
		if(t > ret) {
			ret = t;
			pathX[x][y] = i;
			pathY[x][y] = tmp[i];
		}
	}

	return ret;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 0; i < N; i++) {
			scanf("%s", S[i] + 1);
			len[i] = strlen(S[i] + 1);
			for(int j = 1; j <= len[i]; j++) {
				if(S[i][j] <= 'Z') A[i][j] = S[i][j] - 'A' + 1;
				else A[i][j] = S[i][j] - 'a' + 27;
			}
		}

		for(int i = 0; i < N; i++) for(int j = 1; j <= M; j++) {
			loc[i][j][0] = loc[i][j][1] = 0;
		}

		for(int i = 0; i < N; i++) {
			for(int j = 1; j <= M; j++) cnt[j] = 0;
			for(int j = 1; j <= len[i]; j++) {
				B[i][j] = cnt[A[i][j]];
				loc[i][A[i][j]][cnt[A[i][j]]] = j;
				cnt[A[i][j]]++;
			}
		}

		for(int i = 1; i <= M; i++) {
			for(int j = 0; j < 1 << N; j++) D[i][j] = -2;
		}
		for(int i = 1; i <= M; i++) {
			for(int j = 0; j < 1 << N; j++) f(i, j);
		}

		int ans = -1, x, y;
		for(int i = 1; i <= M; i++) {
			for(int j = 0; j < 1 << N; j++) {
				if(ans < D[i][j]) {
					ans = D[i][j];
					x = i; y = j;
				}
			}
		}

		if(ans <= 0) puts("0");
		else {
			vector<char> str;
			while(x) {
				str.push_back(x);
				int nx = pathX[x][y], ny = pathY[x][y];
				x = nx; y = ny;
			}
			reverse(str.begin(), str.end());
			printf("%d\n", str.size());
			for(int i : str) {
				if(i <= 26) printf("%c", 'A' + i - 1);
				else printf("%c", 'a' + i - 27);
			}
			puts("");
		}
	}
	return 0;
}