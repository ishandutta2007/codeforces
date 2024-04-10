#include<bits/stdc++.h>
using namespace std;
int n,i,s,p[1005],tot,a[1005],d[805][85][85];
int dfs(int x,int i,int j)
{
	if(x<0)return 100000000;
	if(j>tot)return (n-i)*(n-i-1)/2;
	if(d[x][i][j]!=-1)
		return d[x][i][j];
	d[x][i][j]=100000000;
	for(int k=1;k<=n-i;++k)d[x][i][j]=min(d[x][i][j],(k-1)*(k-2)/2+dfs(x-abs(p[j]-(i+k)),i+k,j+1));
	return d[x][i][j];
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i){scanf("%d",&a[i]);if(a[i])p[++tot]=i;else ++s;}
	memset(d,-1,sizeof(d));
	int l;
	for(i=0;i<=n*(n-1)/2&&i<=800;++i){l=dfs(i,0,1);cout<<s*(s-1)/2-l<<' ';}
	for(;i<=n*(n-1)/2;++i)cout<<s*(s-1)/2-l<<' ';
}