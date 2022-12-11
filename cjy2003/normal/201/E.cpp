#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t;
long long l,r,mid,ans;
long long n,m;
long long check(long long x,long long y)
{
	long long s=1,c=1;
	x=x*y;
	for(int i=1;i<=y;++i)
	{
		c=c*(y-i+1)/i;
		if(c*i<x)x-=c*i,s+=c;
		else
		{
			s+=x/i;
			break;	
		}
		if(s>1e9)return 10000000000ll;
	}
	return s;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%I64d %I64d",&n,&m);
		l=0,r=n,ans=0;
		while(l<=r)
		{
			mid=l+r>>1;
			if(check(m,mid)>=n)ans=mid,r=mid-1;
			else l=mid+1;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}