#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int A[1010101];
int st[22];

ll pw(ll a, ll b) {
	ll ret = 1;
	while(b) {
		if(b & 1) ret = ret * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ret;
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N, P; scanf("%d%d", &N, &P);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		sort(A + 1, A + N + 1);

		if(P == 1) {
			if(N & 1) puts("1");
			else puts("0");
			continue;
		}

		for(int i = 0; i < 22; i++) st[i] = 0;

		ll ans = pw(P, A[N]);
		st[0] = 1;
		int mx = A[N];
		for(int i = N - 1; i >= 1; i--) {
			// printf("%d %d\n", i, mx);
			if(mx == -1) {
				st[0] = 1;
				mx = A[i];
				ans += pw(P, A[i]);
				continue;
			}

			if(A[i] <= mx - 20) {
				for(int j = i; j >= 1; j--) {
					ans = (ans + MOD - pw(P, A[j])) % MOD;
				}
				break;
			}

			ans = (ans + MOD - pw(P, A[i])) % MOD;

			int t = mx - A[i];
			st[t]--;
			while(st[t] < 0) {
				st[t] += P;
				st[t - 1]--;
				t--;
			}

			// for(int j = 0; j < 20; j++) printf("%d ", st[j]); puts("");

			int mx2 = -1;
			for(int j = 0; j < 20; j++) {
				if(st[j] > 0) { mx2 = j; break; }
			}
			if(mx2 == -1) mx = -1;
			else {
				for(int j = 0; j < 20 - mx2; j++) {
					st[j] = st[j + mx2];
				}
				mx -= mx2;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}