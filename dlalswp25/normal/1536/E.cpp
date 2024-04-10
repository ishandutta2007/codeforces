#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int N, M;
char A[2020][2020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) scanf("%s", A[i] + 1);
		int zero = 0;
		for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) {
			if(A[i][j] == '0') zero++;
		}
		ll ans = 1;
		for(int i = 1; i <= N * M - zero; i++) ans = ans * 2 % MOD;
		if(!zero) ans = (ans + MOD - 1) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}