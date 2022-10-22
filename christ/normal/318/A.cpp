#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#pragma GCC diagnostic ignored "-Wunused-result" 
#pragma GCC diagnostic ignored "-Wsign-compare" 
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
#define io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef LOCAL
#define setio(x)
#else
#define setio(x) freopen((x+".in").c_str(),"r",stdin); freopen((x+".out").c_str(),"w",stdout)
#endif
const int MN = 1e5+3, BASE = 31, LOG = 20;
int main() {
	ll n,k;
	scanf ("%lld %lld",&n,&k);
	if (k <= (n+1)/2) {
		printf ("%lld\n",k*2-1);
	} else {
		k -= (n+1)/2;
		printf ("%lld\n",k*2);
	}
	return 0;
}