#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

char a[100][100];
bool vis[100][100];
int n;

void dfs(int r, int c, vector<pi>& v) {
	vis[r][c] = 1;
	v.PB({r, c});
	int d[4][2] = {
		{1, 0},{-1, 0},{0, 1},{0, -1}
	};
	for(int i=0;i<4;i++) {
		int nr = r + d[i][0], nc = c + d[i][1];
		if(nc > 0 && nc <= n && nr > 0 && nr <= n &&  a[nr][nc] == '0' &&  vis[nr][nc] == 0)
			dfs(nr, nc, v);
	}
}

int main()
{
	IO_OP;
	
	cin >> n;
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin >> a[i][j];
	
	vector<pi> v1, v2;
	dfs(r1, c1, v1);
	dfs(r2, c2, v2);
	int ans = INF;
	for(auto p1:v1) {
		for(auto p2:v2) {
			ans = min(ans, (p1.F-p2.F)*(p1.F-p2.F) + (p1.S-p2.S)*(p1.S-p2.S));
		}
	}
	cout << ans << endl;
}