#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll T[101010];
int X[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%lld%d", &T[i], &X[i]);
		int x = 0;
		int ans = 0;
		int cur = 1;
		T[N + 1] = 2020202020202020LL;
		while(cur <= N) {
			ll nt = T[cur] + abs(X[cur] - x);
			int nxt = X[cur];
			int now = T[cur];
			ll tmp = T[cur];

			while(cur <= N && (T[cur] == tmp || T[cur] < nt)) {
				if(x < nxt) {
					ll l = x + (T[cur] - now), r = x + (min(T[cur + 1], nt) - now);
					if(l <= X[cur] && X[cur] <= r) ans++;
				}
				else {
					ll r = x - (T[cur] - now), l = x - (min(T[cur + 1], nt) - now);
					if(l <= X[cur] && X[cur] <= r) ans++;
				}
				// printf("cur ans %d %d\n", cur, ans);
				cur++;
			}
			x = nxt;
		}
		printf("%d\n", ans);
	}
	return 0;
}