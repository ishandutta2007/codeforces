#include <bits/stdc++.h>

using namespace std;

int A[1010][1010];
int B[1010][1010];
int C[1010][1010];
int D[1010];
int E[1010];

int N, M;
vector<int> v;

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) v.push_back(A[i][j]);
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		for(int j = 1; j <= M; j++) {
			B[i][j] = lower_bound(v.begin(), v.end(), A[i][j]) - v.begin() + 1;
			D[i] = max(D[i], B[i][j]);
		}
		v.clear();
	}
	for(int j = 1; j <= M; j++) {
		for(int i = 1; i <= N; i++) v.push_back(A[i][j]);
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		for(int i = 1; i <= N; i++) {
			C[i][j] = lower_bound(v.begin(), v.end(), A[i][j]) - v.begin() + 1;
			E[j] = max(E[j], C[i][j]);
		}
		v.clear();
	}

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			if(B[i][j] < C[i][j]) printf("%d ", max(E[j], D[i] + C[i][j] - B[i][j]));
			else printf("%d ", max(D[i], E[j] + B[i][j] - C[i][j]));
		}
		puts("");
	}

	return 0;
}