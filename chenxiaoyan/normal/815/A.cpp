#include<iostream>
#include<vector>
using namespace std;
int gri[101][101],n,m;
bool row[101][101],col[101][101],mar[101][101],ok;
vector<pair<string,int> > ope;
void dfs(int x,int y)
{
	if(x==1&&y==1)
		ok=true;
	if(y==m+1)
	{
		y=1;
		x++;
	}
	if(x==n+1)
	{
		if(ok)
		{
			cout<<ope.size()<<"\n";
			for(int i=0;i<ope.size();i++)
				cout<<ope[i].first<<ope[i].second<<"\n";
			exit(0);
		}
		return;
	}
	if(!gri[x][y])
	{
		if(!mar[x][y])
		{
			int i;
			for(i=1;i<=n;i++)
				col[i][y]=false;
			for(i=1;i<=m;i++)
				row[x][i]=false;
			mar[x][y]=true;
		}
		dfs(x,y+1);
		return;
	}
	ok=false;
	if(row[x][y]&&!col[x][y])
	{
		int mn=501,i;
		for(i=1;i<=m;i++)
			mn=min(mn,gri[x][i]);
		for(i=1;i<=m;i++)
			gri[x][i]-=mn;
		for(i=1;i<=mn;i++)
			ope.push_back(make_pair("row ",x));
		dfs(x,y+1);
		return;
	}
	if(!row[x][y]&&col[x][y])
	{
		int mn=501,i;
		for(i=1;i<=n;i++)
			mn=min(mn,gri[i][y]);
		for(i=1;i<=n;i++)
			gri[i][y]-=mn;
		for(i=1;i<=mn;i++)
			ope.push_back(make_pair("col ",y));
		dfs(x,y+1);
		return;
	}
	if(!row[x][y]&&!col[x][y])
	{
		cout<<-1;
		exit(0);
	}
	dfs(x,y+1);
}
int main()
{
	int mn=501,i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			row[i][j]=col[i][j]=true;
			cin>>gri[i][j];
			mn=min(mn,gri[i][j]);
		}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			gri[i][j]-=mn;
	if(n<m)
		for(i=1;i<=n;i++)
			for(j=1;j<=mn;j++)
				ope.push_back(make_pair("row ",i));
	else
		for(i=1;i<=m;i++)
			for(j=1;j<=mn;j++)
				ope.push_back(make_pair("col ",i));
	while(1)
		dfs(1,1);
}
/*1
3 5
2 2 2 3 2
0 0 0 1 0
1 1 1 2 1
*/
/*2
3 3
0 0 0
0 1 0
0 0 0
*/
/*3
3 3
1 1 1
1 1 1
1 1 1
*/