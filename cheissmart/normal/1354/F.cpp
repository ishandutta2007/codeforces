#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << "Line(" << __LINE__ << ") -> " << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 76;

struct T{
	int first, second, i;
	bool operator<(const T t) const {
		return first < t.first;
	}
} a[N];
int dp[N][N];
pi from[N][N];

void mx(int i, int j, int val, int ii, int jj) {
	if(val > dp[i][j]) {
		dp[i][j] = val;
		from[i][j] = {ii, jj};
	}
}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		for(int i = 0; i < n; i++) cin >> a[i].S >> a[i].F, a[i].i = i + 1;
		sort(a, a + n);
		for(int i = 0; i <= n; i++) for(int j = 0; j <= i; j++) dp[i][j] = -INF;
		dp[0][0] = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j <= i; j++) {
				if(dp[i][j] >= 0) {
					mx(i+1, j+1, dp[i][j] + a[i].S + a[i].F * j, i, j); // want
					mx(i+1, j, dp[i][j] + a[i].F * (k - 1), i, j); //kill
				}
			}
		}
		int i = n, j = k;
		vi l, r;
		while(i) {
			int ii = from[i][j].F, jj = from[i][j].S;
			if(jj == j) { // kill
				r.PB(a[ii].i);
			} else { // want
				l.PB(a[ii].i);
			}
			i = ii, j = jj;
		}
		reverse(ALL(l)), reverse(ALL(r));
		vi ans;
		for(int i = 0; i < (int)l.size() - 1; i++) ans.PB(l[i]);
		for(int i:r) ans.PB(i), ans.PB(-i);
		ans.PB(l.back());
		cout << ans.size() << endl;
		for(int i:ans) cout << i << " ";
		cout << endl;
	}

}