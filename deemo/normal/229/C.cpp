#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll MAXN = 1e6 + 20;

ll n, m;
ll cnt[MAXN];

int main(){
	scanf("%I64d %I64d", &n, &m);
	for (ll i = 0; i < m; i++){
		ll a, b;	scanf("%I64d%I64d", &a, &b);	a--, b--;
		cnt[a]++;
		cnt[b]++;
	}	

	ll ans = n * (n - 1) * (n - 2)/ ll(6), c = 0;
	for (ll i = 0; i < n; i++)
		c += cnt[i] * ((n - 1) - cnt[i]);
	c /= 2;
	ans -= c;
	printf("%I64d\n", ans);
	return	0;
}