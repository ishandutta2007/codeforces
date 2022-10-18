#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define ld long double
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto y : a) cout << y << ' ';\
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
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout); 
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 100000, logN = 17, K = 350;

int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0}, ddx[4] = {1, 1, -1, -1}, ddy[4] = {-1, 1, -1, 1};

int main () {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	string a[n];
	fop (i,0,n) cin >> a[i];
	int pos[n][m][4];
	fop (i,0,n) fop (j,0,m) {
		int k = 0;
		if (!i || !j) pos[i][j][k] = 1;
		else {
			if (a[i - 1][j] == a[i][j - 1] && a[i - 1][j] == a[i][j]) {
				pos[i][j][k] = min(pos[i - 1][j][k], pos[i][j - 1][k]) + 1;
			} else {
				pos[i][j][k] = 1;
			}
		}
	}
	fop (i,0,n) FOP (j,m,0) {
		int k = 1;
		if (!i || j == m - 1) pos[i][j][k] = 1;
		else {
			if (a[i - 1][j] == a[i][j + 1] && a[i][j + 1] == a[i][j]) {
				pos[i][j][k] = min(pos[i - 1][j][k], pos[i][j + 1][k]) + 1;
			} else {
				pos[i][j][k] = 1;
			}
		}
	}
	FOP (i,n,0) fop (j,0,m) {
		int k = 2;
		if (i == n - 1 || !j) pos[i][j][k] = 1;
		else {
			if (a[i + 1][j] == a[i][j - 1] && a[i][j - 1] == a[i][j]) {
				pos[i][j][k] = min(pos[i + 1][j][k], pos[i][j - 1][k]) + 1;
			} else {
				pos[i][j][k] = 1;
			}
		}
	}
	FOP (i,n,0) FOP (j,m,0) {
		int k = 3;
		if (i == n - 1 || j == m - 1) pos[i][j][k] = 1;
		else {
			if (a[i + 1][j] == a[i][j + 1] && a[i][j + 1] == a[i][j]) {
				pos[i][j][k] = min(pos[i + 1][j][k], pos[i][j + 1][k]) + 1;
			} else {
				pos[i][j][k] = 1;
			}
		}
	}
	lli ans = 0;
	fop (i,0,n) fop (j,0,m) {
		int mn = 1 << 30;
		fop (k,0,4) mn = min(mn, pos[i][j][k]);
		ans += mn;
	}
	cout << ans << endl;
}