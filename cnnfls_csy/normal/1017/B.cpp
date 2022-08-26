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
long long n,m,i,j,num[500005],cnt[4],ans;
string st1,st2;
int main()
{
	scanf("%I64d",&n);
	rdst(st2,n+5);
	rdst(st1,n+5);
	fz0k(i,n)
	{
		if (st1[i]=='1')
		{
			if (st2[i]=='1')
			{
				ans+=cnt[0];
				cnt[3]++;
			}
			else
			{
				ans+=cnt[1];
				cnt[2]++;
			}
		}
		else
		{
			if (st2[i]=='1')
			{
				ans+=cnt[0]+cnt[2];
				cnt[1]++;
			}
			else
			{
				ans+=cnt[3]+cnt[1];
				cnt[0]++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}