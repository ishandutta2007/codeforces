#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 100
using namespace std;
int n,m,a[N+5];
long long v[N+5],Alice,Bob,First,Second;
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%lld",v+i);
	for(int len=(m<<1)-1;len>2;--len)
	{
		int lmid=(len-1)>>1,dis=lmid-max(0,len-m-1),rmid=lmid+1+(!(len&1)),cnt=0,maxn=0,max1=0;
		for(int i=1;i<=n;++i)
		{
			a[i]=v[i]%len;
			if(a[i]<rmid) dis=min(dis,lmid-a[i]);
			if(a[i]>lmid) dis=min(dis,a[i]-rmid+1);
			cnt+=a[i]>=rmid;
			if(a[i]>=maxn) max1=maxn,maxn=a[i];
			else if(a[i]>max1) max1=a[i];
		}
		if(dis>0) cnt&1?(First+=min(lmid-(max1>>1),dis)):(Second+=min(lmid-(maxn>>1),dis));
	}
	First<<=1,Second<<=1;
	for(int len=m<<1;len;len-=2)
	{
		int cnt=0;
		for(int i=1;i<=n;++i)
			cnt+=v[i]%len>=(len>>1);
		cnt&1?++First:++Second;
	}
	Alice=Bob=(1ll*m*m-First-Second)>>1;
	printf("%lld %lld %lld %lld",Alice,Bob,First,Second);
	return 0;
}