#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
 
using ll = long long;
using ld = long double;
using namespace std;

int T;
vector <int> t[3];

int main() {
	scanf ("%d", &T);
	while (T--) {
		int n;
		scanf ("%d", &n);
		rep(i, 0, 2) t[i].clear();
		int s = 0;
		rep(i, 1, n) {
			int x;
			scanf ("%d", &x);
			s += x;
			if (x < 0) t[0].pb(x);
			if (x == 0) t[1].pb(x);
			if (x > 0) t[2].pb(x);
		}
		if (s == 0) printf ("NO\n");
		else {
			printf ("YES\n");
			if (s > 0) swap(t[0], t[2]);
			rep(i, 0, 2)
				for (auto x : t[i])
					printf ("%d ", x);
			puts("");
		}
	}
	
	return 0;
}