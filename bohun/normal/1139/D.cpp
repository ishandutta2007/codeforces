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
#define ios cin.tie(0); ios_base::sync_with_stdio(0);
 
 
using namespace std;
using namespace __gnu_pbds;
 
// order_by_key
// find_by_order
// tree<int>, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ja;		
const int mod = 1e9 + 7, nax = 111111;
int n;
int dp[nax];
int sito[nax];

vector <int> primes, pp;
int N;
int ile;

void rek(int wsk, int kon, int sum, int ilo) {
	if(wsk == kon) {
		ile += (sum % 2 == 1 ? -1 : 1) * N / ilo;
		return;
	}
	rek(wsk + 1, kon, sum + 1, ilo * pp[wsk] / __gcd(ilo, pp[wsk]));
	rek(wsk + 1, kon, sum, ilo);
}	

void add(int &a, int b) {
	a += b;
	if(a >= mod)
		a -= mod;
}

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

int byl[nax];

int inv;
int ulamek(int a) {
	return (ll) a * inv % mod;
}


int main() {
	ios
	cin >> n;
	inv = pt(n, mod - 2);
	
	FOR(i, 2, nax - 1) {
		if(!sito[i]) {
			for(int j = i; j < nax; j += i)
				sito[j] = i;
		}
	}
	
	FOR(i, 2, n) {
		primes.clear();
		int x = i;
		while(x != 1) {
			primes.pb(sito[x]);
			x /= sito[x];
		}
		
		x = ss(primes);
		int suma = 1;
		FOR(maska, 0, (1 << x) - 2) {
			int iloczyn = 1;
			FOR(j, 0, x - 1) {
				if((1 << j) & maska)
					iloczyn *= primes[j];
			}
			if(byl[iloczyn] == i)
				continue;
			byl[iloczyn] = i;
			N = n / iloczyn;
			int y = i / iloczyn;
			pp.clear();
			while(y != 1) {
				pp.pb(sito[y]);
				y /= sito[y];
			}
			ile = 0;
			rek(0, ss(pp), 0, 1);
			add(suma, (ll) ile * inv % mod * dp[iloczyn] % mod);
		}
		
		int y = (ll) (n / i) * inv % mod;
		y = (1 - y + mod) % mod;
		dp[i] = (ll) suma * pt(y, mod - 2) % mod;
		
		
	}
	
	int ans = 0;
	FOR(i, 1, n) {
		add(ans, (ll) ulamek(1) * (1 + dp[i]) % mod);
	}
	cout << ans;
			
			
		
	
	
	
	
	
	
	
	
	
	return 0;
}