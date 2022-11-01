#include <bits/stdc++.h>

using namespace std;

int n, m;

int mp[55][55];

int f[55][55][55][55];

int dfs(int x, int y, int a, int b){
	f[x][y][a][b] = max(a - x + 1, b - y + 1);
	if(x == a and y == b){
		if(!mp[x][y]){
			f[x][y][a][b] = 0;
		}
		return 0;
	}
	
	for(int i=x;i<a;i++){
		if(f[x][y][i][b] == -1)dfs(x, y, i, b);
		if(f[i + 1][y][a][b] == -1)dfs(i + 1, y, a, b);
		f[x][y][a][b] = min(f[x][y][a][b], f[x][y][i][b] + f[i + 1][y][a][b]);
	}
	
	for(int i=y;i<b;i++){
		if(f[x][y][a][i] == -1)dfs(x, y, a, i);
		if(f[x][i + 1][a][b] == -1)dfs(x, i + 1, a, b);
		f[x][y][a][b] = min(f[x][y][a][b], f[x][y][a][i] + f[x][i + 1][a][b]);
	}
	
	return 0;
}

int main(){
	int i, j;
	memset(f, -1, sizeof(f));
	
	cin >> n;
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			char ch;
			cin >> ch;
			mp[i][j] = (ch == '#');
		}
	}
	
	dfs(1, 1, n, n);
	
	cout << f[1][1][n][n] << endl;
	
	return 0;
}