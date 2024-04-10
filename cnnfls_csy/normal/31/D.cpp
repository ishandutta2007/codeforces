#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<set>
#define sqr(x) (x)*(x)
using namespace std;
set<pair<int,int>/**/> bi[105][105];
vector<int> ans;
int n,m,k,i,j,x1,x2,yy,y2,s;
bool used[105][105];
bool inmap(int x,int y)
{
	return x>0&&y>0&&x<=n&&y<=m;
}
void dfs(int x,int y)
{
	s++;
	used[x][y]=1;
	for (set<pair<int,int>/**/>::iterator it=bi[x][y].begin();it!=bi[x][y].end();it++)
	{
		if (inmap(it->first,it->second)&&!used[it->first][it->second]) dfs(it->first,it->second);
	}
}
int main()
{
	cin>>n>>m>>k;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=m;j++)
		{
			bi[i][j].insert(make_pair(i-1,j)); 
			bi[i][j].insert(make_pair(i,j-1)); 
			bi[i][j].insert(make_pair(i+1,j)); 
			bi[i][j].insert(make_pair(i,j+1));
		}
	}
	for (i=1;i<=k;i++)
	{
		cin>>x1>>yy>>x2>>y2;
		if (x1==x2)
		{
			for (j=yy+1;j<=y2;j++)
			{
				 bi[x1][j].erase(make_pair(x1+1,j));
				 bi[x1+1][j].erase(make_pair(x1,j));
			}
		}
		else if (yy==y2)
		{
			for (j=x1+1;j<=x2;j++)
			{
				 bi[j][yy].erase(make_pair(j,yy+1));
				 bi[j][yy+1].erase(make_pair(j,yy));
			}
		}
	}
	for (i=1;i<=n;i++) 
	{
		for (j=1;j<=m;j++)
		{
			cerr<<"["<<i<<','<<j<<"]:";
			for (set<pair<int,int>/**/>::iterator it=bi[i][j].begin();it!=bi[i][j].end();it++)
			{
				cerr<<" ("<<it->first<<','<<it->second<<") "; 
			}
			cerr<<endl;
		}
	} 
	for (i=1;i<=n;i++) 
	{
		for (j=1;j<=m;j++)
		{
			if (!used[i][j])
			{
				s=0; 
				dfs(i,j);
				ans.push_back(s);
			}
		}
	}
	sort(ans.begin(),ans.end());
	for (i=0;i<ans.size();i++) cout<<ans[i]<<' ';
	return 0;
}