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
#define rdst(st,len) {char ss[len];scanf("%s",ss);(st)=ss;}
using namespace std;
int n,m,i,j,l,r,ls,rs,mid;
int query(int x)
{
	int t1,t2;
	printf("? %d\n",x);
	fflush(stdout);
	scanf("%d",&t1);
	printf("? %d\n",x+n);
	fflush(stdout);
	scanf("%d",&t2);
	if (t1==t2)
	{
		printf("! %d\n",x);
		exit(0);
	}
	return t1-t2;
}
int sig(int x)
{
	if (x>0) return 1;
	return -1;
}
int main()
{
	scanf("%d",&n);
	n/=2;
	if (n&1)
	{
		puts("! -1");
		return 0;
	}
	l=1;ls=query(1);
	r=n+1;rs=query(n);
	if (sig(ls)==sig(rs)) return -1;
	while (l<r)
	{
		mid=(l+r)/2;
		int t=query(mid);
		if (sig(t)==sig(ls)) l=mid+1;
		else r=mid;
	}
	for(;;);
	return 0;
}