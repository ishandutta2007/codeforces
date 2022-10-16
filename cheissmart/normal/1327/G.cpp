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

const int INF = 1e9 + 7, N = 1e3 + 7, K = 14;

struct AC {
	int ch[N][K], go[N][K], fail[N], val[N], cnt;
	AC() {
		memset(ch, 0, sizeof ch);
		memset(fail, 0, sizeof fail);
		memset(val, 0, sizeof val);
		cnt = 1;
	}
	void insert(string s, int cost) {
		int u = 0;
		for(char c:s) {
			int cc = c - 'a';
			if(ch[u][cc] == 0) {
				ch[u][cc] = cnt++;
			}
			u = ch[u][cc];
		}
		val[u] += cost;
	}
	void build_fail() {
		queue<int> q({0});
		while(q.size()) {
			int u = q.front(); q.pop();
			for(int c = 0; c < K; c++) {
				int v = ch[u][c];
				if(v) {
					q.push(v);
					fail[v] = go[fail[u]][c];
					val[v] += val[fail[v]];
					go[u][c] = v;
				} else {
					go[u][c] = go[fail[u]][c];
				}
			}
		}
	}
} ac;
 
ll dp1[N][1 << K]; // [node in ac][mask]
ll dp2[N][1 << K]; // [node in ac][mask]

signed main()
{
	IO_OP;

	int k;
	cin >> k;
	for(int i = 0; i < k; i++) {	
		string t;
		int c;
		cin >> t >> c;
		ac.insert(t, c);
	}
	ac.build_fail();
	string s;
	cin >> s;
	int u = 0, i = 0;
	ll add = 0;
	for(; i < s.size() && s[i] != '?'; i++) {
		u = ac.go[u][s[i] - 'a'];
		add += ac.val[u];
	}
	memset(dp1, 0xc0, sizeof dp1);
	dp1[u][0] = add;
	for(int a = 0; i < s.size(); a++) {
		// process '?'
		memset(dp2, 0xc0, sizeof dp2);
		for(int u = 0; u < ac.cnt; u++) {
			for(int mask = 0; mask < (1 << K); mask++) {
				if(__builtin_popcount(mask) == a) {
					for(int j = 0; j < K; j++) if((mask >> j & 1) == 0) {
						int nw_mask = mask | (1 << j);
						int v = ac.go[u][j];
						dp2[v][nw_mask] = max(dp2[v][nw_mask], dp1[u][mask] + ac.val[v]);
					}
				}
			}
		}
		// process 'a' ~ 'n'
		memset(dp1, 0xc0, sizeof dp1);
		i++;
		int j = i;
		for(; i < s.size() && s[i] != '?'; i++);
		for(int node = 0; node < ac.cnt; node++) {
			ll add = 0;
			int u = node;
			for(int l = j; l < i; l++) {
				u = ac.go[u][s[l] - 'a'];
				add += ac.val[u];
			}
			for(int mask = 0; mask < (1 << K); mask++)
				dp1[u][mask] = max(dp1[u][mask], dp2[node][mask] + add);
		}
	}
	ll ans = -1e18;
	for(int i = 0; i < ac.cnt; i++)
		for(int j = 0; j < (1 << K); j++)
			ans = max(ans, dp1[i][j]);
	cout << ans << endl;
}