#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int A[202020];
int N, K;

map<int, int> mp;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		mp.clear();
		scanf("%d%d", &N, &K);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		int mx = 0, r = -1;

		for(int i = 1; i <= N; i++) {
			int t = (K - (A[i] % K)) % K;
			if(t == 0) continue;
			mp[t]++;
			int now = mp[t];
			if(now > mx || (now == mx && t > r)) {
				mx = now; r = t;
			}
		}

		// printf("%d %d\n", mx, r);
		if(mx == 0) puts("0");
		else printf("%lld\n", (ll)K * (mx - 1) + r + 1);
	}
	return 0;
}