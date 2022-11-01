#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, q;

vector <int> e[maxn];

int dep[maxn];
int fa[maxn][22];

int dfs(int x){
	for(int i=0;fa[x][i];i++){
		fa[x][i + 1] = fa[fa[x][i]][i];
	}
	
	for(auto y : e[x]){
		if(fa[x][0] == y) continue;
		dep[y] = dep[x] + 1;
		fa[y][0] = x;
		dfs(y);
	}
	
	return 0;
}

int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	if(dep[x] > dep[y]){
		for(int i=20;i>=0;i--){
			if((1 << i) <= dep[x] - dep[y]){
				x = fa[x][i];
			}
		}
	}
	
	if(x == y) return x;
	
	for(int i=20;i>=0;i--){
		if(fa[x][i] != fa[y][i]){
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	
	return fa[x][0];
}

int dis(int x, int y){
	return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}

int main(){
	int i, j;
	int a, b, x, y, z;
	
	scanf("%d", &n);
	
	for(i=1;i<n;i++){
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dep[1] = 1;
	dfs(1);
	
	scanf("%d", &q);
	while(q--){
		scanf("%d%d%d%d%d", &x, &y, &a, &b, &z);
		int d, da, db;
		
		d = dis(a, b);
		if(d <= z and (z - d) % 2 == 0){
			printf("YES\n");
			continue;
		}
		
		da = dis(a, x);
		db = dis(b, y);
		d = da + db + 1;
		if(d <= z and (z - d) % 2 == 0){
			printf("YES\n");
			continue;
		}
		d += dis(x, y) + 1;
		if(d <= z and (z - d) % 2 == 0){
			printf("YES\n");
			continue;
		}
		
		da = dis(a, y);
		db = dis(b, x);
		d = da + db + 1;
		if(d <= z and (z - d) % 2 == 0){
			printf("YES\n");
			continue;
		}
		d += dis(x, y) + 1;
		if(d <= z and (z - d) % 2 == 0){
			printf("YES\n");
			continue;
		}
		
		printf("NO\n");
	}
	
	return 0;
}