#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<set>
#include<iomanip>
#define sqr(x) (x)*(x)
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
//#define T_ int
using namespace std;
int n,m,i,j,a[500005],s,ans,f;
string st;
int main()
{
	scanf("%d",&n);
	fz1(i,n)
	{
		scanf("%d",&a[i]);
	}
	ans=2e9;
	fz1(i,100)
	{
		s=0;
		fz1(j,n)
		{
			s+=min(min(abs(i-a[j]),abs(i-a[j]-1)),abs(i-a[j]+1));
		}
		if (s<ans)
		{
			ans=s;
			f=i;
		}
	}
	cout<<f<<' '<<ans<<endl;
	return 0;
}