#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
using namespace std;
int n,m,x,y,bo,i,j,k;
int a[100005],b[100005],c[100005];
bool ch(int s,int t)
{
	if(a[t]<a[s]&&a[s]<b[t]) return 1;
	if(a[t]<b[s]&&b[s]<b[t]) return 1;
	return 0;
}
void dfs(int x)
{
	if (bo||x==y)
	{
		bo=1;return;
	}
	c[x]=1;
	for (int i=0;i<m;i++)
	{
		if (!c[i]&&ch(x,i))
		{
			dfs(i);
		}
	}
}
int main()
{
	cin>>n; 
	for (i=1;i<=n;i++)
	{
		scanf("%d%d%d",&k,&x,&y);
		if(k==1)
		{
			a[m]=x;
			b[m++]=y;
		}
		else
		{
			x--;y--;
			bo=0;
			for (j=0;j<m;j++) c[j]=0;
			dfs(x);
			if (bo) cout<<"YES"<<endl;else cout<<"NO"<<endl;
		}
	}
	return 0;
}