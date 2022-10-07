#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;
int n,i,x[1000005],k,t[1000005],c[1000005],j;
long long s,ans;
struct str{
	int x,y;
}a[1000005];
bool cmp(str a,str b)
{
	if(a.y==b.y)
		return a.x<b.x;
	return a.y>b.y;
}
int lowbit(int x)
{
	return -x&x;
}
void modify(int x)
{
	while(x<=k)
	{
		t[x]++;
		x+=lowbit(x);
	}
}
int Query(int x)
{
	int ans=0;
	while(x>0)
	{
		ans+=t[x];
		x-=lowbit(x);
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&a[i].x,&a[i].y);
		x[i]=a[i].x;
	}
	sort(a+1,a+1+n,cmp);
	sort(x+1,x+1+n);
	for(i=1;i<=n;i++)
		if(x[k]!=x[i])
			x[++k]=x[i];
	for(i=1;i<=n;i++)
		c[i]=lower_bound(x+1,x+1+k,a[i].x)-x;
	for(i=1;i<=n;)
	{
		s=0;
		for(j=i;j<=n&&a[j].y==a[i].y;j++)
		{
			if(j==i)
			{
				long long tmp=Query(c[j]-1);
				s+=tmp*(tmp+1)/2;
			}
			else
			{
				long long tmp=Query(c[j]-1)-Query(c[j-1]);
				s+=tmp*(tmp+1)/2;
			}
			if(Query(c[j])-Query(c[j]-1)!=1)
				modify(c[j]);
		}
		long long tmp=Query(k)-Query(c[j-1]);
		s+=tmp*(tmp+1)/2;
		ans=ans+1ll*Query(k)*(Query(k)+1)/2-s;
		i=j;
	}
	cout<<ans;
}