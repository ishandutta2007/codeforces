#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define all(x) x.begin(), x.end()
 
using namespace std;

int T;
int a, b, c, e;
vector <int> d[3];

ll kwa(ll a) {
	return a * a;
}

void solve() {
	rep(i, 0, 2) d[i].clear();
	scanf ("%d%d%d", &a, &b, &c);
	rep(i, 1, a) {
		scanf ("%d", &e);
		d[0].pb(e);
	}
	rep(i, 1, b) {
		scanf ("%d", &e);
		d[1].pb(e);
	}
	rep(i, 1, c) {
		scanf ("%d", &e);
		d[2].pb(e);
	}
	rep(i, 0, 2) sort(all(d[i]));
	ll ans = 5e18 + 10101;
	
	rep(i, 0, 2) {
		int x, y;
		if (i == 0) {
			x = 1;
			y = 2;
		}
		if (i == 1) {
			x = 0;
			y = 2;
		}
		if (i == 2) {
			x = 0;
			y = 1;
		}
		rep(j, 0, ss(d[i]) - 1) {
			int z1 = (int) (lower_bound(all(d[x]), d[i][j]) - d[x].begin());
			int z2 = (int) (upper_bound(all(d[y]), d[i][j]) - d[y].begin() - 1);
			
			
			if (0 <= z1 && z1 < ss(d[x]) && 0 <= z2 && z2 < ss(d[y])) {
				a = d[i][j];
				b = d[x][z1];
				c = d[y][z2];
				
				ll g = kwa(a - b) + kwa(a - c) + kwa(b - c);
				
				if (g < ans) {
					ans = g;
				}
			}
			
			z1 = (int) (lower_bound(all(d[y]), d[i][j]) - d[y].begin());
			z2 = (int) (upper_bound(all(d[x]), d[i][j]) - d[x].begin() - 1);
			
			if (0 <= z1 && z1 < ss(d[y]) && 0 <= z2 && z2 < ss(d[x])) {
				a = d[i][j];
				b = d[x][z2];
				c = d[y][z1];
				
				ll g = kwa(a - b) + kwa(a - c) + kwa(b - c);
				
				if (g < ans) {
					ans = g;
				}
			}
		}
	}
	printf ("%lld\n", ans);
}
			
		
	

int main() {
	scanf ("%d", &T);
	while (T--) solve();
	
	
	return 0;
}