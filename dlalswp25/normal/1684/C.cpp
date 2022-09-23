#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) A[i].resize(M + 1);
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) scanf("%d", &A[i][j]);
		}
		int x = 0, y = 0;
		for(int i = 1; i <= N; i++) {
			if(x) break;
			vector<int> v;
			for(int j = 1; j <= M; j++) v.push_back(A[i][j]);
			sort(v.begin(), v.end());
			for(int j = 1; j <= M; j++) {
				int l = lower_bound(v.begin(), v.end(), A[i][j]) - v.begin() + 1;
				int r = upper_bound(v.begin(), v.end(), A[i][j]) - v.begin();
				if(j < l || r < j) {
					x = j;
					for(int k = l; k <= r; k++) {
						if(A[i][k] != A[i][j]) {
							y = k; break;
						}
					}
				}
				if(x) break;
			}
		}
		if(!x) { puts("1 1"); continue; }
		for(int i = 1; i <= N; i++) swap(A[i][x], A[i][y]);
		bool ok = true;
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j < M; j++) if(A[i][j] > A[i][j + 1]) ok = false;
		}
		if(!ok) puts("-1");
		else printf("%d %d\n", x, y);
	}
	return 0;
}