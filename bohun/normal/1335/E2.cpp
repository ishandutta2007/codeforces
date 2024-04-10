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

const int nax = 2e5 + 100;

int T, n, a[nax];
vector <int> vals[nax];
int p[nax][201];
int ile[201];

void solve() {
	scanf ("%d", &n);
	rep(i, 1, n) {
		scanf ("%d", a + i);
		vals[a[i]].pb(i);
		rep(j, 1, 200) p[i][j] = 0;
		rep(j, 1, 200)
			p[i][j] += p[i - 1][j];
		p[i][a[i]]++;
	}
	int res = 0;
	rep(i, 1, 200) res = max(res, ss(vals[i]));
	rep(i, 1, 200)
		rep(j, 1, 200) {
			if (i == j)continue;
				int a1 = 0;
				int a2 = ss(vals[i]) - 1;
				int cnt = 0;
				while (a1 < a2) {
					cnt++;
					res = max(res, 2 * cnt + p[vals[i][a2]][j] - p[vals[i][a1] - 1][j]);
					a1++;
					a2--;
				}
			}
	printf ("%d\n", res);
	rep(i, 1, 200) vals[i].clear();
}	
	

int main() {
	scanf ("%d", &T);
	while (T--) solve();
	
	
	return 0;
}