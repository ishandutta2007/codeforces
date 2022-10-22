#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

const ll MAXN = 1e6 + 10;
const ll MOD = 1e9 + 7;

ll n, h[MAXN];
ll ans = 0, c[MAXN], d[MAXN];

int main(){
	scanf("%I64d", &n);
	for (ll i = 0; i < n; i++)	scanf("%I64d", &h[i]);
	c[0] = 0;
	for (ll i = 0; i < n; i++){
		ans = (ans + h[i] - 1 + MOD) % MOD;
		ll z = i==0?0:min(h[i], h[i - 1]);
		ans = (ans + ll(h[i] - 1 - (h[i] - z)) * c[i]) % MOD;

		if (i < n - 1){
			ll tz = z;
			z = min(h[i], h[i + 1]);
			c[i + 1] = h[i] - 1 - (h[i] - z);
			z = min(z, tz);
			c[i + 1] = (c[i + 1] + ll(h[i] - 1 - (h[i] - z)) * c[i]) % MOD;
		}
	}	
	printf("%I64d\n", ans);
	return	0;
}