#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define ll long long
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, n) for(int i = 0; i < n; ++i)

using namespace std;	

int n;
vector <int> a[10000005];
int b;
ll ans = 1e18;
int c, d;
int MAX;
			
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &b);
		a[b].pb(i);
		MAX = max(MAX, b);
	}
	for(int i = 1; i <= MAX; ++i) {
		pair<int,int> x = mp(0, 0);
		pair<int,int> y = mp(0, 0);
		for(int j = i; j <= MAX; j += i) {
			for(auto it : a[j]) {
				if(!x.fi)
					x = mp(j, it);
				else if(!y.fi) {
					y = mp(j, it);
					break;
				}
			}
			if(y.fi) break;
		}
		if(x.fi && y.fi && ans > 1ll * x.fi * y.fi / __gcd(x.fi, y.fi)) {
			c = x.se;
			d = y.se;
			ans = 1ll * x.fi * y.fi / __gcd(x.fi, y.fi);
		}
	}
	if(c > d) swap(c, d);
	printf("%d %d\n", c, d);
	
	
	
	return 0;
}