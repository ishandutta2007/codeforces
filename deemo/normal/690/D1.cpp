#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 100 + 5;

bool vis[MAXN][MAXN];
int n, m;
string s[MAXN];

bool fit(int a, int b){return 0 <= a && a < n && 0 <= b && b < m;}

void dfs(int a, int b){
	if (vis[a][b])	return;
	vis[a][b] = 1;
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if (abs(i) + abs(j) == 1 && fit(a + i, b + j) && s[a + i][b + j] == 'B')
				dfs(a + i, b + j);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!vis[i][j] && s[i][j] == 'B')	dfs(i, j), ans++;
	cout << ans << endl;
	return 0;
}