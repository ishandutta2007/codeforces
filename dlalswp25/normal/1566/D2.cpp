#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, M;
int A[90909];
int B[303][303];
bool chk[303][303];
vector<int> v;
vector<pii> X[90909];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		v.clear();
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N * M; i++) {
			scanf("%d", &A[i]);
			v.push_back(A[i]);
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		for(int i = 1; i <= N * M; i++) A[i] = lower_bound(v.begin(), v.end(), A[i]) - v.begin() + 1;
		v.clear();
		for(int i = 1; i <= N * M; i++) v.push_back(A[i]);
		sort(v.begin(), v.end());
		int p = 0;
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				B[i][j] = v[p++];
			}
		}

		for(int i = 1; i <= N * M; i++) X[i].clear();
		for(int i = N; i >= 1; i--) {
			for(int j = 1; j <= M; j++) {
				X[B[i][j]].emplace_back(i, j);
			}
		}

		for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) chk[i][j] = false;
		int ans = 0;
		for(int i = 1; i <= N * M; i++) {
			int x, y; tie(x, y) = X[A[i]].back(); X[A[i]].pop_back();
			for(int j = 1; j < y; j++) {
				if(chk[x][j]) ans++;
			}
			chk[x][y] = true;
		}
		printf("%d\n", ans);
	}
	return 0;
}