#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
const int N=1005;
const ld pi=3.1415926535897932384626;
int n,i,j,k,f[105][105],m,gl[105][105],gr[105][105],p,l,r;
int dfs(int l,int r)
{
	if(l>r)
		return 0;
	if(f[l][r]!=-1)
		return f[l][r];
	int i,mx=0;
	for(i=l;i<=r;++i)
	{
		int s=0;
		for(j=1;j<=n;++j)
			if(gl[j][i]>=l&&gr[j][i]<=r)
				++s;
		mx=max(mx,s*s+dfs(l,i-1)+dfs(i+1,r));
	}
	return f[l][r]=mx;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&m);
	memset(f,-1,sizeof(f));
	for(i=1;i<=n;++i)
	{
		scanf("%d",&p);
		for(j=1;j<=p;++j)
		{
			scanf("%d %d",&l,&r);
			for(k=l;k<=r;++k)
			{
				gl[i][k]=l;
				gr[i][k]=r;
			}
		}
	}
	memset(f,-1,sizeof(f));
	cout<<dfs(1,m);
}