#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

char str[maxn];

int f[maxn][5];
pair <int, int> g[maxn][5];
pair <int, int> h[maxn][5];

int dfs(int x, int y){
	if(!x){
		return 0;
	}
	
	dfs(g[x][y].first, g[x][y].second);
	printf("%c", str[x]);
	return 0;
}

int main(){
	int i, j;
	bool flag = false;
	int n;
	
	scanf("%s", &str[1]);
	
	str[0] = 1;
	
	n = strlen(str) - 1;
	
	for(i=1;i<=n;i++){
		if(str[i] == '0'){
			flag = true;
		}
		
		for(j=0;j<3;j++){
			f[i][j] = f[i - 1][j];
			g[i][j] = g[i - 1][j];
			h[i][j] = h[i - 1][j];
		}
		
		for(j=0;j<3;j++){
			if(f[i - 1][j] + 1 > f[i][(j + str[i] - '0') % 3] and f[i - 1][j]){
				f[i][(j + str[i] - '0') % 3] = f[i - 1][j] + 1;
				g[i][(j + str[i] - '0') % 3] = h[i - 1][j];
				h[i][(j + str[i] - '0') % 3] = make_pair(i, (j + str[i] - '0') % 3);
			}
		}
		
		if(str[i] != '0'){
			j = 0;
			if(f[i - 1][j] + 1 > f[i][(j + str[i] - '0') % 3]){
				f[i][(j + str[i] - '0') % 3] = f[i - 1][j] + 1;
				g[i][(j + str[i] - '0') % 3] = h[i - 1][j];
				h[i][(j + str[i] - '0') % 3] = make_pair(i, (j + str[i] - '0') % 3);
			}
		}
	}
	
	if(!f[n][0]){
		if(flag){
			printf("0\n");
		}else{
			printf("-1\n");
		}
	}else{
		dfs(h[n][0].first, h[n][0].second);
	}
	
	return 0;
}