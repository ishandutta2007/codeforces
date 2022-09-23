#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, K, B;
ll S;
ll ans[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d%d%lld", &N, &K, &B, &S);
		if(S < (ll)K * B || S > (ll)K * B + (ll)(K - 1) * N) {
			puts("-1"); continue;
		}
		ans[1] = (ll)B * K;
		for(int i = 2; i <= N; i++) ans[i] = 0;
		S -= (ll)K * B;
		for(int i = 1; i <= N; i++) {
			if(S < K - 1) { ans[i] += S; S = 0; }
			else { ans[i] += K - 1; S -= K - 1; }
		}
		for(int i = 1; i <= N; i++) printf("%lld ", ans[i]); puts("");
	}
	return 0;
}