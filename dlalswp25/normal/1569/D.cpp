#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M, K;
vector<int> vx[202020];
vector<int> vy[202020];
int X[202020];
int Y[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d%d", &N, &M, &K);
		for(int i = 1; i < N; i++) vx[i].clear();
		for(int i = 1; i < M; i++) vy[i].clear();
		for(int i = 1; i <= N; i++) scanf("%d", &X[i]);
		for(int i = 1; i <= M; i++) scanf("%d", &Y[i]);
		X[N + 1] = 1000000;
		Y[M + 1] = 1000000;
		for(int i = 1; i <= K; i++) {
			int x, y; scanf("%d%d", &x, &y);
			int tx = upper_bound(X + 1, X + N + 1, x) - X - 1;
			int ty = upper_bound(Y + 1, Y + M + 1, y) - Y - 1;
			if(X[tx] == x && Y[ty] == y) continue;
			if(X[tx] == x) {
				vy[ty].push_back(x);
			}
			else {
				vx[tx].push_back(y);
			}
		}

		ll ans = 0;
		for(int i = 1; i < N; i++) {
			sort(vx[i].begin(), vx[i].end());
			int b = 0;
			for(int j = 0; j < vx[i].size(); j++) {
				if(j && vx[i][j] != vx[i][j - 1]) b = j;
				ans += b;
			}
		}
		for(int i = 1; i < M; i++) {
			sort(vy[i].begin(), vy[i].end());
			int b = 0;
			for(int j = 0; j < vy[i].size(); j++) {
				if(j && vy[i][j] != vy[i][j - 1]) b = j;
				ans += b;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}