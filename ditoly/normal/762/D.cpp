#include<cstdio>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
inline int read()
{
	int x=0,f=1;char c;
	while((c=getchar())<'0'||c>'9')if(c=='-')f=-1;
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return x*f;
}
#define INF (1LL<<60)
#define MN 100000
ll f[MN+5][233];
int a[MN+5][3];
inline void r(ll&a,ll b){if(b>a)a=b;}
int main()
{
	int n=read(),i,j;
	for(i=1;i<=n;++i)a[i][0]=read();
	for(i=1;i<=n;++i)a[i][1]=read();
	for(i=1;i<=n;++i)a[i][2]=read();
	memset(f,128,sizeof(f));
	f[0][100]=0;
	for(i=0;i<n;++i)for(j=0;j<=222;++j)if(f[i][j]>-INF)
	{
		if(j==100)
		{
			r(f[i+1][100],f[i][100]+a[i+1][0]);
			r(f[i+1][010],f[i][100]+a[i+1][0]+a[i+1][1]);
			r(f[i+1][001],f[i][100]+a[i+1][0]+a[i+1][1]+a[i+1][2]);
			r(f[i+1][122],f[i][100]+a[i+1][0]+a[i+1][1]+a[i+1][2]);
		}
		if(j==010)
		{
			r(f[i+1][100],f[i][010]+a[i+1][0]+a[i+1][1]);
			r(f[i+1][010],f[i][010]+a[i+1][1]);
			r(f[i+1][001],f[i][010]+a[i+1][1]+a[i+1][2]);
		}
		if(j==001)
		{
			r(f[i+1][100],f[i][001]+a[i+1][0]+a[i+1][1]+a[i+1][2]);
			r(f[i+1][010],f[i][001]+a[i+1][1]+a[i+1][2]);
			r(f[i+1][001],f[i][001]+a[i+1][2]);
			r(f[i+1][221],f[i][001]+a[i+1][0]+a[i+1][1]+a[i+1][2]);
		}
		if(j==122)
		{
			r(f[i+1][122],f[i][122]+a[i+1][0]+a[i+1][1]+a[i+1][2]);
			r(f[i+1][001],f[i][122]+a[i+1][0]+a[i+1][1]+a[i+1][2]);
		}
		if(j==221)
		{
			r(f[i+1][221],f[i][221]+a[i+1][0]+a[i+1][1]+a[i+1][2]);
			r(f[i+1][100],f[i][221]+a[i+1][0]+a[i+1][1]+a[i+1][2]);
		}
	}
	cout<<f[n][001];
}