#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include<queue>
#define sqr(x) (x)*(x)
#define fast ios::sync_with_stdio(false);
using namespace std;
struct ii
{
	int x,y;
}now,nxt;
char na[4]={'L','U','R','D'};
bool ok[4],used[105][105],bo=0;
int n,m,i,j,ex,ey,ans[105][105];
char mp[105][105];
int dy[4]={0,-1,0,1},dx[4]={-1,0,1,0};
ii nex(char ch)
{
	cout<<ch<<endl;
	fflush(stdout);
	int x,y;
	cin>>x>>y;
	return {x,y};
}
int main()
{
	fast;
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++) 
		{
			cin>>mp[i][j];
			if (mp[i][j]=='F') 
			{
				mp[i][j]='.';
				ex=i;
				ey=j;
			}
		}
	}
	//cerr<<ex<<' '<<ey<<endl;
	used[ex][ey]=1;
	queue<ii> q;
	q.push({ex,ey});
	while (!q.empty()) 
	{
		ii v=q.front();q.pop();
		for (i=0;i<4;i++)
		{
			ii u={v.x+dy[i],v.y+dx[i]};
			if (u.x>=1&&u.x<=n&&u.y>=1&&u.y<=m&&mp[u.x][u.y]!='*'&&!used[u.x][u.y])
			{ 
				//cerr<<u.x<<' '<<u.y<<endl; 
				ans[u.x][u.y]=(i+2)%4;
				used[u.x][u.y]=1;
				q.push(u);
			}
		}
	}
	now={1,1};
	while (now.x!=ex||now.y!=ey) 
	{
		bo=0;
		nxt=nex(na[ans[now.x][now.y]]);
		if (!ok[ans[now.x][now.y]]) 
		{
			ok[ans[now.x][now.y]]=ok[(ans[now.x][now.y]+2)%4]=1;
			if (nxt.x==now.x&&nxt.y==now.y) {/*cerr<<"dsfasdfafssdafasfds"<<endl;*/swap(na[ans[now.x][now.y]],na[(ans[now.x][now.y]+2)%4]);bo=1;}
		}
		if (!bo) now=nxt;
		//cerr<<nxt;
	}
	return 0;
}