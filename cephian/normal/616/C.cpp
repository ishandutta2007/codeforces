#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int n,m;
string grid[1005];
int sz[1005][1005];
int idc = 0;
int id[1005][1005];

bool ok(int i, int j) {
	return i >= 0 && j >= 0 && i < n && j < m && (grid[i][j] != '*');
}

int dfs_count(int i, int j) {
	if(!ok(i,j) || id[i][j]) return 0;
	id[i][j] = idc;
	return 1+dfs_count(i+1,j) + dfs_count(i-1,j) + dfs_count(i,j+1) + dfs_count(i,j-1);
}

void dfs_fill(int i, int j, int v) {
	if(!ok(i,j) || sz[i][j]) return;
	sz[i][j] = v;
	dfs_fill(i+1,j,v);
	dfs_fill(i-1,j,v);
	dfs_fill(i,j+1,v);
	dfs_fill(i,j-1,v);
}

set<int> ids;
int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		cin >> grid[i];
		fill(sz[i],sz[i]+m,0);
		fill(id[i],id[i]+m,0);
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(grid[i][j] == '*' || id[i][j]) continue;
			++idc;
			int c = dfs_count(i,j);
			dfs_fill(i,j,c);
		}
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(grid[i][j] != '*') continue;
			int ans = 1;
			for(int k = 0; k < 4; ++k) {
				int x = i+d[k][0];
				int y = j+d[k][1];
				if(!ok(x,y)) continue;
				int idv = id[x][y];
				int cnt = sz[x][y];
				if(ids.count(idv)) continue;
				ids.insert(idv);
				ans += cnt;
			}
			grid[i][j] = '0'+(ans%10);
			ids.clear();
		}
	}
	for(int i = 0; i < n; ++i) {
		cout << grid[i] << "\n";
	}
	return 0;
}