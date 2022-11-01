#include <bits/stdc++.h>


using namespace std;

#define re return
#define sz(a) (int)a.size()
#define mp(a, b) make_pair(a, b)
#define fi first
#define se second
#define re return
#define forn(i, n) for (int i = 0; i < int(n); i++)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;
const int mod = 1e9 + 7;

ll n;
int qx[8] = {1, 1, 0, -1, -1, -1, 0, 1}, qy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
bool use[302][302][8][30], ok[302][302];
vector<int> t;

void dfs(int x, int y, int np, int i) {
	if (i == n) re;
	if (use[x][y][np][i])re;
	use[x][y][np][i] = 1;
	//ok[x][y] = 1;
	forn (j, t[i]) {
		x += qx[np];
		y += qy[np];
		ok[x][y] = 1;
	}
	dfs(x, y, (np + 1) % 8, i + 1);
	dfs(x, y, (np + 7) % 8, i + 1);
}
int main() {
	iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("a.in", "r", stdin);
	cin >> n;
	t.resize(n);
	forn (i, n) {
		cin >> t[i];
	}
	/*forn (i, 8) {
		cout << qx[i] << " " << qy[i] << "\n";
	}*/
	dfs(150, 150, 0, 0);
	int ans = 0;
	forn (j, 301)
		forn (k, 301)
			if (ok[j][k])
				ans++;
	cout << ans;
	re 0;
}