
// Problem : D. Same GCDs
// Contest : Educational Codeforces Round 81 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1295/problem/D
// Memory Limit : 256.000000 MB 
// Time Limit : 2000.000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int main () {
	int t;
	scanf ("%d",&t);
	while (t--) {
		ll a,m;
		scanf ("%lld %lld",&a,&m);
		ll gcd = __gcd(a,m), low = a/gcd, high = (a+m-1)/gcd;
		m /= gcd;
		vector<pair<ll,int>> pf;
		for (ll i = 2; i * i <= m; i++) if (m%i==0){
			pf.push_back({i,0});
			while (m%i==0) {
				pf.back().second++;
				m/=i;
			}
		}
		if (m>1) pf.emplace_back(m,1);
		auto solve = [&](ll high) {
			ll ret = 0;
			for (int mask = 1; mask < (1 << pf.size()); mask++) {
				ll prod = 1;
				for (int i = 0; i < pf.size(); i++) if (mask>>i&1) prod *= pf[i].first;
				if (__builtin_popcount(mask)&1) ret += high/prod;
				else ret -= high/prod;
			}
			return ret;
		};
		printf ("%lld\n",high-low+1-solve(high)+solve(low-1));
	}
	return 0;
}