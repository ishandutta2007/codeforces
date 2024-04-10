#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int gcd(int a, int b) { while(b) { a %= b; swap(a, b); } return a; }
ll lcm(int a, int b) { return (ll)a * b / gcd(a, b); }

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int b, db, nb; scanf("%d%d%d", &b, &db, &nb);
		int c, dc, nc; scanf("%d%d%d", &c, &dc, &nc);
		ll rb = b + (ll)db * (nb - 1);
		ll rc = c + (ll)dc * (nc - 1);
		if(c < b || rb < c) { puts("0"); continue; }
		if(rc < b || rb < rc) { puts("0"); continue; }
		if((c - b) % db || dc % db) { puts("0"); continue; }
		if(b > c - dc || rb < rc + dc) { puts("-1"); continue; }

		ll ans = 0;
		for(int i = 1; i * i <= dc; i++) {
			if(lcm(i, db) == dc) {
				ans = (ans + (ll)(dc / i) * (dc / i)) % MOD;
			}
			if(i != dc / i && lcm(dc / i, db) == dc) {
				ans = (ans + (ll)i * i) % MOD;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}