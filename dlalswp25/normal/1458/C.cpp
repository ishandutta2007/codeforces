#include <bits/stdc++.h>

using namespace std;

int N, M;
char S[101010];
int A[4][1010][1010];
int B[1010][1010];

struct State {
	int r = 0, c = 0, t = 0;
	int add = 0;
	int id;

	void col(int x) {
		if(t) c = (c + N + x) % N;
		else r = (r + N + x) % N;
	}
	void row(int x) {
		if(t) r = (r + N + x) % N;
		else c = (c + N + x) % N;
	}
	void all(int x) {
		add = (add + N + x) % N;
	}
	void trans() {
		t ^= 1;
	}

	void print() {
		printf("id : %d t : %d r : %d c : %d add : %d\n", id, t, r, c, add);
	}
};

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) {
			scanf("%d", &A[1][i][j]);
			A[1][i][j]--;
		}
		scanf("%s", S + 1);

		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) A[2][i][A[1][i][j]] = j;
		}
		for(int j = 0; j < N; j++) {
			for(int i = 0; i < N; i++) A[3][A[1][i][j]][j] = i;
		}

		State s1, s2, s3;
		s1.id = 1; s2.id = 2; s3.id = 3;

		for(int i = 1; i <= M; i++) {
			if(S[i] == 'R') {
				s1.row(1); s2.all(1); s3.row(1);
			}
			else if(S[i] == 'L') {
				s1.row(-1); s2.all(-1); s3.row(-1);
			}
			else if(S[i] == 'D') {
				s1.col(1); s2.col(1); s3.all(1);
			}
			else if(S[i] == 'U') {
				s1.col(-1); s2.col(-1); s3.all(-1);
			}
			else if(S[i] == 'I') {
				swap(s1, s2);
				s3.trans();
			}
			else {
				swap(s1, s3);
				s2.trans();
			}

			// s1.print();
			// s2.print();
			// s3.print();
		}

		int t = s1.id, r = s1.r, c = s1.c;

		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				A[t][i][j] = (A[t][i][j] + N + s1.add) % N;
			}
		}

		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				int x = (i + N - r) % N;
				int y = (j + N - c) % N;
				B[i][j] = A[t][x][y];
			}
		}

		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				if(!s1.t) printf("%d ", B[i][j] + 1);
				else printf("%d ", B[j][i] + 1);
			}
			puts("");
		}

		// for(int i = N - r; i < 2 * N - r; i++) {
		// 	for(int j = N - c; j < 2 * N - c; j++) {
		// 		int x = i % N, y = j % N;
		// 		B[(i - (N - r) + 1)]
		// 		if(!s1.t) printf("%d ", A[t][x][y] + 1);
		// 		else printf("%d ", A[t][y][x] + 1);
		// 	}
		// 	puts("");
		// }
	}
	return 0;
}

/*
1
4 4
2 1 4 3
4 3 1 2
1 2 3 4
3 4 2 1
RIRC

1
4 3
2 1 4 3
4 3 1 2
1 2 3 4
3 4 2 1
RIC

1
4 2
2 1 4 3
4 3 1 2
1 2 3 4
3 4 2 1
RC
*/