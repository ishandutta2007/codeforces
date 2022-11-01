#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

char g[1005][1005];
int n,m;
int rx,ry;
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
bool vis[1005][1005];

struct pos{
	int x,y,d,t;
};

bool in(int x,int y){
	return x>=0&&y>=0&&x<n&&y<m;
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%s",&g[i]);
		for(int j=0;j<m;j++){
			if(g[i][j]=='S'){
				rx=i; ry=j;
			}
		}
	}
	queue<pos> q;
	q.push({rx,ry,0,0});q.push({rx,ry,1,0});q.push({rx,ry,2,0});q.push({rx,ry,3,0});
	while(!q.empty()){
		int x=q.front().x,y=q.front().y,d=q.front().d,t=q.front().t;
		q.pop();
		vis[x][y]=1;
		if(g[x][y]=='T'){puts("YES");return 0;}
		int nx=x+dx[d],ny=y+dy[d];
		if(in(nx,ny)&&g[nx][ny]!='*'&&!vis[nx][ny]) q.push({nx,ny,d,t});
		if(t<2){
			q.push({x,y,(d+3)%4,t+1});
			q.push({x,y,(d+1)%4,t+1});
		}
	}
	puts("NO");
	return 0;
}