#include <stdio.h>

typedef long long ll;

int L[70];
int S[300005];
int E[300005];
int O[300005];
ll T[300005];
int A[300005];

int f(ll x) {
	int ret = 0;
	while(x) {
		if(x & 1) ret++;
		x >>= 1;
	}
	return ret;
}

int main() {
	int N; scanf("%d", &N);
	E[0] = 1;
	for(int i = 1; i <= N; i++) scanf("%lld", &T[i]);
	for(int i = 1; i <= N; i++) A[i] = f(T[i]);
	for(int i = 1; i <= N; i++) S[i] = S[i - 1] + A[i];
	for(int i = 1; i <= N; i++) {
		O[i] = O[i - 1]; E[i] = E[i - 1];
		if(S[i] & 1) O[i]++;
		else E[i]++;
	}

	ll ans = 0;
	//for(int i = 1; i <= N; i++) printf("%d ", O[i]); puts("");

	for(int i = 1; i <= N; i++) {
		int b = 0;
		L[A[i]] = i;
		for(int j = 63; j >= 1; j--) {
			if(L[j] <= b) continue;
			int l = b + 1, r = i;
			while(l <= r) {
				int m = (l + r) >> 1;
				if(S[i] - S[m - 1] < 2 * j) r = m - 1;
				else l = m + 1;
			}
			//r
			//printf("%d %d %d %d\n", i, j, r, b);
			if(r <= b) { b = L[j]; continue; }
			if(r > L[j]) r = L[j];
			int o = (b == 0 ? 0 : O[b - 1]);
			int e = (b == 0 ? 0 : E[b - 1]);
			if(S[i] & 1) { ans += (O[r - 1] - o); }
			else { ans += (E[r - 1] - e); }
			b = L[j];
		}
		//printf("%d %lld\n", i, ans);
	}
	printf("%lld\n", ans);
	return 0;
}