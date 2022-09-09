#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int n,m,qq,i,j;
long long dis[1005][1005];
char mp[1005][1005];
queue<pair<int,int> > q;
bool inmap(int x,int y){
	return 1<=x&&x<=n&&1<=y&&y<=m;
}
int main(){
	scanf("%d%d%d",&n,&m,&qq);
	rep(i,n){
		scanf(" %s",mp[i]+1);
	}
	rep(i,n){
		rep(j,m){
			dis[i][j]=2e18;
			if(inmap(i-1,j)&&mp[i-1][j]==mp[i][j]) dis[i][j]=0;
			if(inmap(i+1,j)&&mp[i+1][j]==mp[i][j]) dis[i][j]=0;
			if(inmap(i,j-1)&&mp[i][j-1]==mp[i][j]) dis[i][j]=0;
			if(inmap(i,j+1)&&mp[i][j+1]==mp[i][j]) dis[i][j]=0;
			if(dis[i][j]==0) q.push(make_pair(i,j));
		}
	}
	while(!q.empty()){
		int x=q.front().first,y=q.front().second;q.pop();
		int xx,yy;
		xx=x-1;yy=y;if(inmap(xx,yy)&&dis[xx][yy]>dis[x][y]+1){dis[xx][yy]=dis[x][y]+1;q.push(make_pair(xx,yy));}
		xx=x+1;yy=y;if(inmap(xx,yy)&&dis[xx][yy]>dis[x][y]+1){dis[xx][yy]=dis[x][y]+1;q.push(make_pair(xx,yy));}
		xx=x;yy=y-1;if(inmap(xx,yy)&&dis[xx][yy]>dis[x][y]+1){dis[xx][yy]=dis[x][y]+1;q.push(make_pair(xx,yy));}
		xx=x;yy=y+1;if(inmap(xx,yy)&&dis[xx][yy]>dis[x][y]+1){dis[xx][yy]=dis[x][y]+1;q.push(make_pair(xx,yy));}
	}
	while(qq--){
		int x,y;long long t;
		scanf("%d%d%I64d",&x,&y,&t);
		printf("%d\n",(t<=dis[x][y]?mp[x][y]-'0':(mp[x][y]-'0')^((t-dis[x][y])&1)));
	} 
	return 0;
}