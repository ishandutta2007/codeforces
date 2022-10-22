#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e3+5;
const int Max=1e3;
const int p=1e9+7;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int x[N],y[N],b[N],a[N][N],C[N][N];
int calc(int x1,int y1,int x2,int y2)
{
	x1=max(x1,1ll);
	y1=max(y1,1ll);
	x2=min(x2,Max);
	y2=min(y2,Max);
	if (x2<x1||y2<y1) return 0;
	return a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1];
}

signed main()
{
	memset(a,0,sizeof(a));
	memset(C,0,sizeof(C));
	int n=read(),m=read(),r=read(),ans=0;
	for (int i=1;i<=n;i++)
	{
		x[i]=read();
		y[i]=read();
		b[i]=read();
		a[x[i]][y[i]]++;
	}
	for (int i=1;i<=Max;i++)
	for (int j=1;j<=Max;j++) a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
	C[0][0]=1;
	for (int i=1;i<=n;i++)
	{
		C[i][0]=1;
		for (int j=1;j<=i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
	}
	for (int i=1;i<n;i++)
	for (int j=i+1;j<=n;j++)
	{
		int mul=2ll*b[i]*b[j]%p;
		int tot0=calc(max(x[i]-r,x[j]-r),max(y[i]-r,y[j]-r),min(x[i]+r,x[j]+r),min(y[i]+r,y[j]+r));
		int tot1=calc(x[i]-r,y[i]-r,x[i]+r,y[i]+r);
		int tot2=calc(x[j]-r,y[j]-r,x[j]+r,y[j]+r);
		int sum=(C[n][m]-C[n-tot2][m]-C[n-tot1][m]+C[n-(tot1+tot2-tot0)][m]+p+p)%p;
		ans=(ans+sum*mul%p)%p;
	}
	for (int i=1;i<=n;i++)
	{
		int mul=b[i]*b[i]%p;
		int tot=calc(x[i]-r,y[i]-r,x[i]+r,y[i]+r);
		ans=(ans+(C[n][m]-C[n-tot][m]+p)%p*mul%p)%p;
	}
	print(ans);

	return 0;
}