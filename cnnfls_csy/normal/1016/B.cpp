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
long long n,m,i,j,q,cnt[555555],x,y,lst;
string s,t;
int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&q);
	rdst(s,n+5);rdst(t,m+5);
	s=" "+s; 
	fz1(i,n)
	{
		if (i+t.length()-1<=n)
		{
			if (s.substr(i,t.length())==t) cnt[i]++;
		}
		cnt[i]+=cnt[i-1];
	}
	while (q--)
	{
		scanf("%I64d%I64d",&x,&y);
		if (x+t.length()-1>y)
		{
			puts("0");
			continue;
		}
		printf("%I64d\n",cnt[y-t.length()+1]-cnt[x-1]);
	}
	return 0;
}