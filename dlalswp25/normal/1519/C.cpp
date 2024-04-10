#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
vector<int> V[202020];
vector<ll> S[202020];
int U[202020];
int A[202020];
int bef[202020];
int nxt[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			V[i].clear(); V[i].push_back(0);
		}
		ll tot = 0;
		for(int i = 1; i <= N; i++) scanf("%d", &U[i]);
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			tot += A[i];
			V[U[i]].push_back(A[i]);
		}
		for(int i = 1; i <= N; i++) {
			sort(V[i].begin() + 1, V[i].end());
			S[i].resize(V[i].size());
			for(int j = 1; j < V[i].size(); j++) S[i][j] = S[i][j - 1] + V[i][j];
		}

		nxt[0] = 1; bef[N + 1] = N;
		for(int i = 1; i <= N; i++) {
			bef[i] = i - 1;
			nxt[i] = i + 1;
		}

		for(int i = 1; i <= N; i++) {
			int t = 0;
			while(t <= N) {
				t = nxt[t];
				if(t > N) break;
				if((int)V[t].size() - 1 < i) {
					nxt[bef[t]] = nxt[t];
					bef[nxt[t]] = bef[t];
					tot -= S[t].back();
				}
			}
			t = 0;
			ll ans = 0;
			while(t <= N) {
				t = nxt[t];
				if(t > N) break;
				int m = (int)V[t].size() - 1;
				ans += S[t][m % i];
			}
			printf("%lld ", tot - ans);
		}
		puts("");
	}
	return 0;
}