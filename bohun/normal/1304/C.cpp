#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)

using namespace std;

int n, m;
int t, l, r;
vector <pair<int, pair<int, int>>> v;
int T;

int main() {	
	scanf ("%d", &T);
	while (T--) {
		v.clear();
		scanf("%d%d", &n, &m);
		rep(i, 1, n) {
			scanf ("%d%d%d", &t, &l, &r);
			v.pb({t, {l, r}});
		}
		sort(v.begin(), v.end());
		int last = 0;
		int L = m;
		int R = m;
		bool bad = 0;
		for (int i = 0; i < ss(v);) {
			int j = i;
			int Min = -2e9;
			int Max = 2e9;
			while (j < ss(v) && v[i].fi == v[j].fi) {
				Min = max(Min, v[j].se.fi);
				Max = min(Max, v[j].se.se);
				j++;
			}
			int r = v[i].fi - last;
			L -= r;
			R += r;
			L = max(L, Min);
			R = min(R, Max);
			if (L > R) {
				bad = 1;
				break;
			}
			last = v[i].fi;
			i = j;
		}
		if (bad) printf ("NO\n");
		else printf ("YES\n");
	}
		
	
	
	
	return 0;
}