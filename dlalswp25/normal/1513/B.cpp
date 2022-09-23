#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int N;
int A[202020];
ll F[202020];
bool chk[202020];

int main() {
	F[0] = 1;
	for(int i = 1; i <= 200000; i++) F[i] = F[i - 1] * i % MOD;

	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= N; i++) chk[i] = false;
		for(int i = 0; i < 30; i++) {
			bool zero = false, one = false;
			for(int j = 1; j <= N; j++) {
				if(A[j] & 1 << i) one = true;
				else zero = true;
			}
			if(zero && one) {
				for(int j = 1; j <= N; j++) {
					if(A[j] & 1 << i) chk[j] = true;
				}
			}
		}

		int cnt = N;
		for(int i = 1; i <= N; i++) if(chk[i]) cnt--;
		printf("%lld\n", (ll)cnt * (cnt - 1) % MOD * F[N - 2] % MOD);
	}
	return 0;
}