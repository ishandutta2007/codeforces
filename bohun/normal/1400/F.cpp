#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int) x.size()
#define cat(x) cerr << #x << " = " << x << endl
#define all(x) x.begin(), x.end()
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
 
using ll = long long;
using ld = long double;
using namespace std;

const int N = 1024;
const int M = 2e5;

int n, x;
char s[N];		
vector <int> g;

bool mark[M];
int cnt, fail[M], go[M][10];
void add() {
	int v = 0;
	for (auto x : g) {
		if (!go[v][x])
			go[v][x] = ++cnt;
		v = go[v][x];
	}
	mark[v] = true;
}

queue <int> q;

void build() {
	q.push(0);
	while (!q.empty()) {
		int v = q.front();
		//~ mark[v] |= mark[fail[v]];
		q.pop();
		rep(i, 1, 9) {
			if (go[v][i]) {
				q.push(go[v][i]);
				fail[go[v][i]] = v ? go[fail[v]][i] : 0;
			}
			else go[v][i] = go[fail[v]][i];
		}
	}
}		

void generate(int sum) {
	if (sum == x) {
		rep(l, 0, sz(g) - 1) {
			int s = 0;
			rep(r, l, sz(g) - 1) {
				s += g[r];
				if (x != s && x % s == 0)
					return;
			}
		}
		add();
		return;
	}
	rep(i, 1, min(9, x - sum)) {
		g.pb(i);
		generate(sum + i);
		g.pop_back();
	}
}			
		
int dp[M], ndp[M];
 
int main() {
	scanf ("%s%d", s + 1, &x);
	n = strlen(s + 1);
	generate(0);
	build();
	fill(dp + 1, dp + M, n);
	rep(i, 1, n) {
		int c = s[i] - '0';
		fill(ndp, ndp + M, n);
		rep(j, 0, cnt) {
			if (!mark[go[j][c]])
				ndp[go[j][c]] = min(ndp[go[j][c]], dp[j]);
			ndp[j] = min(ndp[j], dp[j] + 1);
		}
		swap(dp, ndp);
	}
	int ans = n;
	rep(j, 0, cnt) ans = min(ans, dp[j]);
	printf ("%d\n", ans);
	return 0;
}