#include<bits/stdc++.h>
using namespace std;
vector<int>ans;
vector<int>k;
int dis[345][345];
int n;
void dfs(int x,int y)//x:father y :son
{
	if (x==y) return;
	ans.push_back(x);
	for (int i=1;i<=n;i++)
	{
		if (dis[x][i]==1 && dis[y][i] < dis[x][y])
		{
			dfs(i,y);
			return;
		}
	}
}
int main()
{
// 	int n;
 	cin>>n;
 	for(int i=1;i<=n;i++)
 	{
 		for(int j=1;j<=n;j++)
 		{
 			dis[i][j] = (1<<25);
		 }
	}
	
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		dis[x][y] = 1;
		dis[y][x] = 1;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			if(i!=k)
			{
				for(int j=1;j<=n;j++)
				{
					if(i!=j && j!=k)
					{
						dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
					}
				}
			}
		}
	}
	int x;
	k.push_back(1);
	while(cin>>x)
	{
		k.push_back(x);
	}
	k.push_back(1);
	for(int i=1;i<k.size();i++)
	{
		dfs(k[i-1],k[i]);
	}
	ans.push_back(1);
	if (ans.size()!=n*2-1)
	{
		cout<<-1<<endl;
		exit(0);
	}
	for (int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}