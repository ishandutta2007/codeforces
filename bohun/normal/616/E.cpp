#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0)
#define bignum vector <int>
 
 
using namespace std;

const int mod = 1e9 + 7;

ll n, m;
int ans = 0;

ll sum(ll r) {
	r %= mod;
	return (ll) r * (r + 1) / 2 % mod;
}
	

int main() {
	scanf("%lld%lld", &n, &m);
	ans = (ll) (n % mod) * (m % mod) % mod;
	for(ll i = 1; i <= min(n, m);) {
		ll x = n / i;
		ll j = n / x;
		j = min({j, m, n});
		ans -= (ll) (x % mod) * (sum(j) - sum(i - 1) + mod) % mod;
		ans += mod;
		ans %= mod;
		i = j + 1;
	}
	printf("%d", ans);
		
		
	
	
	return 0;
}