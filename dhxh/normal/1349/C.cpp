#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 1000 + 5;

int n, m, t;

int a[maxn][maxn];
long long dis[maxn][maxn];
bool vis[maxn][maxn];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool valid(int x, int y){
	return 1 <= x and x <= n and 1 <= y and y <= m;
}

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int x, y, p;
	char ch;
	
	n = read();
	m = read();
	t = read();
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf(" %c", &ch);
			a[i][j] = ch - '0';
		}
	}
	
	memset(dis, 0x3f, sizeof(dis));
	
	queue <pair<int, int> > q;
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			for(int d=0;d<4;d++){
				x = i + dx[d];
				y = j + dy[d];
				if(valid(x, y)){
					if(a[x][y] == a[i][j]){
						dis[i][j] = 0;
					}
				}
			}
			if(dis[i][j] == 0) q.push({i, j});
		}
	}
	
	while(q.size()){
		int x = q.front().first, y = q.front().second;
		q.pop();
		for(int d=0;d<4;d++){
			int nx = x + dx[d], ny = y + dy[d];
			if(!valid(nx, ny)) continue;
			if(dis[nx][ny] > dis[x][y] + 1){
				dis[nx][ny] = dis[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
	
	while(t--){
		long long p;
		scanf("%d%d%lld", &x, &y, &p);
		if(p <= dis[x][y]){
			printf("%d\n", a[x][y]);
		}else{
			p -= dis[x][y];
			p %= 2;
			if(p){
				printf("%d\n", !a[x][y]);
			}else{
				printf("%d\n", a[x][y]);
			}
		}
	}
	
	return 0;
}