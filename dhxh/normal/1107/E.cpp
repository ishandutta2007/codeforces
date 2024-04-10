#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m, t;

string str;
long long a[105];

long long f[105][105][105][2];

bool vis[105][105][105][2];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int dfs(int l, int r, int x, int t){
	int i, j;
	
	if(vis[l][r][x][t]){
		return 0;
	}
	
	vis[l][r][x][t] = true;
	
	if(x == 0){
		for(i=1;i<=r-l+1;i++){
			dfs(l, r, i, t);
			if(f[l][r][i][t] != -1){
				f[l][r][x][t] = max(f[l][r][x][t], f[l][r][i][t] + a[i]);
			}
		}
		dfs(l, r, 0, !t);
		f[l][r][x][t] = f[l][r][x][!t] = max(f[l][r][x][t], f[l][r][x][!t]);
	}else{
		for(i=l;i<r;i++){
			dfs(l, i, 1, t);
			dfs(i + 1, r, x - 1, t);
			if(f[l][i][1][t] != -1 and f[i + 1][r][x - 1][t] != -1){
				f[l][r][x][t] = max(f[l][r][x][t], f[l][i][1][t] + f[i + 1][r][x - 1][t]);
			}
		}
	}
	
	return 0;
}

int main(){
	int i, j;
	
	memset(f, -1, sizeof(f));
	
	cin >> n;
	cin >> str;
	
	str = 'x' + str;
	
	for(i=1;i<=n;i++){
		cin >> a[i];
	}
	
	for(i=1;i<=n;i++){
		f[i][i][1][str[i] - '0'] = 0;
		vis[i][i][1][str[i] - '0'] = true;
	}
	
	dfs(1, n, 0, 0);
	
	cout << f[1][n][0][0] << endl;
	
	return 0;
}