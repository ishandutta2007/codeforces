#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define int ll
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, K = 500, N = 3e5 + 7;

int ddp[6][6][6][K][3], stt[6][6][6], lenn[6][6][6], p[N], s[N], a[N];

void pre(int x, int y, int z) {
	int dp[K][3];
	memset(dp, 0, sizeof dp);
	for(int i=1;i<K;i++) {
		{
			set<int> s;
			s.insert(dp[max(0LL, i-x)][0]);
			s.insert(dp[max(0LL, i-y)][1]);
			s.insert(dp[max(0LL, i-z)][2]);
			for(int j=0;j<10;j++) {
				if(s.count(j) == 0) {
					dp[i][0] = j;
					break;
				}
			}
		}
		{
			set<int> s;
			s.insert(dp[max(0LL, i-x)][0]);
			// s.insert(dp[max(0LL, i-y)][1]);
			s.insert(dp[max(0LL, i-z)][2]);
			for(int j=0;j<10;j++) {
				if(s.count(j) == 0) {
					dp[i][1] = j;
					break;
				}
			}
		}
		{
			set<int> s;
			s.insert(dp[max(0LL, i-x)][0]);
			s.insert(dp[max(0LL, i-y)][1]);
			// s.insert(dp[max(0LL, i-z)][2]);
			for(int j=0;j<10;j++) {
				if(s.count(j) == 0) {
					dp[i][2] = j;
					break;
				}
			}
		}
	}
	int st=0, len = -1;
	map<array<array<int, 3>, 6>, int> cnt;
	for(int i=200;i<K;i++) {
		array<array<int, 3>, 6> cur = {(array<int, 3>){dp[i][0], dp[i][1], dp[i][2]},
										(array<int, 3>){dp[i-1][0], dp[i-1][1], dp[i-1][2]},
										(array<int, 3>){dp[i-2][0], dp[i-2][1], dp[i-2][2]},
										(array<int, 3>){dp[i-3][0], dp[i-3][1], dp[i-3][2]},
										(array<int, 3>){dp[i-4][0], dp[i-4][1], dp[i-4][2]},
										(array<int, 3>){dp[i-5][0], dp[i-5][1], dp[i-5][2]}};
		if(cnt.count(cur)) {
			st = cnt[cur];
			len = i - st;
			break;
		}
		cnt[cur] = i;
	}
	assert(len != -1);
	for(int i=0;i<K;i++)
		for(int j=0;j<3;j++)
			ddp[x][y][z][i][j] = dp[i][j];
	stt[x][y][z] = st, lenn[x][y][z] = len;
}

void solve() {
	int n, x, y, z;
	cin >> n >> x >> y >> z;
	for(int i=0;i<=n+1;i++) p[i] = s[i] = 0;
	for(int i=1;i<=n;i++) cin >> a[i];
	int st = stt[x][y][z], len = lenn[x][y][z];
	for(int i=1;i<=n;i++) {
		int cur;
		if(a[i] < K) cur = ddp[x][y][z][a[i]][0];
		else cur = ddp[x][y][z][(a[i] - st) % len + st][0];
		p[i] = p[i-1] ^ cur;
	}
	for(int i=n;i>=1;i--) {
		int cur;
		if(a[i] < K) cur = ddp[x][y][z][a[i]][0];
		else cur = ddp[x][y][z][(a[i] - st) % len + st][0];
		s[i] = s[i+1] ^ cur;
	}
	int ans = 0;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<3;j++) {
			int cur;
			int tt = a[i];
			if(j == 0) tt = max(0LL, tt - x);
			if(j == 1) tt = max(0LL, tt - y);
			if(j == 2) tt = max(0LL, tt - z);
			if(tt < K) cur = ddp[x][y][z][tt][j];
			else cur = ddp[x][y][z][(tt - st) % len + st][j];
			int sg = cur ^ p[i-1] ^ s[i+1];
			if(sg == 0) ans++;
			// debug(i);
			// debug(j);
			// debug(sg);
		}
	}
	cout << ans << endl;
}

signed main()
{
	IO_OP;
	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++)
			for(int k=1;k<=5;k++)
				pre(i, j, k);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}

}