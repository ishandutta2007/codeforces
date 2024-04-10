#include <bits/stdc++.h>

using namespace std;

const int maxn = 200 + 5;

int n, m;
int a[maxn];
int f[maxn][maxn];
int g[maxn];
vector <int> e[maxn];

int ans = 0;

int dfs(int x, int fa){
	f[x][0] = a[x];
	ans = max(ans, f[x][0]);
	
	for(int y : e[x]){
		if(y == fa)continue;
		dfs(y, x);
		
		for(int i=0;i<=n;i++){
			if(!f[x][i])continue;
			for(int j=0;j<=n;j++){
				if(!f[y][j])continue;
				if(i + j + 1 > m){
					ans = max(ans, f[x][i] + f[y][j]);
				}
			}
		}
		
		//cout << "---" << y << " " << f[x][1] << " " << f[x][2] << endl;
		memset(g, 0, sizeof(g));
		
		for(int i=0;i<=n;i++){
			g[i] = f[x][i];
			if(i > 0)g[i] = max(g[i],f[y][i - 1]);
		}
		
		for(int i=0;i<=n;i++){
			if(!f[x][i])continue;
			for(int j=0;j<=n;j++){
				if(!f[y][j])continue;
				if(i + j + 1 > m){
					g[min(i, j + 1)] = max(g[min(i, j + 1)], f[x][i] + f[y][j]);
				}
			}
		}
		
		for(int i=0;i<=n;i++){
			f[x][i] = g[i];
		}
	}
	
	//cout << x << " " << f[x][0]<< " " << f[x][1] << " " << f[x][2] << endl;
	
	return 0;
}

int main(){
	int i, j;
	
	scanf("%d%d", &n, &m);
	
	for(i=1;i<=n;i++){
		scanf("%d", &a[i]);
	}
	
	for(i=1;i<n;i++){
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	
	dfs(1, -1);
	
	printf("%d\n", ans);
	
	return 0;
}