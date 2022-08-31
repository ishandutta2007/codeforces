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
long long n,m,i,j,q,num[300005][2],sum[300005][4],suf[300005][4],ans,ss,cnt;
string s,t;
long long get1(long long x,long long y)
{
	if (x>n) return 0;
	return suf[x+1][1]+cnt*sum[x+1][1];
}
long long get2(long long x,long long y)
{
	if (x>n) return 0;
	y+=(n-x);
	return suf[n][0]-suf[x][0]-sum[x][0]*(n-x)+y*(sum[n][0]-sum[x][0]);
}
long long get3(long long x,long long y)
{
	if (x>n) return 0;
	return suf[x+1][2]+cnt*sum[x+1][2];
}
long long get4(long long x,long long y)
{
	if (x>n) return 0;
	y+=(n-x);
	return suf[n][3]-suf[x][3]-sum[x][3]*(n-x)+y*(sum[n][3]-sum[x][3]);
}
int main()
{
	scanf("%I64d",&n);
	fz1(i,n) scanf("%I64d",&num[i][0]);
	fz1(i,n) scanf("%I64d",&num[i][1]);
	fd1(i,n) sum[i][1]=sum[i+1][1]+num[i][1];
	fz1(i,n) sum[i][0]=sum[i-1][0]+num[i][0];
	fd1(i,n) suf[i][1]=suf[i+1][1]+sum[i+1][1]+num[i][1];
	fz1(i,n) suf[i][0]=suf[i-1][0]+sum[i-1][0]+num[i][0];
	fd1(i,n) sum[i][2]=sum[i+1][2]+num[i][0];
	fz1(i,n) sum[i][3]=sum[i-1][3]+num[i][1];
	fd1(i,n) suf[i][2]=suf[i+1][2]+sum[i+1][2]+num[i][0];
	fz1(i,n) suf[i][3]=suf[i-1][3]+sum[i-1][3]+num[i][1];
	cnt=-1;
	fz0g(i,n)
	{
		if (i)
		{
			cnt++;
			ss+=num[i][!(i&1)]*cnt;
			cnt++;
			ss+=num[i][i&1]*cnt;
		}
		if ((i&1)) ans=max(ans,ss+get1(i,cnt)+get2(i,cnt)); else ans=max(ans,ss+get3(i,cnt)+get4(i,cnt));
	}
	printf("%I64d\n",ans);
	return 0;
}