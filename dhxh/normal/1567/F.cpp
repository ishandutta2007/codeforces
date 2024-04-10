#include <bits/stdc++.h>

using namespace std;

const int maxn = 500 + 5;

int n, m;

bool a[maxn][maxn];

vector <pair <int, int> > e[maxn][maxn];

int ans[maxn][maxn];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool valid(int x, int y){
	return 1 <= x and x <= n and 1 <= y and y <= m;
}

void dfs(int x, int y){
	for(auto [p, q] : e[x][y]){
		if(!ans[p][q]){
			ans[p][q] = 5 - ans[x][y];
			dfs(p, q);
		}
	}
}

int main(){
	int i, j;
	char ch;
	
	scanf("%d%d", &n, &m);
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf(" %c", &ch);
			a[i][j] = (ch == 'X'); 
		}
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(!a[i][j]) continue;
			vector <pair <int, int> > vec;
			for(int d=0;d<4;d++){
				int x = i + dx[d];
				int y = j + dy[d];
				if(!valid(x, y) or a[x][y]) continue;
				vec.push_back({x, y});
			}
			
			if(vec.size() & 1){
				printf("NO\n");
				return 0;
			}
			
			for(auto [x, y] : vec){
				for(auto [p, q] : vec){
					if(vec.size() == 4 and (x == p or y == q)) continue;
					if(x != p or y != q){
						e[x][y].push_back({p, q});
					}
				}
			}
		}
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(a[i][j]) continue;
			if(ans[i][j]) continue;
			ans[i][j] = 1;
			dfs(i, j);
		}
	}
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(!a[i][j]) continue;
			for(int d=0;d<4;d++){
				int x = i + dx[d];
				int y = j + dy[d];
				if(a[x][y]) continue;
				ans[i][j] += ans[x][y];
			}
		}
	}
	
	printf("YES\n");
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}