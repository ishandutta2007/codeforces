#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll INF = 2e18;

vector<int> v;
ll ans;

void f() {
	ll t = 0;
	reverse(v.begin(), v.end());
	for(int i : v) {
		// printf("%d ", i);
		t *= 10;
		t += i;
	}
	// puts("");
	ans = min(ans, t);
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N, K; scanf("%d%d", &N, &K);

		ans = INF;

		for(int i = 0; i < 10; i++) {
			int s = 0;
			for(int j = i; j <= i + K; j++) {
				if(j < 10) s += j;
				else s += j - 9;
			}
			if(s == N) { ans = i; break; }
		}

		if(ans != INF) { printf("%lld\n", ans); continue; }

		for(int i = 0; i < 17; i++) {
			for(int j = 0; j < 10; j++) {
				// printf("%d %d\n", i, j);
				v.clear();
				v.push_back(j);
				for(int k = 0; k < i; k++) v.push_back(9);

				int x;

				if(j + K < 10) {
					int y = i * 9 * (K + 1);
					for(int k = j; k <= j + K; k++) {
						// printf("k %d\n", k);
						y += k;
					}
					if(y > N) continue;
					if((N - y) % (K + 1)) continue;
					x = (N - y) / (K + 1);
				}
				else {
					int z = 10 - j;
					int y = i * 9 * z;
					for(int k = j; k <= j + K; k++) y += k % 10;
					if(y > N) continue;
					if((N - y + z - (K + 1)) % (K + 1)) continue;
					x = (N - y + z - (K + 1)) / (K + 1);
				}

				// printf("%d %d %d\n", i, j, x);

				if(x == 0) {
					f(); continue;
				}

				if(x <= 8) {
					v.push_back(x);
					f(); continue;
				}

				v.push_back(8); x -= 8;
				while(x > 9) {
					v.push_back(9); x -= 9;
				}
				v.push_back(x);
				f();
			}
		}
		if(ans == INF) puts("-1");
		else printf("%lld\n", ans);
	}
	return 0;
}