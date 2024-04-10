#include <bits/stdc++.h>

using namespace std;

const int inf = 0x3f3f3f3f;

int dis[1005][1005][45];
int a[1005][1005];

bool v[45][45];

struct ex {
	int x, y, z;
};

vector <ex> vec[45];

queue <ex> q;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int n, m, k, t;

int main(){
	int i, j;
	
	scanf("%d%d%d", &n, &m, &k);
	
	memset(dis, 0x3f3f3f3f, sizeof(dis));
	
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d", &a[i][j]);
			vec[a[i][j]].push_back({i, j});
		}
	}
	for(i=1;i<=k;i++) v[i][i] = true;
	
	for(int z=1;z<=k;z++){
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				if(a[i][j] == z){
					dis[i][j][z] = 0;
					q.push({i, j});
				}
			}
		}
		while(q.size()){
			int x = q.front().x, y = q.front().y;
			q.pop(); 
			
			for(i=0;i<4;i++){
				if(1 <= x + dx[i] and x + dx[i] <= n and 1 <= y + dy[i] and y + dy[i] <= m){
					if(dis[x + dx[i]][y + dy[i]][z] > dis[x][y][z] + 1){
						dis[x + dx[i]][y + dy[i]][z] = dis[x][y][z] + 1;
						q.push({x + dx[i], y + dy[i], z});
					}
				}
			}
			
			if(!v[z][a[x][y]]){
				v[z][a[x][y]] = true;
				for(auto tmp : vec[a[x][y]]){
					if(dis[tmp.x][tmp.y][z] > dis[x][y][z] + 1){
						dis[tmp.x][tmp.y][z] = dis[x][y][z] + 1;
						q.push({tmp.x, tmp.y, z});
					}
				}
			}
		}
	}
	
	scanf("%d", &t);
	
	while(t--){
		int x, y, a, b;
		scanf("%d%d%d%d", &x, &y, &a, &b);
		int ans = abs(x - a) + abs(y - b);
		for(i=1;i<=k;i++){
			ans = min(ans, dis[x][y][i] + dis[a][b][i] + 1);
		}
		printf("%d\n", ans);
	}
	
	return 0;
}