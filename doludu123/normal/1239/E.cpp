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
const int mod = 1e9 + 7, x = 864197532, N = 27, logN = 18, K = 350;

bitset <N * 50000> dp[N][N + N];
	
int main () {
	int n;
	cin >> n;
	vector <int> a(n + n);
	fop (i,0,n + n) cin >> a[i];
	sort(all(a));
	int all = accumulate(a.begin() + 2, a.end(), 0);
	dp[0][1][0] = true;
	int mx = -1, from = -1, now = n - 1;
	fop (i,2,n + n) {
		fop (j,1,n) {
			dp[j][i] |= dp[j - 1][i - 1] << a[i];
			dp[j][i] |= dp[j][i - 1];
		}
	}
        fop (s,0,N * 50000) fop (i,2,n + n) {
            if (abs(all - 2 * mx) > abs(all - 2 * s) && dp[n - 1][i][s]) mx = s, from = i;
        }
	vector <int> ans1, ans2;
	FOP (i,n + n,2) {
		if (mx >= a[i] && dp[now - 1][i - 1][mx - a[i]]) {
		    ans1.pb(a[i]);
		    now--;
		    mx -= a[i];
                } else ans2.pb(a[i]);
	}
	sort(all(ans1));
	sort(all(ans2));
	reverse(all(ans2));
	cout << a[0] << ' ';
	for (int i : ans1) cout << i << ' ';
	cout << endl;
	for (int i : ans2) cout << i << ' ';
	cout << a[1] << endl;
}