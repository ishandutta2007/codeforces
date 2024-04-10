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
	
const int N = 80;

int T, n, k;
int a[N], b[N];
int dp[N][N];
bool biore[N][N];

void solve() {
	scanf ("%d%d", &n, &k);
	rep(i, 1, n) 
		scanf ("%d%d", a + i, b + i);
		
	rep(i, 0, n)
		rep(j, 0, k) {
			dp[i][j] = -1e9;
			biore[i][j] = false;
		}
	vector <int> ord;
	rep(i, 1, n) 
		ord.pb(i);
	sort(all(ord), [](int x, int y) {
		return b[x] < b[y];
	});
	
	dp[0][0] = 0;
	rep(i, 1, n) {
		int ja = ord[i - 1];
		rep(j, 0, k) {
			if (j >= 1) {
				if (dp[i - 1][j - 1] < 0) continue;
				int s = dp[i - 1][j - 1] + (j - 1) * b[ja] + a[ja];
				if (dp[i][j] < s) {
					dp[i][j] = s;
					biore[i][j] = true;
				}
			}
			if (dp[i - 1][j] < 0) continue;
			int s = dp[i - 1][j] + (k - 1) * b[ja];
			if (dp[i][j] < s) {
				dp[i][j] = s;
				biore[i][j] = false;
			}
		}
	}
	
	int K = k;
	vector <int> vec, q;
	per(i, 1, n) {
		if (biore[i][K]) {
			vec.pb(ord[i - 1]);
			K--;
		}
		else q.pb(ord[i - 1]);
	}
	reverse(all(vec));
	printf ("%d\n", n + n - k);
	rep(i, 0, ss(vec) - 2)
		printf ("%d ", vec[i]);
	for (auto it : q) 
		printf ("%d %d ", it, -it);
	printf ("%d\n", vec.back());
}

int main() {
	scanf ("%d", &T);
	while (T--) solve();
			
	return 0;
}