#include<cstdio>
#define ll long long
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 500
#define end return 0*puts("-1")
ll a[MN+5][MN+5],s,p;
int main()
{
	int n=read(),i,j,x,y;
	if(n==1)return 0*puts("1");
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)if(!(a[i][j]=read()))x=i,y=j;
	for(i=1;i<=n;++i)if(i!=y)a[x][y]-=a[x][i];
	for(i=1;i<=n;++i)s+=a[1+(x==1)][i];a[x][y]+=s;
	if(a[x][y]<=0)end;
	for(i=1;i<=n;++i)
	{
		for(p=0,j=1;j<=n;++j)p+=a[i][j];if(p!=s)end;
		for(p=0,j=1;j<=n;++j)p+=a[j][i];if(p!=s)end;
	}
	for(p=0,i=1;i<=n;++i)p+=a[i][i];if(p!=s)end;
	for(p=0,i=1;i<=n;++i)p+=a[i][n-i+1];if(p!=s)end;
	printf("%I64d",a[x][y]);
}