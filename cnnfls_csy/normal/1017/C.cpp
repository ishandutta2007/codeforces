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
long long n,m,i,j,vis[500005],ans,b;
string st1,st2;
long long calc(long long x)
{
	return x+(n-1)/x+1;
}
int main()
{
	scanf("%I64d",&n);
	b=1;
	for (i=2;i<=n;i++) if (calc(i)<calc(b)) b=i;
//	cerr<<b<<endl;
	vis[0]=1;
	for (i=b;;i--)
	{
		if (vis[i])
		{
			if (i>n) return 0;
			i+=b+b;
		}
		vis[i]=1;
		if (i<=n) printf("%I64d ",i);
	}
	return 0;
}