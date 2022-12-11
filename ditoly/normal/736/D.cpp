#include<cstdio>
#include<algorithm>
#include<bitset>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 2000
#define MM 500000
int a[MM+5],b[MM+5];
bitset<MN*2+5> f[MN+5];
int main()
{
	int n,m,i,j;
	n=read();m=read();
	for(i=1;i<=m;++i)a[i]=read(),f[a[i]][b[i]=read()]=1;
	for(i=1;i<=n;++i)f[i][n+i]=1;
	for(i=1;i<=n;++i)
	{
		for(j=i;!f[i][i]&&j<=n;++j)if(f[j][i])f[i]^=f[j];
		for(j=1;j<=n;++j)if(i!=j&&f[j][i])f[j]^=f[i];
	}
	for(i=1;i<=m;++i)puts(f[b[i]][n+a[i]]?"NO":"YES");
}