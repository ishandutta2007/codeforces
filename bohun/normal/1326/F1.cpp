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
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 14;

int n, ff;
char s[N][N + 1];
vector <LL> dp[1 << N][N];
LL sum[1 << N];

vector <int> bits[1 << N];

int main() {	
	scanf ("%d", &n);
	rep(i, 0, n - 1) scanf ("%s", s[i]);
	rep(mask, 1, (1 << n) - 1)
		rep(last, 0, n - 1)
			dp[mask][last].resize(1 << (__builtin_popcount(mask) - 1), 0);
			
	rep(mask, 1, (1 << n) - 1)
		rep(j, 0, n - 1)
			if ((mask >> j) & 1)
				bits[mask].pb(j);
			
	rep(mask, 1, (1 << n) - 1)
		rep(last, 0, n - 1) {
			if (((mask >> last) & 1) == 0) continue;
			int cnt = __builtin_popcount(mask);
			if (cnt == 1) {
				dp[mask][last][0] = 1;
				continue;
			}
			rep(f, 0, (1 << (cnt - 1)) - 1) {
				for (auto bit : bits[mask]) {
					if (bit == last || ((f >> (cnt - 2)) & 1) != (s[last][bit] == '1')) continue;
					ff = f;
					if (((f >> (cnt - 2)) & 1) == 1) ff ^= (1 << (cnt - 2));
					dp[mask][last][f] += dp[mask ^ (1 << last)][bit][ff];
				}
			}
		}
	rep(last, 0, n - 1)
		rep(mask, 0, (1 << (n - 1)) - 1) 
			sum[mask] += dp[(1 << n) - 1][last][mask];
			
	rep(i, 0, (1 << (n - 1)) - 1) printf ("%lld ", sum[i]);
	
	return 0;
}