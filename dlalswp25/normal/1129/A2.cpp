#include <bits/stdc++.h>

using namespace std;

int A[20202];
int B[20202];

vector<int> G[5050];
int N, M;

int dst(int i, int j) {
	if(j < i) return j + N - i;
	return j - i;
}

int main() {
	scanf("%d%d", &N, &M);
	int mx = 0;
	for(int i = 1; i <= M; i++) {
		scanf("%d%d", &A[i], &B[i]);
		G[A[i]].push_back(B[i]);
	}

	for(int i = 1; i <= N; i++) {
		int ans = 0;
		for(int j = 1; j <= N; j++) {
			if(G[j].size() == 0) continue;
			int mn = 987654321;
			for(int k : G[j]) {
				mn = min(mn, dst(j, k));
			}
			ans = max(ans, ((int)G[j].size() - 1) * N + dst(i, j) + mn);
		}
		printf("%d ", ans);
	}
	puts("");
	return 0;
}