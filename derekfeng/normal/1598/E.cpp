#include<bits/stdc++.h>
using namespace std;
int n,m,q,ans;
int f[1004][1004][2];
bool o[1004][1004];
void init(){
	for(int i=n;i;i--)for(int j=m;j;j--){
		f[i][j][0]=f[i][j+1][1]+(i<=n&&j+1<=m);
		f[i][j][1]=f[i+1][j][0]+(i+1<=n&&j<=m);
		ans+=f[i][j][0]+f[i][j][1]+1;
	}
}
void locked(int x,int y){
	int s0=f[x][y][0]+1,s1=f[x][y][1]+1;
	ans-=f[x][y][0]+f[x][y][1]+1;
	o[x][y]=1;
	f[x][y][0]=f[x][y][1]=0;
	int nx=x,ny=y;
	while(nx&&ny){
		nx--;
		if(nx<1||ny<1||o[nx][ny])break;
		f[nx][ny][1]-=s0;
		ans-=s0;
		ny--;
		if(nx<1||ny<1||o[nx][ny])break;
		f[nx][ny][0]-=s0;
		ans-=s0;
	}
	nx=x,ny=y;
	while(nx&&ny){
		ny--;
		if(nx<1||ny<1||o[nx][ny])break;
		f[nx][ny][0]-=s1;
		ans-=s1;
		nx--;
		if(nx<1||ny<1||o[nx][ny])break;
		f[nx][ny][1]-=s1;
		ans-=s1;
	}
}
void unlocked(int x,int y){
	f[x][y][0]=f[x][y+1][1]+(x<=n&&y+1<=m&&!o[x][y+1]);
	f[x][y][1]=f[x+1][y][0]+(x+1<=n&&y<=m&&!o[x+1][y]);
	o[x][y]=0;
	ans+=f[x][y][0]+f[x][y][1]+1;
	int s0=f[x][y][0]+1,s1=f[x][y][1]+1;
	int nx=x,ny=y;
	while(nx&&ny){
		nx--;
		if(nx<1||ny<1||o[nx][ny])break;
		f[nx][ny][1]+=s0;
		ans+=s0;
		ny--;
		if(nx<1||ny<1||o[nx][ny])break;
		f[nx][ny][0]+=s0;
		ans+=s0;
	}
	nx=x,ny=y;
	while(nx&&ny){
		ny--;
		if(nx<1||ny<1||o[nx][ny])break;
		f[nx][ny][0]+=s1;
		ans+=s1;
		nx--;
		if(nx<1||ny<1||o[nx][ny])break;
		f[nx][ny][1]+=s1;
		ans+=s1;
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	init();
	while(q--){
		int x,y;scanf("%d%d",&x,&y);
		if(o[x][y])unlocked(x,y);
		else locked(x,y);
		printf("%d\n",ans);
	}
}