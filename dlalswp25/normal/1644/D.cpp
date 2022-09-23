#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int N, M, K, Q;
int X[202020];
int Y[202020];
int chkX[202020];
int chkY[202020];

int main() {
	int tc; scanf("%d", &tc);
	int t = 0;
	while(tc--) {
		t++;
		scanf("%d%d%d%d", &N, &M, &K, &Q);
		for(int i = 1; i <= Q; i++) scanf("%d%d", &X[i], &Y[i]);

		int cntX = 0, cntY = 0;

		int vis = 0;
		for(int i = Q; i >= 1; i--) {
			if(chkX[X[i]] == t && chkY[Y[i]] == t) continue;
			vis++;
			if(chkX[X[i]] != t) {
				chkX[X[i]] = t; cntX++;
			}
			if(chkY[Y[i]] != t) {
				chkY[Y[i]] = t; cntY++;
			}
			if(cntX >= N || cntY >= M) break;
		}
		ll ans = 1;
		for(int i = 0; i < vis; i++) ans = ans * K % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}