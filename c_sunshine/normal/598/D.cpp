#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
int n,m,Q;
char s[1005][1005];
int I[1005][1005];
int f[1100005],c[1100005],N;

int getf(int x)
{
	int y;
	for(y=x;f[y];y=f[y]);
	for(int t;x!=y;t=f[x],f[x]=y,x=t);
	return y;
}

void merge(int x,int y)
{
	x=getf(x),y=getf(y);
	if(x!=y)
	{
		c[x]+=c[y];
		f[y]=x;
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;j++)
			if(s[i][j]=='.')
				I[i][j]=++N;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]=='.')
				c[I[i][j]]=(s[i][j-1]=='*')+(s[i][j+1]=='*')+(s[i-1][j]=='*')+(s[i+1][j]=='*');
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(I[i][j])
			{
				if(I[i][j+1])merge(I[i][j],I[i][j+1]);
				if(I[i+1][j])merge(I[i][j],I[i+1][j]);
			}
	for(int x,y,t,qi=1;qi<=Q;qi++)
	{
		scanf("%d%d",&x,&y);
		t=getf(I[x][y]);
		printf("%d\n",c[t]);
	}
	return 0;
}