#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#define sqr(x) (x)*(x)
#define fz1(i,n) for (i=1;i<=n;i++)
#define fd1(i,n) for (i=n;i>=1;i--)
#define fz0g(i,n) for (i=0;i<=n;i++)
#define fd0g(i,n) for (i=n;i>=0;i--)
#define fz0k(i,n) for (i=0;i<n;i++)
#define fd0k(i,n) for (i=(long long)(n-1);i>=0;i--)
#define fz(i,x,y) for (i=x;i<=y;i++)
#define fd(i,y,x) for (i=y;i>=x;i--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len) {char ss[len];scanf(" %s",ss);(st)=ss;}
using namespace std;
int n,m,i,j,ans[105][105],a[105],b[105],s;
int main()
{
	scanf("%d%d",&n,&m);
	fz1(i,n) scanf("%d",&a[i]);
	fz1(i,m) scanf("%d",&b[i]);
	fz1(i,n) s^=a[i];
	fz1(i,m) s^=b[i];
	if (s!=0)
	{
		puts("NO");
		return 0;
	}
	fz1(i,n-1)
	{
		fz1(j,m-1)
		{
			ans[i][j]=a[i]^b[j];
			a[i]^=ans[i][j];
			b[j]^=ans[i][j];
		}
	}
	fz1(i,n-1)
	{
		ans[i][m]=a[i];
		b[m]^=ans[i][m];
	}
	fz1(i,m-1)
	{
		ans[n][i]=b[i];
		a[n]^=ans[n][i];
	}
	if (a[n]!=b[m])
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	ans[n][m]=a[n];
	fz1(i,n)
	{
		fz1(j,m) printf("%d ",ans[i][j]);
		puts("");
	}
	return 0;
}