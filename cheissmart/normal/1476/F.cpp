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

const int INF = 1e9 + 7, N = 3e5 + 7;

int p[N], dp[N], r[N], from[N], n, l[N];
int mx[N * 4], mn[N * 4];

void build_mx(int v = 1, int tl = 0, int tr = n + 1) {
	if(tr - tl == 1) {
		mx[v] = r[tl];
		return;
	}
	int tm = (tl + tr) / 2;
	build_mx(v * 2, tl, tm);
	build_mx(v * 2 + 1, tm, tr);
	mx[v] = max(mx[v * 2], mx[v * 2 + 1]);
}

int qry_mx(int l, int r, int v = 1, int tl = 0, int tr = n + 1) {
	if(l <= tl && tr <= r) return mx[v];
	int tm = (tl + tr) / 2, ans = -INF;
	if(l < tm) ans = max(ans, qry_mx(l, r, v * 2, tl, tm));
	if(r > tm) ans = max(ans, qry_mx(l, r, v * 2 + 1, tm, tr));
	return ans;
}

void build_mn(int v = 1, int tl = 0, int tr = n + 1) {
	if(tr - tl == 1) {
		mn[v] = INF;
		return;
	}
	int tm = (tl + tr) / 2;
	build_mn(v * 2, tl, tm);
	build_mn(v * 2 + 1, tm, tr);
	mn[v] = min(mn[v * 2], mn[v * 2 + 1]);
}

void upd_mn(int pos, int val, int v = 1, int tl = 0, int tr = n + 1) {
	if(tr - tl == 1) {
		mn[v] = min(mn[v], val);
		return;
	}
	int tm = (tl + tr) / 2;
	if(pos < tm) upd_mn(pos, val, v * 2, tl, tm);
	else upd_mn(pos, val, v * 2 + 1, tm, tr);
	mn[v] = min(mn[v * 2], mn[v * 2 + 1]);
}

int qry_mn(int l, int r, int v = 1, int tl = 0, int tr = n + 1) {
	if(l <= tl && tr <= r) return mn[v];
	int tm = (tl + tr) / 2, ans = INF;
	if(l < tm) ans = min(ans, qry_mn(l, r, v * 2, tl, tm));
	if(r > tm) ans = min(ans, qry_mn(l, r, v * 2 + 1, tm, tr));
	return ans;
}

void solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> p[i];
		r[i] = p[i] + i;
		l[i] = 0;
	}
	build_mx();
	build_mn();
	dp[0] = 0;
	upd_mn(dp[0], 0);
	for(int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1];
		if(dp[i - 1] >= i) {
			dp[i] = max(dp[i - 1], min(r[i], n));
			l[i] = -1;
			from[i] = i - 1;
		}
		int j = qry_mn(max(i - p[i] - 1, 0), i);
		if(j < i) {
			int nw = min(max(i - 1, qry_mx(j + 1, i)), n);
			if(nw > dp[i]) {
				dp[i] = nw;
				from[i] = j;
				l[i] = 1;
			}
		}
		if(dp[i] >= 0)
			upd_mn(dp[i], i);
 	}
	if(dp[n] == n) {
		cout << "YES" << '\n';
		string s(n, 'A');
		int i = n;
		while(i) {
			if(l[i] == 1) {
				s[i - 1] = 'L';
				for(int j = from[i] + 1; j < i; j++)
					s[j - 1] = 'R';
				i = from[i];
			} else if(l[i] == -1) {
				s[i - 1] = 'R';
				i = from[i];
			} else throw;
		}
		cout << s << '\n';
	} else {
		cout << "NO" << '\n';
	}
}

signed main()
{
	IO_OP;

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	
}