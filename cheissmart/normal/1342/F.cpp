#include <bits/stdc++.h>
#define IO_OP ios::sync_with_stdio(0), cin.tie(0)
#define F first
#define S second
#define V vector
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(v) int((v).size())
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

array<int, 3> trans[1 << 15][16][16];
int dp[1 << 15][16][16];

void solve() {
	int n; cin >> n;
	vi a(n); for(int& i:a) cin >> i;
	
	//V<V<V<array<int, 3>>>> trans(1 << n, V<V<array<int, 3>>>(n + 1, V<array<int, 3>>(n + 1)));
	//V<V<vi>> dp(1 << n, V<vi>(n + 1, vi(n + 1, INF)));
	for(int i = 0; i < (1 << n); i++)
		for(int j = 0; j <= n; j++)
			for(int k = 0; k <= n; k++)
				dp[i][j][k] = INF;
	
	vi sum(1 << n);
	for(int i = 0; i < (1 << n); i++) 
		for(int j = 0; j < n; j++) if(i >> j & 1)
			sum[i] += a[j];
			
	V<vi> next_ok(1 << n, vi(n + 1, -1));
	for(int i = 1; i < (1 << n); i++)
		for(int j = 0; j <= n; j++)
			for(int k = j; k < n; k++)
				if(i >> k & 1) {
					next_ok[i][j] = k;
					break;
				}

	dp[0][0][0] = 0;
	for(int i = 0; i < (1 << n); i++) {
		int cnt = __builtin_popcount(i);
		for(int j = 0; j <= cnt; j++) {
			for(int k = j; k <= n; k++) {
				if(k && dp[i][j][k - 1] < dp[i][j][k]) {
					dp[i][j][k] = dp[i][j][k - 1];
					trans[i][j][k] = trans[i][j][k - 1];
				}
				if(dp[i][j][k] == INF) continue;
				int comp = ((1 << n) - 1) ^ i;
				for(int l = comp; l; l = (l - 1) & comp) {
					if(dp[i][j][k] < sum[l] && next_ok[l][k] != -1) {
						if(sum[l] < dp[i | l][j + 1][next_ok[l][k] + 1]) {
							dp[i | l][j + 1][next_ok[l][k] + 1] = sum[l];
							trans[i | l][j + 1][next_ok[l][k] + 1] = {i, j, k};
						}
					}
				}
			}
		}
	}
	int mx = 0;
	for(int j = 0; j <= n; j++)
		for(int k = 0; k <= n; k++)
			if(dp[(1 << n) - 1][j][n] < INF) {
				mx = j;
			}
			
	vi p(n); iota(ALL(p), 0);
	auto add = [&] (int x, int y) {
		int pos_x = int(find(ALL(p), x) - p.begin());
		int pos_y = int(find(ALL(p), y) - p.begin());
		p.erase(find(ALL(p), x));
		cout << pos_x + 1 << ' ' << pos_y + 1 << '\n';
	};
			
	cout << n - mx << '\n';
	int i = (1 << n) - 1, j = mx, k = n, lst = n;
	while(i) {
		int take = trans[i][j][k][0] ^ i;
		int who = -1;
		for(int l = 0; l < n; l++)
			if(take >> l & 1)
				if(l < lst)
					who = l;		
		assert(who != -1);
		for(int l = 0; l < n; l++)
			if(take >> l & 1)
				if(l != who)
					add(l, who);
		lst = who;
		auto tt = trans[i][j][k];
		i = tt[0], j = tt[1], k = tt[2];
	}
	
}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) solve();
	
}