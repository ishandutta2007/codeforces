#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M;
multiset<int> A[105];
int ans[105][105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) A[i].clear();
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				int a; scanf("%d", &a);
				A[i].insert(a);
			}
		}
		for(int i = 1; i <= M; i++) {
			int mn = 1010101010, mni;
			for(int j = 1; j <= N; j++) {
				if(mn > *A[j].begin()) {
					mn = *A[j].begin();
					mni = j;
				}
			}

			for(int j = 1; j <= N; j++) {
				if(j == mni) {
					ans[j][i] = mn;
					A[j].erase(A[j].find(mn));
				}
				else {
					ans[j][i] = *(--A[j].end());
					A[j].erase(--A[j].end());
				}
			}
		}

		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) printf("%d ", ans[i][j]); puts("");
		}
	}
	return 0;
}