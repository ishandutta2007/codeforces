#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
const int MN = 2e3+5;
int grid[MN][MN], dx[4] = {0,0,1,-1}, dy[4] = {1,-1,0,0};
long long dist[MN][MN]; //(0,0) is portal node
int main () {
	int n,m,w; scanf ("%d %d %d",&n,&m,&w);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf ("%d",&grid[i][j]);
		}
	}
	memset(dist,0x3f,sizeof dist);
	priority_queue<tuple<long long,int,int>,vector<tuple<long long,int,int>>,greater<tuple<long long,int,int>>> pq;
	dist[1][1] = 0;
	pq.push({0,1,1});
	while (!pq.empty()) {
		auto [d,x,y] = pq.top(); pq.pop();
		if (d > dist[x][y]) continue;
		if (x == 0 && y == 0) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (grid[i][j] > 0 && d + grid[i][j] < dist[i][j]) {
						dist[i][j] = d + grid[i][j];
						pq.push({dist[i][j],i,j});
					}
				}
			}
			continue;
		}
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if (1 <= nx && nx <= n && 1 <= ny && ny <= m && grid[nx][ny] >= 0 && d + w < dist[nx][ny]) {
				dist[nx][ny] = d + w;
				pq.push({d+w,nx,ny});
			} 
		}
		if (grid[x][y] > 0 && d + grid[x][y] < dist[0][0]) {
			dist[0][0] = d + grid[x][y];
			pq.push({dist[0][0],0,0});
		}
	}
	printf ("%lld\n",dist[n][m] > 1e18 ? -1 : dist[n][m]);
	return 0;
}