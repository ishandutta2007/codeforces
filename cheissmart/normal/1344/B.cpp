#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 1003;

char a[N][N];
bool hasl[N][N], hasr[N][N], hasu[N][N], hasd[N][N], vis[N][N];

void no() {
	cout << -1 << endl;
	exit(0);
}

int d[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m;

void dfs(int i, int j) {
	vis[i][j] = 1;
	for(int k = 0; k < 4; k++) {
		int ii = i + d[k][0];
		int jj = j + d[k][1];
		if(ii >= 0 && jj >= 0 && ii < n && jj < m && a[ii][jj] == '#' && !vis[ii][jj])
			dfs(ii, jj);
	}
}

signed main()
{
	IO_OP;
	
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	for(int i = 0; i < n; i++) {
		bool yes = false;
		for(int j = 0; j < m; j++) {
			if(a[i][j] == '.')
				hasl[i][j] = yes;
			else
				yes = true;
		}
	}

	for(int i = 0; i < n; i++) {
		bool yes = false;
		for(int j = m - 1; j >= 0; j--) {
			if(a[i][j] == '.')
				hasr[i][j] = yes;
			else
				yes = true;
		}
	}

	for(int j = 0; j < m; j++) {
		bool yes = false;
		for(int i = 0; i < n; i++) {
			if(a[i][j] == '.')
				hasu[i][j] = yes;
			else
				yes = true;
		}
	}

	for(int j = 0; j < m; j++) {
		bool yes = false;
		for(int i = n - 1; i >= 0; i--) {
			if(a[i][j] == '.')
				hasd[i][j] = yes;
			else
				yes = true;
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] == '.') {
				if(hasl[i][j] && hasr[i][j]) no();
				if(hasu[i][j] && hasd[i][j]) no();
			}
		}
	}
	for(int i = 0; i < n; i++) {
		int cnt = 0;
		for(int j = 0; j < m; j++) {
			cnt += a[i][j] == '#';
		}
		if(cnt) continue;
		bool ok = false;
		for(int j = 0; j < m; j++) {
			if(hasu[i][j] == 0 && hasd[i][j] == 0) {
				ok = true;
				break;
			}
		}
		if(!ok) no();
	}
	for(int j = 0; j < m; j++) {
		int cnt = 0;
		for(int i = 0; i < n; i++) {
			cnt += a[i][j] == '#';
		}
		if(cnt) continue;
		bool ok = false;
		for(int i = 0; i < n; i++) {
			if(hasl[i][j] == 0 && hasr[i][j] == 0) {
				ok = true;
				break;
			}
		}
		if(!ok) no();
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] == '#' && !vis[i][j]) {
				dfs(i, j);
				ans++;
			}
		}
	}
	cout << ans << endl;
}