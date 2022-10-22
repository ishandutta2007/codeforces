#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
 
using ll = long long;
using namespace std;	
	
const int MOD = 1e9 + 7;	
	
int n;
ll x[1 << 20];
	
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int cnt[60]{};
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%lld", x + i);
			for (int j = 0; j < 60; ++j)
				if (x[i] >> j & 1)
					cnt[j]++;
		}
		ll res = 0;
		for (int i = 0; i < n; ++i) {
			
			ll s1 = 0, s2 = 0;
			for (int j = 0; j < 60; ++j) {
				if (x[i] >> j & 1) {
					s1 += (1LL << j) % MOD * cnt[j] % MOD;
					s2 += (1LL << j) % MOD * n % MOD;
				}
				else {
					s2 += (1LL << j) % MOD * cnt[j] % MOD;
				}
			}
			
			s1 %= MOD;
			s2 %= MOD;
			
			res += s1 * s2 % MOD;
			res %= MOD;
		}
		printf("%lld\n", res);
	}
	
	return 0;
}