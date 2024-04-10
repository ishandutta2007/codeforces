#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 1005
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,p,spd[15],t[15];
int grid[maxn][maxn];//0: empty, -1: blocked.
int dis[maxn][maxn];
const int dx[] = {-1,0,1,0};
const int dy[] = {0,1,0,-1};
struct node{
	int x,y,d;
	node(int x = 0,int y = 0,int d = 0): x(x),y(y),d(d) {}
};
queue <node> active[11];
void bfs(int id,int lim){
	while(!active[id].empty()){
		node cur = active[id].front();
		if(cur.d == lim) break;
		active[id].pop();
		for(int i=0;i<4;i++){
			int cx = cur.x + dx[i],cy = cur.y + dy[i];
			if(cx >= 1 && cx <= n && cy >= 1 && cy <= m && grid[cx][cy] == 0){
				grid[cx][cy] = id;
				active[id].push(node(cx,cy,cur.d + 1));
			}
		}
	}
}
bool play(){
	bool ok = false;
	for(int i=1;i<=p;i++){
		t[i] += spd[i];
		if(!active[i].empty()){
			ok = true;
			bfs(i,t[i]);
		}
	}
	return ok;
}
char s[maxn];
int main(){
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=p;i++) scanf("%d",&spd[i]);
	for(int i=1;i<=n;i++){
		scanf("%s",s + 1);
		for(int j=1;j<=m;j++){
			if(s[j] == '.') grid[i][j] = 0;
			else if(s[j] == '#') grid[i][j] = -1;
			else{
				grid[i][j] = s[j] - '0';
				active[grid[i][j]].push(node(i,j,0));
			}
		}
	}
	while(play());
	memset(spd,0,sizeof(spd));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(grid[i][j] > 0) spd[grid[i][j]]++;
		}
	}
	for(int i=1;i<=p;i++){
		printf("%d%c",spd[i],i == p ? '\n' : ' ');
	}
	return 0;
}