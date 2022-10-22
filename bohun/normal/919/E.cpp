#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i) 
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
 
 
using namespace std;
using namespace __gnu_pbds;
 
// order_by_key
// find_by_order
// tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> siema;
 
int a, b, p;
ll x;
 
int pt(int a, int b) {
	int r = 1;
	while(b) {
		if(b & 1)
			r = (ll) r * a % p;
		a = (ll) a * a % p;
		b /= 2;
	}
	return r;
}
 
ll ans = 0;
	
	
				
int main() {
	scanf("%d%d%d%lld", &a, &b, &p, &x);
	for(int y = 0; y <= min((ll) p - 2, x); ++y) {
		ll right = (ll) b * pt(pt(a, y), p - 2) % p;
		ll left = (y - right + p) % p;
		ll R = (x - y) / (p - 1);
		if(R < left) {
			continue;
		}
		ll r = R % p;
		ll D = R / p;
		if(left <= r) {
			ans += D + 1;
		}
		else {
			ans += D;
		}
	}
	cout << ans;
			
		
	
	
	
		
	return 0;
}