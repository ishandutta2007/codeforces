#include<bits/stdc++.h>
using namespace std;
int a[1003][13];
int Max(int x)
{
	int res=0;
	for(int i=1; i<=5; i++) res=max(res,a[x][i]);
	return res;
}
int main()
{
	int n,m,ch;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) 
	{
		getchar();
		for(int j=1; j<=m; j++) 
		{
			ch=getchar();
			a[j][(int)ch-(int)'A'+1]++;
		}
	}
	int ans=0,t;
	for(int i=1; i<=m; i++) 
	{
		scanf("%d",&t);
		ans+=Max(i)*t;
	}
	printf("%d",ans);
	return 0;
}