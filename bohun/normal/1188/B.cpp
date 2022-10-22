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

const int nax = 300005;

int n, p, k;
int a;	
map <int, int> mapa;
ll ans = 0;
	
				
int main() {
	scanf("%d%d%d", &n, &p, &k);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a);
		ll g = (ll) a * a % p * a % p * a % p;
		g = (g - (ll) k * a % p + p) % p;
		ans += mapa[g];
		mapa[g]++;
	}
	printf("%lld", ans);
	
			
		
	
	
	
		
	return 0;
}