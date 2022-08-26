#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<deque>
using namespace std;
vector<int> a[100005],b,c;
int d[100005],n,m,i,j,x,y;
/*bool dfs(int x,bool bo,int f)
{
	if (a[x].empty()) return d[i]=1;
	if (!d[a[x][0]]) if (!dfs(a[x][0],1,x)) return 0;
	if (bo) 
	{
	   d[x]=3-d[a[x][0]];
    }
    if (d[x]==1) b.push_back(x);
    else c.push_back(x);
	for (int i=0;i<a[x].size();i++)
	{
	 	if (!d[a[x][i]]&&a[x][i]!=f) if (!dfs(a[x][i],1,x)) return 0;
	 	if (d[x]==d[a[x][i]]) return 0;
	}
	return 1;
}*/
bool dfs(int x,int y,int cc)
{
	int i;
	for (i=0;i<a[x].size();i++)
	if (a[x][i]!=cc)
	{
		if (d[a[x][i]]==y) return 0;
		if (d[a[x][i]]==0)
		{
			if (y==1) {d[a[x][i]]=2;c.push_back(a[x][i]);} else {d[a[x][i]]=1;b.push_back(a[x][i]);} 
			if (!dfs(a[x][i],d[a[x][i]],cc)) return 0;
		}
	}
	return 1;
}
int main()
{
	cin>>n>>m;
	for (i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
/*	for (i=1;i<=n;i++)
	{
		for (j=0;j<a[i].size();j++) cout<<a[i][j];cout<<endl;}*/
	for (i=1;i<=n;i++) 
	{
 	 	if (!d[i]) 
 		{
 			//d[i]=1;
			 b.push_back(i);
		    if (!dfs(i,1,i)) {cout<<-1;return 0;}
		}
	}
	cout<<b.size()<<endl;
	for (i=0;i<b.size();i++)
	printf("%d ",b[i]);
	cout<<endl<<c.size()<<endl;
	for (i=0;i<c.size();i++)
	printf("%d ",c[i]);
	return 0;
}