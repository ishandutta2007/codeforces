#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<stack>
using namespace std;
int n,i,j,m,s,a[105][105],x,y,Max,t;
void dfs(int x,int y,int z)
{
	t=max(t,z);
	int i;
	for (i=1;i<=m;i++)
	if (a[x][i]&&i!=y) dfs(i,x,z+1);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n;
	for (;n--;)
	{
		cin>>m;
		for (i=1;i<=100;i++)
		for (j=1;j<=100;j++) a[i][j]=0;
		for (i=1;i<=m-1;i++) {scanf("%d%d",&x,&y);a[x][y]=1;a[y][x]=1;}
		Max=0;
		for (i=1;i<=m;i++) 
		{
			t=0;
		    	dfs(i,-1,0);
			Max=max(Max,t);
		}
		s+=Max;
	}
	cout<<s;
	return 0;
}