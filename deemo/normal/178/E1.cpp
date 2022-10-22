#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 2e3 + 5;

int n, a[MAXN][MAXN], up[MAXN][MAXN], le[MAXN][MAXN];
bool mark[MAXN][MAXN];

void dfs(int x, int y){
	if (x < 0 || y < 0)	return;
	if (a[x][y] == 0)	return;
	if (mark[x][y])	return;
	mark[x][y] = 1;
	
	for (int i = -1; i < 2; i++)
		for (int j = -1; j < 2; j++)
			if (abs(i) + abs(j) == 1)
				dfs(x + i, y + j);
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)	scanf("%d", &a[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] == 1){
				if (i == 0)	up[i][j] = 1;
				else	up[i][j] = 1 + up[i - 1][j];

				if (j == 0)	le[i][j] = 1;
				else	le[i][j] = 1 + le[i][j - 1];
			}
	
	int aa = 0, bb = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!mark[i][j] && a[i][j]){
				int x = i, y = j;
				while (up[x][y] < 10)	x++;
				while (le[x][y] < 10)	y++;
				
				if (le[x - 9][y] != 10 || up[x][y - 9] != 10)	bb++;
				else	aa++;
				dfs(x, y);
			}
	cout << bb << " " << aa << endl;
	return	0;
}