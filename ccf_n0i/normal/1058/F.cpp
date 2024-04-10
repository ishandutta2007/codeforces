#include <bits/stdc++.h>
using namespace std;
long long n,m,i,j,a[200005],x,y,op,l,r,mid,pos[200005],mod=1e9+7;
struct bit
{
	long long arr[200005];
	int lowbit(int x){return x&(-x);}
	void add(int x,long long y){for (int i=x;i<=n;i+=lowbit(i)) arr[i]+=y;}
	long long query(int x){long long s=0;for (int i=x;i>0;i-=lowbit(i)) s+=arr[i];return s;}
	long long query2(long long y)
	{
		int s=0,i;
		for (i=19;i>=0;i--)
		{
			s+=(1<<i);
			if (s>n||arr[s]>y) s-=(1<<i); else y-=arr[s];
		}
		return s+(y>0);
	}
};
struct bit2
{
	long long arr[200005];
	int lowbit(int x){return x&(-x);}
	void add(int x,long long y){for (int i=x;i<=n;i+=lowbit(i)) (arr[i]+=y)%=mod;}
	long long query(int x){long long s=0;for (int i=x;i>0;i-=lowbit(i)) (s+=arr[i])%=mod;return (s%mod+mod)%mod;}
};
bit c;bit2 d,e;
long long calc(long long x)
{
	return x*(x+1)/2;
}
int main()
{
	scanf("%I64d%I64d",&n,&m);
	for (i=1;i<=n;i++) scanf("%I64d",&pos[i]);
	for (i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		c.add(i,a[i]);
		d.add(i,a[i]*pos[i]);
		e.add(i,a[i]*i);
	}
	while (m--)
	{
		scanf("%I64d%I64d",&x,&y);
		if (x>0)
		{
			long long sum=c.query(y)-c.query(x-1);
			long long p=c.query2(c.query(x-1)+(sum+1)/2);
			long long ans=(((c.query(p-1)-c.query(x-1)))*pos[p]-(d.query(p-1)-d.query(x-1)));
			ans+=((d.query(y)-d.query(p))-(c.query(y)-c.query(p))*pos[p]);
			ans-=e.query(y)-e.query(p)-p*(c.query(y)-c.query(p));
			ans-=(c.query(p-1)-c.query(x-1))*p-(e.query(p-1)-e.query(x-1));
			printf("%I64d\n",(ans%mod+mod)%mod);
		}
		else
		{
			x=-x;
			c.add(x,-a[x]);
			d.add(x,-a[x]*pos[x]);
			e.add(x,-a[x]*x);
			a[x]=y;
			c.add(x,a[x]);
			d.add(x,a[x]*pos[x]);
			e.add(x,a[x]*x);
		}
	}
	return 0;
}