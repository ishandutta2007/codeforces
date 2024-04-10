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
	ll x,y,m;
	scanf ("%lld %lld %lld",&x,&y,&m);
	if (x >= m || y >= m) return !printf ("0\n");
	if (x <= 0 && y <= 0) return !printf ("%d\n",-1);
	ll old = 0;
	if (x <= 0 || y <= 0) {
		if (x > 0) swap(x,y);
		old = (-x)/y;
		x += old * y;
		assert(x <= y);
	}
	for (int ans = 0;ans < 100000; ans++) {
		if (x >= m || y >= m) return !printf ("%lld\n",ans+old);
		(x < y ? x : y) = x + y;
	}
	assert(0);
	return 0;
}