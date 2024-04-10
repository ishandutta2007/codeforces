#include<bits/stdc++.h>
#define maxl 300010
using namespace std;
 
int n,m,ans,up,top;
unsigned long long k;
unsigned long long st[201],ed[201],sum[201],num[201];
int s[maxl];
 
inline void init()
{
	unsigned long long mi=1;
	st[0]=0;ed[0]=0;
	for(int i=1;i<=64;i++)
	{
		st[i]=ed[i-1]+i;
		num[i]=((mi*10-1)-mi+1);
		ed[i]=st[i]+i*(num[i]-1);
		sum[i]=sum[i-1]+(st[i]+ed[i])*num[i]/2;
		up=i;
		if(sum[i]>=1e18)
			break;
		mi*=10;
	}
}
 
inline void prework()
{
	scanf("%lld",&k);
}
 
inline int findans(unsigned long long x,int pos)
{
	top=0;
	while(x>0)
	{
		s[++top]=x%10;
		x/=10;
	}
	return s[top-pos+1];
}
 
inline void mainwork()
{
	unsigned long long mi=1,id;
	for(int i=1;i<=up;i++)
	{
		if(sum[i]>=k)
		{
			id=i;
			break;
		}
		mi*=10;
	}
	k-=sum[id-1];
	unsigned long long l=0,r=num[id]-1,mid;
	unsigned long long t,d;
	while(l+1<r)
	{
		mid=(l+r)>>1;
		t=(st[id]+id*(mid-1)+st[id])*mid/2;
		if(t<k)
			l=mid;
		else
			r=mid;
	}
	if((st[id]+id*(r-1)+st[id])*r/2<k)
		d=r;
	else
		d=r-1;
	k-=(st[id]+id*(d-1)+st[id])*d/2;
	unsigned long long len=st[id]+d,sum=0;
	for(int i=1;i<=up;i++)
	{
		if(k<=num[i]*i)
		{
			id=i;
			break;
		}
		k-=num[i]*i;sum+=num[i];
	}
	unsigned long long val=k/id;
	if(k%id==0)
		ans=findans(val+sum,id);
	else
		ans=findans(val+sum+1,k%id);
}
 
inline void print()
{
	printf("%d\n",ans);
}
 
int main()
{
	init();
	int t=1;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		prework();
		mainwork();
		print();
	}
	return 0;
}