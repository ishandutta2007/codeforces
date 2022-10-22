#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define boost cin.tie(0);ios_base::sync_with_stdio(0);
#define vi vector <int>

using namespace std;	

const int nax = 1e5 + 111;
const LL INF = 1e18;

int n, p, k;
int a[nax];
int b[nax][10];

vector <int> v;

LL dp[nax][1 << 7];

int main() {
	scanf ("%d%d%d", &n, &p, &k);
	rep(i, 1, n) scanf ("%d", a + i);
	rep(i, 1, n) rep(j, 0, p - 1) scanf ("%d", &b[i][j]);
	
	rep(i, 1, n) v.pb(i);
	
	sort(v.begin(), v.end(), [](int x, int y) {
		return a[x] > a[y];
	});
	
	rep(i, 0, n)
		rep(mask, 0, (1 << p) - 1)
			dp[i][mask] = -INF;
		
	dp[0][0] = 0;
	
	rep(i, 1, n) {
		int ja = v[i - 1];
		rep(mask, 0, (1 << p) - 1) {
			int c = __builtin_popcount(mask);
			if ((i - 1) - c < k) dp[i][mask] = dp[i - 1][mask] + a[ja];
			else dp[i][mask] = dp[i - 1][mask];
			rep(j, 0, p - 1)
				if (((mask >> j) & 1))
					dp[i][mask] = max(dp[i][mask], dp[i - 1][mask ^ (1 << j)] + b[ja][j]);
		}
	}				
	printf ("%lld\n", dp[n][(1 << p) - 1]);
	
	return 0;
}