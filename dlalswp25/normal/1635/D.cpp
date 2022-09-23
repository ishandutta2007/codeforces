#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
const int MX = 200000;

int N, P;
set<int> S;
int A[202020];
ll D[202020];

int main() {
	D[0] = 1; D[1] = 1;
	for(int i = 2; i <= MX; i++) D[i] = (D[i - 1] + D[i - 2]) % MOD;
	for(int i = 1; i <= MX; i++) D[i] = (D[i] + D[i - 1]) % MOD;
	int tc = 1;
	while(tc--) {
		scanf("%d%d", &N, &P);
		S.clear();
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			S.insert(A[i]);
		}
		ll ans = 0;
		for(int i = 1; i <= N; i++) {
			bool ok = true;
			int tmp = A[i], b = 0;
			while(tmp) {
				tmp >>= 1; b++;
			}
			if(b > P) continue;

			while(A[i]) {
				if(A[i] & 1) A[i] >>= 1;
				else if(A[i] & 2) break;
				else A[i] >>= 2;
				if(S.find(A[i]) != S.end()) {
					ok = false; break;
				}
			}
			if(ok) {
				ans = (ans + D[P - b]) % MOD;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}