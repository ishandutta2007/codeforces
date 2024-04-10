#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int SZ = 500;

int N, Q;
ll X[202020];
ll Y[202020];
int add[202020];
int small[505][505];
int when[202020];

int main() {
	scanf("%d%d", &N, &Q);
	for(int i = 1; i <= N; i++) scanf("%lld%lld", &X[i], &Y[i]);

	int ans = 0;
	for(int i = 1; i <= Q; i++) {
		int t, a; scanf("%d%d", &t, &a);
		if(t == 1) {
			ll L = X[a] + Y[a];
			if(L > SZ) {
				for(ll j = i + X[a]; j <= Q; j += L) add[j]++;
				for(ll j = i + L; j <= Q; j += L) add[j]--;
			}
			else {
				small[L][(i + X[a]) % L]++;
				small[L][i % L]--;
				add[i]++;
			}
			when[a] = i;
		}
		else {
			ll L = X[a] + Y[a];
			if(L > SZ) {
				for(ll j = when[a] + X[a]; j <= Q; j += L) add[j]--;
				for(ll j = when[a] + L; j <= Q; j += L) add[j]++;
			}
			else {
				small[L][(when[a] + X[a]) % L]--;
				small[L][when[a] % L]++;
			}
			if((i - when[a]) % L > X[a] || (i - when[a]) % L == 0) add[i]--;
		}

		ans += add[i];
		for(int j = 1; j <= SZ; j++) {
			ans += small[j][i % j];
		}

		printf("%d\n", ans);
	}
	return 0;
}