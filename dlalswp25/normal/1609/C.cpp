#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MX = 1000000;

int N, E;
int A[202020];
int go[202020][2];
bool notprime[1010101];

int main() {
	for(int i = 2; i <= MX; i++) {
		if(notprime[i]) continue;
		for(ll j = (ll)i * i; j <= MX; j += i) {
			notprime[j] = true;
		}
	}

	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &E);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = N; i >= 1; i--) {
			if(i + E > N) { go[i][0] = go[i][1] = 0; continue; }
			if(A[i + E] != 1) go[i][0] = 0;
			else go[i][0] = go[i + E][0] + 1;
			if(A[i + E] != 1 && notprime[A[i + E]]) go[i][1] = 0;
			else go[i][1] = go[i + E][1] + 1;
		}

		ll ans = 0;
		for(int i = 1; i <= N; i++) {
			if(A[i] != 1 && notprime[A[i]]) continue;
			if(A[i] != 1) ans += go[i][0];
			else {
				if(go[i][0] == go[i][1]) { continue; }

				int t = go[i][0];
				if(i + (t + 1) * E > N) { continue; }

				ans += 1 + go[i + (t + 1) * E][0];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}