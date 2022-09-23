#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M;
int A[105][105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);	
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				scanf("%d", &A[i][j]);
			}
		}

		ll ans = 0;
		for(int i = 1; i <= (N + 1) / 2; i++) {
			for(int j = 1; j <= (M + 1) / 2; j++) {
				vector<int> v;
				int x = N + 1 - i, y = M + 1 - j;
				v.push_back(A[i][j]);
				if(x != i) v.push_back(A[x][j]);
				if(y != j) v.push_back(A[i][y]);
				if(x != i && y != j) v.push_back(A[x][y]);

				sort(v.begin(), v.end());
				if(v.size() == 2) ans += v[1] - v[0];
				else if(v.size() == 4) {
					ans += v[3] + v[2] - v[1] - v[0];
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}