#include<bits/stdc++.h>
using namespace std;
int r1,c1,r2,c2,dx[4]={1,0,-1,0},dy[4]={0,-1,0,1},n,m;
char c[503][503];
bool vis[503][503];
int value(char x){
	if(x=='X')return 1;
	if(x=='.')return 2;
	return 0;
}
void dfs(int x,int y){
	//cout<<x<<' '<<y<<endl;
	if(x==r2&&y==c2){
		if(c[x][y]=='X')
		{
			cout<<"YES";
			exit(0);
		}
		else
		{
			int cnt=0;
			for(int i=0;i<4;i++)
				cnt+=(value(c[x+dx[i]][y+dy[i]])==2);
			if(cnt>0){cout<<"YES";exit(0);}
		}
	}
	if(vis[x][y])return;
	vis[x][y]=1;
	c[x][y]='X';
	for(int i=0;i<4;i++)
		if(x+dx[i]>0&&x+dx[i]<=n&&y+dy[i]>0&&y+dy[i]<=m&&(c[x+dx[i]][y+dy[i]]=='.'||(x+dx[i]==r2&&y+dy[i]==c2)))
			dfs(x+dx[i],y+dy[i]);
	c[x][y]='.';
	//vis[x][y]=0;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>c[i][j];
	cin>>r1>>c1>>r2>>c2;
	if(r1==r2&&c1==c2){
		int cnt=0;
		for(int i=0;i<4;i++)
			if(r1+dx[i]>0&&r1+dx[i]<=n&&c1+dy[i]>0&&c1+dy[i]<=m&&c[r1+dx[i]][c1+dy[i]]=='.')
				cnt++;
		if(cnt>=value(c[r1][c1]))
			cout<<"YES";
		else
			cout<<"NO";
		return 0;
	}
	dfs(r1,c1);
	cout<<"NO";
}