#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
pii A[202020];
int B[202020];
int ans[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i].first);
			A[i].second = i;
		}
		sort(A + 1, A + N + 1);
		int c = 1, mx = 1;
		for(int i = 2; i <= N; i++) {
			if(A[i].first == A[i - 1].first) c++;
			else c = 1;
			mx = max(mx, c);
		}
		for(int i = 1; i <= N; i++) {
			B[(i + mx - 1) % N + 1] = A[i].first;
		}
		for(int i = 1; i <= N; i++) A[i].first = B[i];
		for(int i = 1; i <= N; i++) ans[A[i].second] = A[i].first;
		for(int i = 1; i <= N; i++) printf("%d ", ans[i]); puts("");
	}
	return 0;
}