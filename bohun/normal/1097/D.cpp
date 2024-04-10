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
using namespace __gnu_pbds;
 
// order_of_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ja;

const int mod = 1e9 + 7, nax = 1e4 + 111;
ll n, k;
int dp[nax][60];
map <ll, int> primes;

int pt(ll a, int b) {
	int r = 1;
	while(b) {
		if(b & 1)
			r = (ll) r * a % mod;
		a = (ll) a * a % mod;
		b /= 2;
	}
	return r;
}

void add(int &a, int b) {
	a += b;
	if(a >= mod)
		a -= mod;
}

int odw[nax];

int main() {				 
	ios;
	cin >> n >> k;
	
	FOR(i, 0, 100) {
		odw[i] = pt(i, mod - 2);
	}
	
	int ans = 1;
	for(ll i = 2; i * i <= n; ++i) {
		while(n % i == 0) {
			primes[i] += 1;
			n /= i;
		}
	}
	
	if(n > 1) {
		primes[n] += 1;
	}
	
	for(auto it: primes) {
		ll p = it.fi;
		int ile = it.se;
		
		for(int krok = 0; krok <= k; ++krok)
			for(int j = 0; j <= ile; ++j)
				dp[krok][j] = 0;
		dp[0][ile] = 1;
		for(int krok = 0; krok < k; ++krok) {
			for(int j = 0; j <= ile; ++j) {
				for(int g = 0; g <= j; ++g) {
					add(dp[krok + 1][g], (ll) dp[krok][j] * odw[j + 1] % mod);
				}
			}
		}
		
		int sum = 0;
		for(int j = 0; j <= ile; ++j) {
			 add(sum, (ll) pt(p, j) * dp[k][j] % mod);
		}
		
		//cout << p << " " << sum << endl;
		
		ans = (ll) ans * sum % mod;
	}
	
	cout << ans;
				
	
	
	
	
		
	
	
	
	
	return 0;
}