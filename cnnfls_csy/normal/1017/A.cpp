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
int n,m,i,j,num[500005],a,b,c,d,f;
string st;
int main()
{
	scanf("%d",&n);
	fz1(i,n)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		num[i]=a+b+c+d;
	}
	f=num[1];
	sort(num+1,num+n+1);
	reverse(num+1,num+n+1);
	fz1(i,n) if (num[i]==f)
	{
		printf("%d\n",i);
		return 0;
	}
	return 0;
}