#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)
#define boost cin.tie(0);ios_base::sync_with_stdio(0);
#define vi vector <int>

using namespace std;

const int nax = 2100;
const int INF = 1e9 + 111;

int n, m;
int r, c;
int x, y;

char s[nax][nax];

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool in(int row, int col) {
	return 1 <= row && row <= n && 1 <= col && col <= m;
}

int dp[nax][nax][2];
bool odw[nax][nax][2];

deque <pair<pair<int, int>, pair<int, int>>> q;

int main() {	
	scanf ("%d%d", &n, &m);
	scanf ("%d%d", &r, &c);
	scanf ("%d%d", &x, &y);
	
	rep(i, 1, n) scanf ("%s", s[i] + 1);
	
	rep(i, 1, n) rep(j, 1, m) dp[i][j][0] = dp[i][j][1] = INF;
	
	dp[r][c][0] = dp[r][c][1] = 0;
	
	q.pb({{0, 0}, {r, c}});
	
	while (ss(q)) {
		int r = q.front().se.fi;
		int c = q.front().se.se;
		int d = q.front().fi.se;
		q.pop_front();
		if (odw[r][c][d]) continue;
		odw[r][c][d] = 1;
		
		rep(g, 0, 3) {
			int nr = r + dx[g];
			int nc = c + dy[g];
			if (!in(nr, nc) || s[nr][nc] == '*') continue;
			
			int cost = dp[r][c][0] + (g == 3);
			
			if (dp[nr][nc][0] > cost) {
				dp[nr][nc][0] = cost;
				if (cost != dp[r][c][0])
					q.pb({{-cost, 0}, {nr, nc}});
				else
					q.push_front({{-cost, 0}, {nr, nc}});
			}
		}
	}
	
	q.pb({{0, 1}, {r, c}});
	
	while (ss(q)) {
		int r = q.front().se.fi;
		int c = q.front().se.se;
		int d = q.front().fi.se;
		q.pop_front();
		if (odw[r][c][d]) continue;
		odw[r][c][d] = 1;
		
		rep(g, 0, 3) {
			int nr = r + dx[g];
			int nc = c + dy[g];
			if (!in(nr, nc) || s[nr][nc] == '*') continue;
			
			int cost = dp[r][c][1] + (g == 2);
			
			if (dp[nr][nc][1] > cost) {
				dp[nr][nc][1] = cost;
				if (cost != dp[r][c][1])
					q.pb({{-cost, 1}, {nr, nc}});
				else
					q.push_front({{-cost, 1}, {nr, nc}});
			}
		}
	}
	
	int ans = 0;
	rep(i, 1, n) rep(j, 1, m) {
		//printf ("%d %d %d %d\n", i, j, dp[i][j][0], dp[i][j][1]);
	//	int old = ans;
		if (j <= c) {
			ans += (dp[i][j][1] <= y && (c - j + dp[i][j][1]) <= x);
		}
		else {
			ans += (dp[i][j][0] <= x && (j - c + dp[i][j][0] <= y));
		}
		//if (ans ^ old) printf ("%d %d\n", i, j);
	}
	printf ("%d", ans);
	
	
	
	
	return 0;
}