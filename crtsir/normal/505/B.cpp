#include<vector>
#include<iostream>
using namespace std;
vector<int>a[101][2];
bool b[101][101],col[101];
int ans[101];
void dfs(int x,int y,int co,int num)
{
	for(int i=0;i<a[x][0].size();i++)
		if(a[x][1][i]==co)
			if(a[x][0][i]==y&&col[co]==false)
			{
				ans[num]++;
				col[co]=true;
				b[a[x][0][i]][a[x][1][i]]=true;
			}
			else if(!b[a[x][0][i]][a[x][1][i]])
			{
				b[a[x][0][i]][a[x][1][i]]=true;
				dfs(a[x][0][i],y,a[x][1][i],num);
			}
	return;
}
int main()
{
	int n,m;
	cin>>m>>n;
	for(int i=0;i<n;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		a[x][0].push_back(y);
		a[x][1].push_back(z);
		a[y][0].push_back(x);
		a[y][1].push_back(z);
	}
	int k;
	cin>>k;
	for(int i=0;i<k;i++)
	{
		int x,y;
		cin>>x>>y;
		for(int j=0;j<a[x][1].size();j++)
			dfs(x,y,a[x][1][j],i);
		for(int j=0;j<101;j++)
			for(int k=0;k<101;k++)
				b[j][k]=false;
		for(int i=0;i<101;i++)
			col[i]=false;
	}
	for(int i=0;i<k;i++)
		cout<<ans[i]<<endl;
}