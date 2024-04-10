#include <bits/stdc++.h>

using namespace std;

int D[252][252][252];
char S[201010];
int N, Q;
int nxt[201010][30];
vector<int> idx[30];
vector<char> A, B, C;

int f(int a, int b, int c, char x) {
	return nxt[D[a][b][c]][x - 'a'];
}

int main() {
	scanf("%d%d", &N, &Q);
	int M = N;
	scanf("%s", S + 1);
	for(int j = 0; j < 1000; j++) {
		for(int i = 'a'; i <= 'z'; i++) {
			S[++N] = i;
		}
	}

	D[0][0][0] = 0;
	A.push_back(0);
	B.push_back(0);
	C.push_back(0);

	for(int i = 0; i < 26; i++) idx[i].push_back(0);

	for(int i = 1; i <= N; i++) {
		while(idx[S[i] - 'a'].size()) {
			nxt[idx[S[i] - 'a'].back()][S[i] - 'a'] = i;
			idx[S[i] - 'a'].pop_back();
		}

		for(int j = 0; j < 26; j++) {
			idx[j].push_back(i);
		}
	}
	for(int i = 0; i < 26; i++) {
		while(idx[i].size()) {
			nxt[idx[i].back()][i] = N + 1;
			idx[i].pop_back();
		}
	}

	// for(int i = 1; i <= M; i++) {
	// 	for(int j = 0; j < 26; j++) {
	// 		printf("%d ", nxt[i][j]);
	// 	}
	// 	puts("");
	// }

	int a = 0, b = 0, c = 0;

	for(int q = 1; q <= Q; q++) {
		char t;
		scanf(" %c", &t);

		if(t == '+') {
			int x; char ch;
			scanf("%d %c", &x, &ch);

			if(x == 1) {
				a++;
				A.push_back(ch);
				D[a][0][0] = f(a - 1, 0, 0, A[a]);
				for(int i = 1; i <= b; i++) D[a][i][0] = min(f(a - 1, i, 0, A[a]), f(a, i - 1, 0, B[i]));
				for(int i = 1; i <= c; i++) D[a][0][i] = min(f(a - 1, 0, i, A[a]), f(a, 0, i - 1, C[i]));
				for(int i = 1; i <= b; i++) {
					for(int j = 1; j <= c; j++) {
						D[a][i][j] = min(f(a - 1, i, j, A[a]), min(f(a, i - 1, j, B[i]), f(a, i, j - 1, C[j])));
					}
				}
			}
			else if(x == 2) {
				b++;
				B.push_back(ch);
				D[0][b][0] = f(0, b - 1, 0, B[b]);
				for(int i = 1; i <= a; i++) D[i][b][0] = min(f(i, b - 1, 0, B[b]), f(i - 1, b, 0, A[i]));
				for(int i = 1; i <= c; i++) D[0][b][i] = min(f(0, b - 1, i, B[b]), f(0, b, i - 1, C[i]));
				for(int i = 1; i <= a; i++) {
					for(int j = 1; j <= c; j++) {
						D[i][b][j] = min(f(i - 1, b, j, A[i]), min(f(i, b - 1, j, B[b]), f(i, b, j - 1, C[j])));
					}
				}
			}
			else {
				c++;
				C.push_back(ch);
				D[0][0][c] = f(0, 0, c - 1, C[c]);
				for(int i = 1; i <= a; i++) D[i][0][c] = min(f(i - 1, 0, c, A[i]), f(i, 0, c - 1, C[c]));
				for(int i = 1; i <= b; i++) D[0][i][c] = min(f(0, i - 1, c, B[i]), f(0, i, c - 1, C[c]));
				for(int i = 1; i <= a; i++) {
					for(int j = 1; j <= b; j++) {
						D[i][j][c] = min(f(i - 1, j, c, A[i]), min(f(i, j - 1, c, B[j]), f(i, j, c - 1, C[c])));
					}
				}
			}
		}
		else {
			int x; scanf("%d", &x);
			if(x == 1) {
				A.pop_back();
				a--;
			}
			else if(x == 2) {
				B.pop_back();
				b--;
			}
			else {
				C.pop_back();
				c--;
			}
		}
		// printf("%d %d %d\n", a, b, c);
		// for(int i = 0; i <= a; i++) {
		// 	for(int j = 0; j <= b; j++) {
		// 		for(int k = 0; k <= c; k++) {
		// 			printf("%d %d %d %d\n", i, j, k, D[i][j][k]);
		// 		}
		// 	}
		// }
		if(D[a][b][c] <= M) puts("YES");
		else puts("NO");
	}

	return 0;
}