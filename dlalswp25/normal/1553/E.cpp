#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[303030];
int B[303030];
int X[303030];
int cnt[303030];
int pos[303030];

void sw(int i, int j) {
	int x = B[i], y = B[j];
	swap(pos[x], pos[y]);
	swap(B[i], B[j]);
}

bool chk(int k) {
	// printf("k %d\n", k);
	for(int i = 1; i <= N; i++) {
		A[i] = (i + N - k - 1) % N + 1;
	}
	for(int i = 1; i <= N; i++) {
		B[i] = X[i];
		pos[B[i]] = i;
	}

	int c = 0;
	for(int i = 1; i <= N; i++) {
		if(A[i] != B[i]) {
			int j = pos[A[i]];
			sw(i, j); c++;
		}
	}
	if(c > M) return false;
	return true;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 0; i < N; i++) cnt[i] = 0;
		for(int i = 1; i <= N; i++) {
			scanf("%d", &X[i]);
			cnt[(i + N - X[i]) % N]++;
		}

		vector<int> ans;
		for(int i = 0; i < N; i++) {
			if(cnt[i] < N - 2 * M) continue;
			if(chk(i)) ans.push_back(i);
		}
		printf("%d ", ans.size());
		for(int i : ans) printf("%d ", i); puts("");
	}
	return 0;
}