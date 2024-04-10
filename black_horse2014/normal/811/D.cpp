#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef double DB;

#define pb push_back
#define mset(a, b) memset(a, b, sizeof a)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))
#define cnti(x) (__builtin_popcount(x))
#define cntl(x) (__builtin_popcountll(x))
#define clzi(x) (__builtin_clz(x))
#define clzl(x) (__builtin_clzll(x))
#define ctzi(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))

#define X first
#define Y second

#define Error(x) cout << #x << " = " << x << endl

template <typename T, typename U>
inline void chkmax(T& x, U y) {
	if (x < y) x = y;
}

template <typename T, typename U>
inline void chkmin(T& x, U y) {
	if (y < x) x = y;
}

const char pat[] = "LRUD";
int n, m;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

bool out(int x, int y) {
	return x < 1 || x > n || y < 1 || y > m;
}

int d[111][111], q[22222], prv[111][111];
char s[111][111];
int ex, ey;
int S[111][111];

pair<int, int> go(int dir) {
	cout << pat[dir] << endl;
	int x, y; scanf("%d%d", &x, &y);
	return make_pair(x, y);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", s[i]+1);
		for (int j = 1; j <= m; j++) {
			if (s[i][j] == 'F') ex = i, ey = j;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i][j] == '*') continue;
			int T = 0;
			for (int k = 0; k < 4; k++) {
				int x = i + dx[k], y = j + dy[k];
				if (out(x, y) || s[x][y] != '*') T |= bit(k);
			}
			int cnt[2] = {0, 0};
			for (int k = 0; k < 2; k++) {
				if (T >> (k*2) & 1) cnt[k]++;
				if (T >> (k*2+1) & 1) cnt[k]++;
				if (cnt[k] == 2) S[i][j] |= bit(k);
			}
		}
	}
	int curx = 1, cury = 1;
	int flg[2] = {-1, -1};
	if (m == 1) flg[0] = 0;
	if (n == 1) flg[1] = 0;
	if (!~flg[0] && (S[1][1] & 1)) {
		pair<int, int> ans = go(1);
		if (ans.first - curx == dx[1] && ans.second - cury == dy[1]) flg[0] = 0, go(0);
		else flg[0] = 1, go(1);
	}
	if (!~flg[1] && (S[1][1] & 2)) {
		pair<int, int> ans = go(3);
		if (ans.first - curx == dx[3] && ans.second - cury == dy[3]) flg[1] = 0, go(2);
		else flg[1] = 1, go(3);
	}
	if (!~flg[0]) {
		for (int i = 1; i <= n; i++) {
			curx = i, cury = 1;
			if (S[i][1] & 1) {
				pair<int, int> ans = go(1);
				if (ans.first - curx == dx[1] && ans.second - cury == dy[1]) flg[0] = 0, go(0);
				else flg[0] = 1, go(1);
				break;
			}
			go(3 ^ flg[1]);
		}
	}
	else if (!~flg[1]) {
		for (int i = 1; i <= m; i++) {
			curx = 1, cury = i;
			if (S[1][i] & 2) {
				pair<int, int> ans = go(3);
				if (ans.first - curx == dx[3] && ans.second - cury == dy[3]) flg[1] = 0, go(2);
				else flg[1] = 1, go(3);
				break;
			}
			go(1 ^ flg[0]);
		}
	}
	int qn = 0;
	q[qn++] = curx, q[qn++] = cury;
	for (int i = 0; i < qn; i += 2) {
		int x = q[i], y = q[i+1];
		if (x == ex && y == ey) break;
		for (int j = 0; j < 4; j++) {
			int xx = x + dx[j], yy = y + dy[j];
			if (out(xx, yy) || s[xx][yy] == '*') continue;
			if (d[xx][yy]) continue;
			d[xx][yy] = d[x][y] + 1;
			q[qn++] = xx, q[qn++] = yy;
			prv[xx][yy] = j;
		}
	}
	vector<char> ret;
	while (ex != curx || ey != cury) {
		ret.push_back(prv[ex][ey]);
		int k = prv[ex][ey];
		ex -= dx[k], ey -= dy[k];
	}
	reverse(all(ret));
	for (int i = 0; i < sz(ret); i++) go(ret[i]^flg[ret[i]/2]);
	return 0;
}