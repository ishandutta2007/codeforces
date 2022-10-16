#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int K, n, m;
char a[11][11][11];
bool vis[11][11][11];

bool ok(int i, int j, int k) {
	if(i < 0 || i >= K) return false;
	if(j < 0 || j >= n) return false;
	if(k < 0 || k >= m) return false;
	return true;
}

void dfs(int i, int j, int k) {
	vis[i][j][k] = 1;
	int nxt[][3] = {
		{1, 0, 0},
		{-1, 0, 0},
		{0, 1, 0},
		{0, -1, 0},
		{0, 0, 1},
		{0, 0, -1}
	};
	for(int l=0;l<6;l++) {
		int ni = i + nxt[l][0],
			nj = j + nxt[l][1],
			nk = k + nxt[l][2];
		if(ok(ni, nj, nk) && a[ni][nj][nk] == '.' && vis[ni][nj][nk] == 0) {
			dfs(ni, nj, nk);
		}
	}
}

int main()
{
	IO_OP;

	cin >> K >> n >> m;
	for(int i=0;i<K;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<m;k++)
				cin >> a[i][j][k];
	int x, y;
	cin >> x >> y;
	x--, y--;
	dfs(0, x, y);
	int ans = 0;
	for(int i=0;i<K;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<m;k++)
				if(vis[i][j][k])
					ans++;
	cout << ans << endl;
}