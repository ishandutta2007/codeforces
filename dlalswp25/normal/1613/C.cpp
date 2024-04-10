#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = 1000000000000000001LL;

int N;
ll H;
int A[105];

ll add(ll a, ll b) {
	return min(INF, a + b);
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%lld", &N, &H);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		ll l = 1, r = H;
		while(l <= r) {
			ll m = l + r >> 1;
			ll tot = m;
			for(int i = 1; i < N; i++) tot = add(tot, min(m, (ll)A[i + 1] - A[i]));
			if(tot >= H) r = m - 1;
			else l = m + 1;
		}
		printf("%lld\n", l);
	}
	return 0;
}