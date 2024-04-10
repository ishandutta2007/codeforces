#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M;
ll D[4040404];
ll delta[4040404];

int main() {
	scanf("%d%d", &N, &M);
	ll S = 1;
	ll add = 0;
	for(int i = 1; i <= N; i++) {
		D[i] = S;
		add = (add + delta[i]) % M;
		D[i] = (D[i] + add) % M;
		for(int j = 2; (ll)i * j <= N; j++) {
			delta[i * j] = (delta[i * j] + D[i]) % M;
			if(i * j + j <= N) delta[i * j + j] = (delta[i * j + j] + M - D[i]) % M;
		}
		if(i > 1) S = (S + D[i]) % M;
	}
	printf("%lld\n", D[N]);
	return 0;
}