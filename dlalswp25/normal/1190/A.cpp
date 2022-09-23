#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll P[101010];
ll N, M, K;
int ans;

int main() {
	scanf("%lld%lld%lld", &N, &M, &K);
	for(int i = 1; i <= M; i++) { scanf("%lld", &P[i]); P[i]--; }

	int p = 1;

	while(p <= M) {
		int t = p;
		ll x = (P[p] - (t - 1)) / K;
		while(p <= M && (P[p] - (t - 1)) / K == x) p++;
		ans++;
	}
	printf("%d\n", ans);

	return 0;
}