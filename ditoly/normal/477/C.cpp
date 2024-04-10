#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 2000
#define MM 500
char a[MN+5],b[MM+5];
int p[MN+5],f[MN+5][MN+5];
inline void rw(int&x,int y){if(y>x)x=y;}
int main()
{
	int n,m,i,j,k;
	scanf("%s%s",a+1,b+1);n=strlen(a+1);m=strlen(b+1);
	for(i=1;i<=n;p[i++]=k)for(j=1,k=i-1;j<=m;++j)for(++k;k<=n&&a[k]!=b[j];)++k;
	memset(f,200,sizeof(f));f[0][0]=0;
	for(i=0;i<n;++i)for(j=0;j<=n;++j)if(f[i][j]>=0)
		rw(f[i+1][j],f[i][j]),rw(f[i+1][j+1],f[i][j]),
		p[i+1]<=n?rw(f[p[i+1]][j+p[i+1]-i-m],f[i][j]+1),0:0;
	for(i=0;i<=n;++i)printf("%d ",f[n][i]);
}