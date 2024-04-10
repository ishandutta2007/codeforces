#include <bits/stdc++.h>

using namespace std;

int A[303030];
vector<int> B[20];
int N, Q;
vector<int> adj[303030];
int mn[303030][20];

int main() {
	scanf("%d%d", &N, &Q);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

	for(int i = 0; i <= 19; i++) {
		for(int j = 1; j <= N; j++) {
			if(A[j] & (1 << i)) {
				if(B[i].size()) adj[B[i].back()].push_back(j);
				B[i].push_back(j);
			}
		}
	}

	// for(int i = 1; i <= N; i++) {
	// 	for(int j : adj[i]) printf("%d ", j); puts("");
	// }

	for(int i = N; i >= 1; i--) {
		for(int j = 0; j <= 19; j++) {
			if(A[i] & (1 << j)) mn[i][j] = i;
			else mn[i][j] = N + 1;
		}

		for(int j : adj[i]) {
			for(int k = 0; k <= 19; k++) mn[i][k] = min(mn[i][k], mn[j][k]);
		}
	}

	for(int i = 1; i <= Q; i++) {
		int l, r; scanf("%d%d", &l, &r);
		bool ok = false;
		for(int j = 0; j <= 19; j++) {
			if(!(A[r] & (1 << j))) continue;
			if(mn[l][j] <= r) ok = true;
		}
		if(ok) puts("Shi");
		else puts("Fou");
	}

	return 0;
}