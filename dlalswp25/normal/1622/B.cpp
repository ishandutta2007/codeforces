#include <bits/stdc++.h>

using namespace std;

int N;
int A[202020];
int ans[202020];
char S[202020];
vector<int> V[2];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		V[0].clear(); V[1].clear();
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		scanf("%s", S + 1);
		for(int i = 1; i <= N; i++) {
			V[S[i] - '0'].push_back(A[i]);
		}
		sort(V[0].begin(), V[0].end());
		sort(V[1].begin(), V[1].end());
		int p = 1;
		for(int i : V[0]) ans[i] = p++;
		for(int i : V[1]) ans[i] = p++;
		for(int i = 1; i <= N; i++) printf("%d ", ans[A[i]]); puts("");
	}
	return 0;
}