#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#define LL long long 
using namespace std;
int n,m;
int a[110][110];
int now[110][110];
int row[110],col[110];
int get(int first)
{
	memset(row,0,sizeof(row));
	memset(col,0,sizeof(col));
	row[1]=first;
	for(int i=1;i<=m;i++)col[i]=a[1][i]-first;
	for(int i=2;i<=n;i++)
	{
		row[i]=a[i][1]-col[1];
		if (row[i]<0)return 2147483647;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if (a[i][j]-row[i]-col[j]!=0)return 2147483647;
	int sum=0;
	for(int i=1;i<=n;i++)sum+=row[i];
	for(int i=1;i<=m;i++)sum+=col[i];
	return sum;
}
void work()
{
	int maxop=600;
	for(int i=1;i<=m;i++)maxop=min(maxop,a[1][i]);
	int ans=2147483647;
	int ansp=-1;
	for(int i=0;i<=maxop;i++)
	{
		int t=get(i);
		if (t<ans)ans=t,ansp=i;
	}
	if (ansp==-1)
	{
		cout<<-1<<endl;
		return;
	}
	get(ansp);
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
		if (row[i]!=0)
			for(int j=1;j<=row[i];j++)printf("row %d\n",i);
	for(int i=1;i<=m;i++)
		if (col[i]!=0)
			for(int j=1;j<=col[i];j++)printf("col %d\n",i);
}
int main()
{	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	work();
	return 0;
}