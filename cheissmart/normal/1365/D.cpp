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

const int INF = 1e9 + 7, N = 55;

char a[N][N];
bool vis[N][N];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int n, m;

void dfs(int x, int y) {
	vis[x][y] = 1;
	for(int k = 0; k < 4; k++) {
		int xx = x + dx[k], yy = y + dy[k];
		if(xx >= 0 && xx < n && yy >= 0 && yy < m && a[xx][yy] != '#' && !vis[xx][yy])
			dfs(xx, yy);
	}
}

bool solve() {
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> a[i][j];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(a[i][j] == 'B') {
				for(int k = 0; k < 4; k++) {
					int ii = i + dx[k], jj = j + dy[k];
					if(ii >= 0 && ii < n && jj >= 0 && jj < m) {
						if(a[ii][jj] == 'G') {
							return false;
						} else if(a[ii][jj] == '.') {
							a[ii][jj] = '#';
						}
					}
				}
			}
		}
	}
	// for(int i = 0; i < n; i++) {
	// 	for(int j = 0; j < m; j++) {
	// 		cout << a[i][j];
	// 	}
	// 	cout << endl;
	// }
	memset(vis, 0, sizeof vis);
	if(a[n-1][m-1] != '#') dfs(n-1, m-1);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if((a[i][j] == 'G' && !vis[i][j]) || (a[i][j] == 'B' && vis[i][j]))
				return false;
		}
	}
	return true;
}

signed main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		cout << (solve() ? "YES" : "NO") << endl;
	}	
	
}