#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
bool vis[100][100], found;
char c[100][100];

void dfs(int x, int y, int a = -1, int b = -1){
	vis[x][y] = 1;
	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++)
			if (abs(i) + abs(j) == 1 && c[x + i][y + j] == c[x][y] && (x + i != a || y + j != b)){
				if (vis[x + i][y + j])
					found = 1;
				else
					dfs(x + i, y + j, x, y);
			}
}

int main(){
	cin >> n >> m;	for (int i = 0; i < n; i++)	for (int j = 0; j < m; j++)	cin >> c[i][j];
	for (int i = 0; i < n; i++)	for (int j = 0; j < m; j++)	if (!vis[i][j])	dfs(i, j);
	if (found)
		cout << "Yes\n";
	else
		cout << "No\n";
	return	0;
}