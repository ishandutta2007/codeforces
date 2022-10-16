#include <iostream>
#include <cstdio>
using namespace std;
int n,m,f[2000005],g[2000005],sum1[2000005],sum2[2000005];
char s[2000005];
int id(int x,int y){
	if (x<1||y<1||x>n||y>m)return 0;
	return (x-1)*m+y;
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=n*m;i+=m)scanf("%s",s+i);
	f[id(1,1)]=1,g[id(n,m)]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			if (i==1&&j==1)continue;
			if (s[id(i,j)]=='#')continue;
			f[id(i,j)]|=f[id(i-1,j)];
			f[id(i,j)]|=f[id(i,j-1)];
		}
	for (int i=n;i>=1;i--)
		for (int j=m;j>=1;j--){
			if (i==n&&j==m)continue;
			if (s[id(i,j)]=='#')continue;
			g[id(i,j)]|=g[id(i+1,j)];
			g[id(i,j)]|=g[id(i,j+1)];
		}
	if (f[id(n,m)]==0){
		puts("0");
		return 0;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			sum1[id(i,j)]=sum1[id(i,j-1)]+(f[id(i,j)]&g[id(i,j)]);
			sum2[id(i,j)]=sum2[id(i-1,j)]+(f[id(i,j)]&g[id(i,j)]);
		}
	int fg=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			if (id(i,j)==1||id(i,j)==n*m)continue;
			if (f[id(i,j)]&&g[id(i,j)]&&sum1[id(i+1,j-1)]==0&&sum2[id(i-1,j+1)]==0)fg=1;
		}
	if (fg==1)puts("1");
	else puts("2");
	return 0;
}