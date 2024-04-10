#include<bits/stdc++.h>
using namespace std;
char c[502][502];
int n,m,k,start1,start2,dx[4]={-1,0,0,1},dy[4]={0,1,-1,0};
bool vis[503][503];
void dfs(int x,int y){
	vis[x][y]=1;
	//cout<<x<<' '<<y;
	for(int i=0;i<4;i++)
	{
		int xx=x+dx[i],yy=y+dy[i];
		if(c[xx][yy]!='.'||vis[xx][yy])continue;
		dfs(xx,yy);
	}
	if(k)k--,c[x][y]='X';
}
int main(){
	for(int i=0;i<502;i++)
		for(int j=0;j<502;j++)
			c[i][j]='#';
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>c[i][j];
			if(c[i][j]=='.')start1=i,start2=j;
		}
	dfs(start1,start2);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			cout<<c[i][j];
		cout<<endl;
	}
}
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////                                                ////
////                                                ////
////                      _/\_                      ////
////                    _\_  _|_                    ////
////                   _\_ __ _|_                   ////
////                  _\_ ____ _|_                  ////
////                 _\_ ______ _|_                 ////
////                _\_ ________ _|_                ////
////                \______________|                ////
////                                                ////
////                                                ////
////           Here is some shit for you.           ////
////                                                ////
////                                                ////
////                 Please eat it.                 ////
////                                                ////
////                                                ////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////