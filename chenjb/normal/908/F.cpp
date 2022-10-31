#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#define rep(i,n) for(int i=1;i<=n;++i)
#define red(i,n) for(int i=n;i>=1;--i)
using namespace std;
struct node
{
	long long x;
	int c;
	friend bool operator <(node x,node y)
	{
		return x.x<y.x;
	}
}a[400001];
long long leftdata[400001],rightdata[400001];
int n;
long long ans;
long long max1,max2,l1,r1,ttt;
void work1()
{
	long long tans;
	l1=0;
	rep(i,n)
		if(a[i].c==0)
		{
			tans=ans;
			if(l1!=0)ans+=a[i].x-l1;
			l1=a[i].x;
		}
	
	l1=0;
	rep(i,n)
		if(a[i].c==1)
		{
			tans=ans;
			if(l1!=0)ans+=a[i].x-l1;
			l1=a[i].x;
		}
	cout<<ans<<endl;
}
void work2()
{
	long long tans;
	long long f1=0,f2=0;
	int sum=0;
	rep(i,n)
	{
		if(a[i].c==2)
		{
			max2=max(a[i].x-r1,max2);
			max1=max(a[i].x-l1,max1);
			sum++;
			if(sum==1)
			{
				tans=ans;
				if(f1!=0)ans=ans+a[i].x-f1;
				if(f2!=0)ans=ans+a[i].x-f2;
			}
			else
			{
				long long t1=a[i].x+a[i].x-ttt-ttt;
				long long t2=(a[i].x+a[i].x-ttt-ttt)-max1+(a[i].x-ttt)-max2;
				long long yzc=min(t1,t2);
				ans=ans+yzc;
			}
			l1=r1=ttt=a[i].x;
			max1=0;
			max2=0;
		}
		else 
		if(a[i].c==0)
		{
			if(f1==0)f1=a[i].x;
			if (max1<a[i].x-l1)max1=a[i].x-l1;
			l1=a[i].x;
		}
		else
		{
			if(f2==0)f2=a[i].x;
			if (max2<a[i].x-r1)max2=a[i].x-r1;
			r1=a[i].x;
		}
	}
	f1=0;  f2=0;
	red(i,n)
	{
		if(a[i].c==2)
		{
			tans=ans;
			if(f1!=0)ans=ans+f1-a[i].x;
			if(f2!=0)ans=ans+f2-a[i].x;
			break;
		}
		else if(a[i].c==0)
		{
			if(f1==0)f1=a[i].x;
		}
		else
		{
			tans=ans;
			if(f2==0)f2=a[i].x;
		}
	}
	cout<<ans<<endl;
}
int main()
{
	scanf("%d",&n);
	char tmp[123];
	int sumx=0;
	rep(i,n)
	{
		long long x;
		scanf("%lld",&x);
		scanf("%s",tmp);
		a[i].x=x;
		if(tmp[0]=='R')a[i].c=0;
		else 
		if(tmp[0]=='B')a[i].c=1;
		else a[i].c=2,sumx++;
	}
	sort(a+1,a+n+1);
	ans=max1=max2=l1=r1=ttt=0;
	if(sumx==0)work1();
	else work2();
	return 0;
}