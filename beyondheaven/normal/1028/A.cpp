#include<bits/stdc++.h>
#define MaxN 223
char mp[MaxN][MaxN];
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	scanf("%s",mp[i]+1);
	int x1,y1,x2,y2;
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j)
	if(mp[i][j]=='B')
	{
		x1=i;y1=j;break;
	}
	for(int i=n;i;--i)
	for(int j=m;j;--j)
	if(mp[i][j]=='B')
	{
		x2=i;y2=j;break;
	}
	printf("%d %d\n",(x1+x2)/2,(y1+y2)/2);
	return 0;
}