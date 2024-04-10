#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define print(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define mt make_tuple
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define X first
#define Y second
#define oset tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update>
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 998244353, x = 864197532, N = 3000;

void solve() {
	int n, m;
	cin >> n >> m;
	vector <vector <lli>> a(n, vector <lli> (m));
	fop (i,0,n) fop (j,0,m) cin >> a[i][j];
	auto ask = [&](lli height) {
		lli dp[n][m];
		fop (i,0,n) {
			fop (j,0,m) {
				if (a[i][j] - i - j < height) dp[i][j] = 1ll << 58;
				else if (!i and !j) dp[i][j] = a[i][j] - height;
				else if (!i) {
					dp[i][j] = dp[i][j - 1] + a[i][j] - (height + i + j);
				} else if (!j) {
					dp[i][j] = dp[i - 1][j] + a[i][j] - (height + i + j);
				} else {
					dp[i][j] = min(dp[i][j - 1] + a[i][j] - (height + i + j), dp[i - 1][j] + a[i][j] - (height + i + j));
				}
			}
		}
		return dp[n - 1][m - 1];
	};
	lli ans = 1ll << 60;
	fop (i,0,n) fop (j,0,m) {
		lli aa = ask(a[i][j] - i - j);
		ans = min(ans, aa);
		//test(aa); 
	}
	cout << ans << endl;
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
}