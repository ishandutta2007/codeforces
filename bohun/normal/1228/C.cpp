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
 
 
using namespace std;

const int mod = 1e9 + 7;

ll n, x;
int res = 1;
vector <int> primes;

int pt(int a, int b) {
	int r = 1;
	while(b) {
		if(b & 1)
			r = (ll) r * a % mod;
		a = (ll) a * a % mod;
		b /= 2;
	}
	return r;
}

int main() {
	scanf("%lld%lld", &x, &n);
	for(int i = 2; i * i <= x; ++i) {
		if(x % i == 0) {
			primes.pb(i);
			while(x % i == 0)
				x /= i;
		}
	}
	if(x > 1)
		primes.pb(x);
	for(auto it : primes) {
		ll ile = 0;
		ll z = 1;
		while((ld) z <= (ld) n / it) {
			z *= it;
			ile += n / z;
			ile %= mod - 1;
		}
		res = (ll) res * pt(it, ile) % mod;
	}
	printf("%d\n", res);
		
	
	
	return 0;
}