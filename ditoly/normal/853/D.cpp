#include<cstdio>
#include<cstring>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 300000
#define K 100
int a[MN+5],f[MN+5][K+5];
inline void r(int&a,int b){if(b<a)a=b;}
int main()
{
	int n=read(),i,j;
	for(i=1;i<=n;++i)a[i]=read();
	memset(f,40,sizeof(f));f[0][0]=0;
	for(i=1;i<=n;++i)for(j=0;j<=K;++j)
	{
		if(j+a[i]/1000<=K)r(f[i][j+a[i]/1000],f[i-1][j]+a[i]);
		if(j*100<a[i])r(f[i][0],f[i-1][j]+a[i]-j*100);
		else r(f[i][j-a[i]/100],f[i-1][j]);
	}
	for(i=0;i<=K;++i)r(f[0][1],f[n][i]);
	printf("%d",f[0][1]);
}