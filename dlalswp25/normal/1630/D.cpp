#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M;
int A[1010101];
vector<int> V[1010101];

int gcd(int a, int b) { while(b) { a %= b; swap(a, b); } return a; }

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		int g = 0;
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= M; i++) {
			int b; scanf("%d", &b);
			g = gcd(g, b);
		}
		for(int i = 0; i < g; i++) V[i].clear();
		for(int i = 1; i <= N; i++) {
			V[(i - 1) % g].push_back(A[i]);
		}
		for(int i = 0; i < g; i++) sort(V[i].begin(), V[i].end());
		ll sum = 0;
		for(int i = 1; i <= N; i++) sum += A[i];

		ll ans = sum;

		ll delta = 0;
		for(int i = 0; i < g; i++) {
			for(int j = 0; j + 1 < V[i].size(); j += 2) {
				if(V[i][j] + V[i][j + 1] < 0) delta += (V[i][j] + V[i][j + 1]);
				else break;
			}
		}
		ans = max(ans, sum - delta - delta);

		delta = 0;
		for(int i = 0; i < g; i++) delta += V[i][0];
		for(int i = 0; i < g; i++) {
			for(int j = 1; j + 1 < V[i].size(); j += 2) {
				if(V[i][j] + V[i][j + 1] < 0) delta += (V[i][j] + V[i][j + 1]);
				else break;
			}
		}
		ans = max(ans, sum - delta - delta);
		printf("%lld\n", ans);
	}
	return 0;
}