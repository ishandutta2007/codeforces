#include<bits/stdc++.h>
using namespace std;
bool vis[503][503];
int cnt;
short n,m,dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};
pair<char,pair<short,short> >ans[1023456];
void dfs(short x,short y,short a,short b){
	vis[x][y]=1;
	ans[cnt++]=(make_pair('B',make_pair(x,y)));
	for(int i=0;i<4;i++){
		short xx=x+dx[i],yy=y+dy[i];
		if(xx>=0&&xx<n&&yy>=0&&yy<m&&vis[xx][yy]^1)
		dfs(xx,yy,a,b);
	}
	if(x!=a||y!=b)
	{
		ans[cnt++]=(make_pair('D',make_pair(x,y)));
		ans[cnt++]=(make_pair('R',make_pair(x,y)));
	}
}
char c;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		c=getchar();
		for(int j=0;j<m;j++)
		{
			c=getchar();
			if(c=='#')vis[i][j]=1;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(1^vis[i][j]){
				dfs(i,j,i,j);
			}
		}
	}
	cout<<cnt<<endl;
	for(int i=0;i<cnt;i++)
		printf("%c %d %d\n",ans[i].first,ans[i].second.first+1,ans[i].second.second+1);
}