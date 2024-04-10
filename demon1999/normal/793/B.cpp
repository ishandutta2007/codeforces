#include <bits/stdc++.h>  
using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define fi first
#define mp make_pair
#define se second
#define sz(a) (int)a.size()
#define prev previ
#define tm tmmm
#define div divv
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const ll mod = ll(1e9) + 7;
const int ma = 1024 * 1024 * 2;

int n, m, use[1100][1100][4][3];
string s[2000];
int xx[4] = {1, 0, -1, 0}, yy[4] = {0, 1, 0, -1};

bool ok(int a, int b, int np, int o) {
	re a >= 0 && b >= 0 && a < n && b < m && s[a][b] == '.' && use[a][b][np][o] == 0;
}
void dfs(int x, int y, int np, int k) {
	use[x][y][np][k] = 1;
	forn (np1, 4) {
		int o = 0;
		if (np1 != np) o++;
		if (k + o < 3 && ok(x + xx[np1], y + yy[np1], np1, k + o)) {
			dfs(x + xx[np1], y + yy[np1], np1, k + o);
		}
	}
}
int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	scanf("%d%d", &n, &m);
	int ax, ay, bx, by;
	forn (i, n) {
		char c = getchar();
		while (c != 'S' && c != 'T' && c != '.' && c != '*')
			c = getchar();
		s[i] = "";
		while (!(c != 'S' && c != 'T' && c != '.' && c != '*')) {
			s[i] += c; c = getchar();
		}
		forn (j, sz(s[i])) {
			if (s[i][j] == 'S') {
				s[i][j] = '.';
				ax = i; ay = j;
			}
			if (s[i][j] == 'T') {
				s[i][j] = '.';
				bx = i;
				by = j;
			}
		}
	}
	forn (i, 4) {
		if (!use[ax][ay][i][0])
			dfs(ax, ay, i, 0);
	}
	forn (i, 4) {
		forn (j, 3)
			if (use[bx][by][i][j]) {
				cout << "YES\n";
				re 0;
			}
	}
	cout << "NO\n";
	re 0;
}