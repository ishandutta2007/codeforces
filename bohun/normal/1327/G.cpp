#include <bits/stdc++.h>
#define LL long long
#define LD long double
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

const int K = 1010;
const int N = 4e5 + 10;
const LL INF = 1e18;

int n, cost;
char t[K], s[N];

int cnt;
int go[K][14];
int link[K];
int sum[K];

void add() {
	int m = strlen(t);
	int v = 0;
	rep(i, 0, m - 1) {
		int c = t[i] - 'a';
		if (!go[v][c]) go[v][c] = ++cnt;
		v = go[v][c];
	}
	sum[v] += cost;
}

vector <int> g[K];
queue <int> q;

void aho() {
	q.push(0);
	while (ss(q)) {
		int v = q.front();
		q.pop();
		if (v != 0) g[link[v]].pb(v);
		rep(i, 0, 13) {
			if (go[v][i]) {
				q.push(go[v][i]);
				link[go[v][i]] = (v == 0 ? 0 : go[link[v]][i]);
			}
			else {
				go[v][i] = go[link[v]][i];
			}
		}
	}
}
	
LL f[K];

void dfs(int v, LL s) {
	s += sum[v];
	f[v] = s;
	for (auto it : g[v])
		dfs(it, s);
}

LL dp[K][1 << 14][2];
vector <int> masks[14];

int main() {	
	rep(mask, 0, (1 << 14) - 1)
		masks[__builtin_popcount(mask)].pb(mask);
	scanf ("%d", &n);
	rep(i, 1, n) {
		scanf ("%s", t);
		scanf ("%d", &cost);
		add();
	}
	aho();
	dfs(0, 0);
	scanf ("%s", s + 1);
	int m = strlen(s + 1);
	rep(i, 1, cnt) dp[i][0][0] = -INF;
	int d = 0;
	for (int i = 1; i <= m;) {
		if (s[i] == '?') {
			rep(j, 0, cnt) for (auto mask : masks[d + 1]) dp[j][mask][1] = -INF;
			rep(j, 0, cnt) for (auto mask : masks[d]) rep(c, 0, 13) {
				if ((mask >> c) & 1) continue;
				int nmask = mask ^ (1 << c);
				int v = go[j][c];
				dp[v][nmask][1] = max(dp[v][nmask][1], dp[j][mask][0] + f[v]);
			}
			rep(j, 0, cnt) for (auto mask : masks[d + 1]) dp[j][mask][0] = dp[j][mask][1];
			d++;
			i++;
		}
		else {
			rep(j, 0, cnt) for (auto mask : masks[d]) dp[j][mask][1] = -INF;
			rep(j, 0, cnt) {
				int v = j;
				int e = i;
				LL sq = 0;
				while (e <= m && s[e] != '?') {
					v = go[v][s[e] - 'a'];
					sq += f[v];
					e++;
				}
				for (auto mask : masks[d])
					dp[v][mask][1] = max(dp[v][mask][1], dp[j][mask][0] + sq);
				if (j == cnt) i = e;
			}
			rep(j, 0, cnt) for (auto mask : masks[d]) dp[j][mask][0] = dp[j][mask][1];		
		}
	}
	LL best = -INF;
	rep(i, 0, cnt) for (auto mask : masks[d]) best = max(best, dp[i][mask][1]);
	printf ("%lld\n", best);
	
	return 0;
}