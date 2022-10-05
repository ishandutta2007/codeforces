#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, K;
int A[1010][25];
map<ll, int> cards;
map<ll, int> cnt;

int main() {
	scanf("%d%d", &N, &K);
	for(int i = 1; i <= N; i++) {
		ll v = 0;
		for(int j = 0; j < K; j++) {
			scanf("%d", &A[i][j]);
			v = v * 3 + A[i][j];
		}
		cards[v] = 1;
	}

	for(int i = 1; i <= N; i++) {
		for(int j = i + 1; j <= N; j++) {
			ll v = 0;
			for(int k = 0; k < K; k++) {
				if(A[i][k] == A[j][k]) v = v * 3 + A[i][k];
				else v = v * 3 + (3 - A[i][k] - A[j][k]);
			}
			if(cards.find(v) == cards.end()) continue;
			cnt[v]++;
		}
	}

	ll ans = 0;
	for(auto& e : cnt) {
		ans += (ll)e.second * (e.second - 1) / 2;
	}
	printf("%lld\n", ans);
	return 0;
}