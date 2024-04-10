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

const int INF = 1e9 + 7, N = 1e5 + 7;

vi G[N], who[N];
int cnt[N], cnt2[N], mx_depth;

void dfs(int u, int depth = 0) {
	mx_depth = max(mx_depth, depth);
	cnt[depth]++;
	who[depth].PB(u);
	for(int v:G[u]) dfs(v, depth + 1);
}

signed main()
{
	IO_OP;

	int n, x;
	cin >> n >> x;
	for(int i = 2; i <= n; i++) {
		int p;
		cin >> p;
		G[p].PB(i);
	}
	dfs(1);
	for(int i = 0; i < n; i++)
		if(cnt[i])
			cnt2[cnt[i]]++;
	vi dp(n + 1);
	V<pi> from(n + 1);
	dp[0] = 1;
	for(int i = 1; i <= n; i++) if(cnt2[i]) { // this if is true for at most sqrt(n) times
		vi new_dp = dp;
		vi lst(i, -1);
		for(int j = 0; j <= n; j++) {
			int k = j % i;
			if(lst[k] != -1 && (j - lst[k]) / i <= cnt2[i]) {
				new_dp[j] = 1;
				if(from[j] == MP(0, 0))
					from[j] = {i, (j - lst[k]) / i};
			}
			if(dp[j]) lst[k] = j;
		}
		swap(dp, new_dp);
	}
	if(dp[x]) {
		vi need(n + 1);
		while(x) {
			pi p = from[x];
			x -= p.F * p.S;
			need[p.F] = p.S;
		}
		string ans(n, 'b');
		for(int i = 0; i < n; i++) if(need[cnt[i]]) {
			need[cnt[i]]--;
			for(int u:who[i])
				ans[u - 1] = 'a';
		}
		cout << mx_depth + 1 << '\n';
		cout << ans << '\n';
	} else {
		int a = x, b = n - x;
		string ans(n, 'c');
		for(int i = 0; i < n; i++) {
			if(who[i].empty()) break;
			if(who[i].size() <= a) {
				for(int u:who[i])
					ans[u - 1] = 'a', a--;
			} else if(who[i].size() <= b) {
				for(int u:who[i])
					ans[u - 1] = 'b', b--;
			} else {
				for(int u:who[i]) if(G[u].empty()) {
					if(min(a, b) == 0) break;
					if(a <= b)
						ans[u - 1] = 'a', a--;
					else
						ans[u - 1] = 'b', b--;
				}
				assert(a == 0 || b == 0);
				for(int u:who[i]) if(ans[u - 1] == 'c') {
					if(a) ans[u - 1] = 'a', a--;
					else if(b) ans[u - 1] = 'b', b--;
				}
			}
		}
		cout << mx_depth + 2 << '\n';
		cout << ans << '\n';
	}
}