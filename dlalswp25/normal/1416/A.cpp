#include <bits/stdc++.h>

using namespace std;

int N;
int A[303030];
int ans[303030];

vector<int> v[303030];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) v[i].clear();
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			v[A[i]].push_back(i);
		}
		for(int i = 1; i <= N; i++) v[i].push_back(N + 1);

		for(int i = 1; i <= N; i++) ans[i] = 0;
		int r = N + 1;

		for(int i = 1; i <= N; i++) {
			int t = 0, mx = 0;
			for(int j : v[i]) {
				mx = max(mx, j - t);
				t = j;
			}
			if(r > mx) {
				r = mx;
				ans[r] = i;
			}
		}
		int c = 0;
		for(int i = 1; i <= N; i++) {
			if(ans[i]) c = ans[i];
			if(!c) printf("-1 ");
			else printf("%d ", c);
		}
		puts("");
	}
	return 0;
}