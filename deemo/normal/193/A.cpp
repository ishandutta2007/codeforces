#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN = 50 + 3;

int n, m, zz;
char c[MAXN][MAXN];
bool del[MAXN][MAXN], vis[MAXN][MAXN];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

bool fit(int a, int b){return 0 <= a && a < n && 0 <= b && b < m && !del[a][b];}

void dfs(int a, int b){
	if (vis[a][b])	return;
	vis[a][b] = 1;
	zz++;
	for (int i = 0; i < 4; i++)
		if (fit(a + dx[i], b + dy[i]) && c[a + dx[i]][b + dy[i]] == '#')
			dfs(a + dx[i], b + dy[i]);
}

int main(){
	cin >> n >> m;
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			cin >> c[i][j];
			if (c[i][j] == '#')
				cnt++;
		}
	
	if (cnt < 3){
		printf("-1\n");
		return 0;
	}

	int ans = 1e9;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (c[i][j] == '#'){
				int ret = 0;
				for (int ii = -1; ii <= 1; ii++)
					for (int jj = -1; jj <= 1; jj++)
						if (abs(ii) + abs(jj) == 1 && fit(i + ii, j + jj))
							ret += int(c[i + ii][j + jj] == '#');
				ans = min(ans, ret);
			}

	pair<int, int> a(-1, -1), b(-1, -1);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (c[i][j] == '#'){
				if (a.first == -1)
					a = {i, j};
				else
					b = {i, j};
			}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (c[i][j] == '#'){
				del[i][j] = 1;
				zz = 0;
				memset(vis, 0, sizeof(vis));
				if (a.first == i && a.second == j)
					dfs(b.first, b.second);
				else
					dfs(a.first, a.second);
				if (zz != cnt - 1){
					ans = 1;
					printf("%d\n", ans);
					return 0;
				}
				del[i][j] = 0;
			}
	cout << ans << endl;
	return 0;
}