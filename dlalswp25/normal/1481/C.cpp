#include <bits/stdc++.h>

using namespace std;

int N, M;
int ans[101010];
int used;
int A[101010];
int B[101010];
int C[101010];

vector<int> X[101010];
vector<int> Y[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) {
			X[i].clear(); Y[i].clear();
		}
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= N; i++) scanf("%d", &B[i]);
		for(int i = 1; i <= M; i++) scanf("%d", &C[i]);
		for(int i = 1; i <= N; i++) {
			if(A[i] == B[i]) X[A[i]].push_back(i);
			else Y[B[i]].push_back(i);
		}
		bool ok = true;
		used = 0;
		for(int i = M; i >= 1; i--) {
			if(Y[C[i]].size()) {
				int t = Y[C[i]].back(); Y[C[i]].pop_back();
				ans[i] = t;
				used = t;
			}
			else if(!used) {
				if(X[C[i]].size()) {
					int t = X[C[i]].back();
					ans[i] = t;
					used = t;
				}
				else { ok = false; break; }
			}
			else {
				ans[i] = used;
			}
		}
		for(int i = 1; i <= N; i++) if(Y[i].size()) ok = false;
		if(!ok) puts("NO");
		else {
			puts("YES");
			for(int i = 1; i <= M; i++) printf("%d ", ans[i]); puts("");
		}
	}
	return 0;
}