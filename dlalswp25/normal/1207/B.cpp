#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int A[55][55];
int B[55][55];

int N, M;

vector<pii> v;

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	for(int i = 1; i < N; i++) {
		for(int j = 1; j < M; j++) {
			if(A[i][j] && A[i + 1][j] && A[i][j + 1] && A[i + 1][j + 1]) {
				v.push_back({i, j});
				B[i][j] = B[i + 1][j] = B[i][j + 1] = B[i + 1][j + 1] = 1;
			}
		}
	}

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			if(A[i][j] != B[i][j]) { puts("-1"); return 0; }
		}
	}
	printf("%d\n", v.size());
	for(pii i : v) printf("%d %d\n", i.first, i.second);

	return 0;
}