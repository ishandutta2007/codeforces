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

char s[3333];

int num;
int ccnt[5555], c[5555];
int chk[5555];

char ans[2][3333];
VI adj[5555];
map<string, int> H;
int a[5555][1111];
int tp[5555];

int Hash(char *tok) {
	string temp = (string)tok;
	if (H.count(temp)) return H[temp];
	return H[temp] = ++num;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m; scanf("%d%d\n", &n, &m);
	for (int i = 1; i <= n; i++) {
		gets(s);
		int cnt = 0, an = 0, u, v = 0, w = 0;
		for (char *tok = strtok(s, " "); tok; tok = strtok(NULL, " ")) {
			cnt++;
			if (cnt == 2) continue;
			if (cnt == 1) {
				u = Hash(tok);
			} else if (cnt == 3) {
				if (isdigit(tok[0])) {
					for (int j = 0; j < m; j++) a[u][j] = tok[j] - '0';
				} else if (tok[0] == '?') {
					chk[u]++;
				} else {
					v = Hash(tok);
				}
			} else if (cnt == 4) {
				if (tok[0] == 'X') tp[u] = 0;
				if (tok[0] == 'A') tp[u] = 1;
				if (tok[0] == 'O') tp[u] = 2;
			} else if (cnt == 5) {
				if (tok[0] == '?') {
					chk[u]++;
				} else {
					w = Hash(tok);
				}
			}
		}
		if (v) adj[u].push_back(v);
		if (w) adj[u].push_back(w);
	}
	for (int i = 0; i < m; i++) {
		for (int k = 0; k < 2; k++) {
			ccnt[k] = 0;
			for (int j = 1; j <= n; j++) {
				if (adj[j].empty() && !chk[j]) {
					c[j] = a[j][i];
				} else if (chk[j] == 2) {
					if (tp[j] == 0) c[j] = 0;
					else c[j] = k;
				} else if (chk[j]) {
					int u = adj[j][0];
					if (tp[j] == 0) c[j] = c[u] ^ k;
					else if (tp[j] == 1) c[j] = c[u] & k;
					else c[j] = c[u] | k;
				} else {
					int u = adj[j][0], v = adj[j][1];
					if (tp[j] == 0) c[j] = c[u] ^ c[v];
					else if (tp[j] == 1) c[j] = c[u] & c[v];
					else c[j] = c[u] | c[v];
				}
				if (c[j]) ccnt[k]++;
			}
		}
		if (ccnt[0] == ccnt[1]) {
			ans[0][i] = ans[1][i] = '0';
			continue;
		}
		if (ccnt[0] > ccnt[1]) {
			ans[0][i] = '1', ans[1][i] = '0';
		} else {
			ans[1][i] = '1', ans[0][i] = '0';
		}
	}
	puts(ans[0]);
	puts(ans[1]);
	return 0;
}