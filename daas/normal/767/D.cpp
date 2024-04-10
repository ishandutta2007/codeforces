#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int n,m,K,rest,NOW,a[1000001],ans;
struct sb
{
	int v,id;
}b[1000001];
int cmp(sb x,sb y)
{
	return x.v<y.v;
}
int check(int lim)
{
	int l=n,r=m;
	NOW=max(a[l],b[r].v)+1;
	rest=0;
	while(l>=1 || r>=lim)
	{
		if(l>=1 && (r<lim || a[l]>b[r].v))
		{
			if(NOW>a[l])
			{
				NOW=a[l];
				rest=K-1;
				if(!rest)
				{
					--NOW;
					rest=K;
				}
				--l;
			}
			else
			{
				rest--;
				if(!rest)
				{
					--NOW;
					rest=K;
				}
				--l;
			}
		}
		else
		{
			if(NOW>b[r].v)
			{
				NOW=b[r].v;
				rest=K-1;
				if(!rest)
				{
					--NOW;
					rest=K;
				}
				--r;
			}
			else
			{
				rest--;
				if(!rest)
				{
					--NOW;
					rest=K;
				}
				--r;
			}
		}
	}
	if(rest==K)
		++NOW;
	return NOW>=0;
}
int main()
{
	n=read(),m=read(),K=read();
	for(int i=1;i<=n;++i)
		a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=m;++i)
		b[i].v=read(),b[i].id=i;
	sort(b+1,b+m+1,cmp);
	ans=-1;
	int l=1,r=m+1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
			ans=mid,r=mid-1;
		else
			l=mid+1;
	}
	if(ans==-1)
		puts("-1");
	else
	{
		printf("%d\n",m-ans+1);
		for(int i=ans;i<=m;++i)
			printf("%d ",b[i].id);
		putchar('\n');
	}
	return 0;
}