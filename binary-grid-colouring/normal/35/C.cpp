#include<bits/stdc++.h>
using namespace std;
queue<pair<int,int> >q;
int n,m;
int k;
int d[2345][2345];
bool vis[2345][2345];
void bfs()
{
	while(!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i=-1;i<=1;i++)
		{
			for(int j=-1;j<=1;j++)
			{
				if(abs(i)+abs(j)==1)
				{
					if(x+i>0 && x+i<=n && y+j>0 && y+j<=m && vis[x+i][y+j]==0)
					{
						vis[x+i][y+j]=1;
						d[x+i][y+j] = d[x][y]+1;
						q.push(make_pair(x+i,y+j));
					}
				}
			}
		}
	}
	int x=1,y=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(d[i][j]>d[x][y])
			{
				x=i;
				y=j;
			}
		}
	}
	cout<<x<<" "<<y<<endl; 
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	cin>>n>>m;
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		int x,y;
		cin>>x>>y;
		vis[x][y]=1;
		q.push(make_pair(x,y));
	}
	bfs();
	return 0;
 }