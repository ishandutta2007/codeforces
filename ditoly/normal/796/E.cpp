#include<cstdio>
#include<cstring>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 1000
#define MK 50
int a[MN+5],b[MN+5],f[2][MN+5][MK+5][MK+5];
inline void up(int&a,int b){if(b>a)a=b;}
int main()
{
	int n,p,k,i,j,x,y,nw,nx,ans=0;
	n=read();p=read();k=read();
	for(i=read();i--;)++a[read()];
	for(i=read();i--;)++b[read()];
	if(p*k>=2*n)
	{
		for(i=1;i<=n;++i)if(a[i]||b[i])++ans;
		return 0*printf("%d",ans);
	}
	memset(f[0],128,sizeof(f[0]));f[0][0][0][0]=0;
	for(i=0;i<n;++i)
	{
		nw=i&1;nx=nw^1;
		memset(f[nx],128,sizeof(f[nx]));
		for(j=0;j<=p;++j)for(x=0;x<k;++x)for(y=0;y<k;++y)if(f[nw][j][x][y]>=0)
		{
			if(x&&y)up(f[nx][j][x-1][y-1],f[nw][j][x][y]+(a[i+1]||b[i+1]));
			if(!x&&y)
			{
				up(f[nx][j][0][y-1],f[nw][j][x][y]+b[i+1]);
				if(j<p)up(f[nx][j+1][k-1][y-1],f[nw][j][x][y]+(a[i+1]||b[i+1]));
			}
			if(x&&!y)
			{
				up(f[nx][j][x-1][0],f[nw][j][x][y]+a[i+1]);
				if(j<p)up(f[nx][j+1][x-1][k-1],f[nw][j][x][y]+(a[i+1]||b[i+1]));
			}
			if(!x&&!y)
			{
				up(f[nx][j][0][0],f[nw][j][0][0]);
				if(j<p)up(f[nx][j+1][k-1][0],f[nw][j][x][y]+a[i+1]),
					   up(f[nx][j+1][0][k-1],f[nw][j][x][y]+b[i+1]);
				if(j+1<p)up(f[nx][j+2][k-1][k-1],f[nw][j][x][y]+(a[i+1]||b[i+1]));
			}
		}
	}
	printf("%d",f[nx][p][0][0]);
}