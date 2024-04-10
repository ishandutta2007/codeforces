#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int inf = 0x3f3f3f3f;

int n, m, t;

int d, s;

pair <int, int> f[5005][505];
int dis[5005][505];
bool vis[5005][505];
int a[5005][505];

queue <pair <int, int> > q; 

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int dfs(int x, int y){
	
	if(f[x][y].first){
		dfs(f[x][y].first, f[x][y].second);
	}
	
	printf("%d", a[x][y]);
	
	return 0;
}

int solve(){
	int i, j;
	int x, y;
	
	memset(dis, 0x3f, sizeof(dis));
	
	dis[0][0] = 1;
	
	for(i=1;i<=9;i++){
		if(i <= s){
			dis[i][i % d] = 1;
			a[i][i % d] = i;
			vis[i][i % d] = true;
			q.push(make_pair(i, i % d));
		}
	}
	
	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;
		q.pop();
		vis[x][y] = false;
		
		for(i=0;i<=9;i++){
			if(x + i <= s){
				if(dis[x + i][(y * 10 + i) % d] > dis[x][y] + 1){
					dis[x + i][(y * 10 + i) % d] = dis[x][y] + 1;
					f[x + i][(y * 10 + i) % d].first = x;
					f[x + i][(y * 10 + i) % d].second = y;
					a[x + i][(y * 10 + i) % d] = i;
					if(!vis[x + i][(y * 10 + i) % d]){
						vis[x + i][(y * 10 + i) % d] = true;
						q.push(make_pair(x + i, (y * 10 + i) % d));
					}
				}/*else if(dis[x + i][(y * 10 + i) % d] == dis[x][y] + 1 and a[x + i][(y * 10 + i) % d] < i){
					f[x + i][(y * 10 + i) % d].first = x;
					f[x + i][(y * 10 + i) % d].second = y;
					a[x + i][(y * 10 + i) % d] = i;
					if(!vis[x + i][(y * 10 + i) % d]){
						vis[x + i][(y * 10 + i) % d] = true;
						q.push(make_pair(x + i, (y * 10 + i) % d));
					}
				}*/
			}
		}
	}
	
	if(dis[s][0] == inf){
		printf("-1\n");
	}else{
		dfs(s, 0);
		printf("\n");
	}
	
	return 0;
}

int main(){
	int i, j;
	
	d = read();
	s = read();
	
	solve();
	
	return 0;
}