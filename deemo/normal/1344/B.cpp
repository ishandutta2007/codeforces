#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 1e9 + 7;//XXX
const int C = 26;//XXX

void add(int &x, int y){
	x += y;
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
}

int fix(int x){
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
	return x;
}

int pw(int a, int b){
	int ret = 1;
	while (b){
		if (b & 1)
			ret = 1ll*ret*a%MOD;
		b >>= 1;
		a = 1ll*a*a%MOD;
	}
	return ret;
}

const int MAXN = 1e3 + 10;

int n, m;
string s[MAXN];

void fail() {
	cout << "-1\n";
	exit(0);
}

bool vis[MAXN][MAXN];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool fit(int r, int c) { return 0 <= r && r < n && 0 <= c && c < m && s[r][c] == '#'; }

void dfs(int r, int c) {
	if (vis[r][c]) return;
	vis[r][c] = true;

	for (int w = 0; w < 4; w++)
		if (fit(r + dx[w], c + dy[w]))
			dfs(r + dx[w], c + dy[w]);
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> s[i];

	int mask = 0;
	for (int r = 0; r < n; r++) {
		bool sn = false;
		for (int c = 0; c < m; c++) {
			if (s[r][c] == '#') {
				if (sn && c && s[r][c-1] == '.')  fail();
				sn = true;
			}
		}
		if (!sn)
			mask |= 1;
	}
	for (int c = 0; c < m; c++) {
		bool sn = false;
		for (int r = 0; r < n; r++) {
			if (s[r][c] == '#') {
				if (sn && r && s[r-1][c] == '.') fail();
				sn = true;
			}
		}
		if (!sn)
			mask |= 2;
	}
	if (mask && mask != 3)
		fail();
	
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (s[i][j] == '#' && !vis[i][j])
				dfs(i, j), ans++;
	cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	//cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}