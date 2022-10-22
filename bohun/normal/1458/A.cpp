#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()
#define cat(x) cerr << #x << " = " << x << endl
 
using ll = long long;
using namespace std;

int n, m;
ll a[200005], b, g;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) 
		scanf("%lld", a + i);
	sort(a, a + n);
	for (int i = 1; i < n; ++i)
		g = __gcd(g, a[i] - a[0]);
	for (int i = 0; i < m; ++i) {
		scanf("%lld", &b);
		ll ans =  __gcd(g, a[0] + b);
		printf("%lld ", ans);
		//~ ll ans2 = 0;
		//~ for (int j = 0; j < n; ++j)
			//~ ans2 = __gcd(ans2, a[j] + b);
		//~ assert(ans == ans2);
	}		
	return 0;
}