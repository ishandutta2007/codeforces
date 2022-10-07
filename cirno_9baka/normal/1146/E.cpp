#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
const int N=100005,M=1000000007;
int n,i,ans[100005],k,mx,p,t[100005],fa[200005],u[100005],q,x,j;
char s;
struct str{
	int s,x,p;
}a[100005];
bool cmp(str a,str b)
{
	return abs(a.x)<abs(b.x);
}
int lowbit(int x)
{
	return -x&x;
}
int poq=1;
void Push(int x)
{
	poq=-poq;
	while(x<=100000)
	{
		u[x]=-u[x];
		x+=lowbit(x);
	}
}
int Query(int x)
{
	int ans=poq;
	while(x>0)
	{
		ans=ans*u[x];
		x-=lowbit(x);
	}
	return ans;
}
int main(){
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;i++)
		scanf("%d",&t[i]);
	scanf("\n");
	for(i=0;i<=q;i++)
		u[i]=1;
	for(i=1;i<=q;i++)
	{
		scanf("%c %d\n",&s,&x);
		if(s=='<')
		{
			a[i]=(str){0,x,i};
			if(a[i].x>0)
				Push(i);
		}
		else
		{
			a[i]=(str){1,x,i};
			if(a[i].x<0)
				Push(i);
		}
	}
	sort(a+1,a+1+q,cmp);
	p=0;
	j=1;
	for(i=0;i<=100000;i++)
	{
		for(k=j;abs(a[k].x)==i&&k<=q;k++)
		{
			if(a[k].s==1&&a[k].x<0||a[k].s==0&&a[k].x>0)
				Push(a[k].p);
			if(a[k].s==1&&a[k].x<0&&mx<a[k].p)
			{
				p=-1;
				mx=a[k].p;
			}
			if(a[k].s==0&&a[k].x>0&&mx<a[k].p)
			{
				p=1;
				mx=a[k].p;
			}
		}
		int ans=Query(mx);
		if(p==0)
		{
			fa[i+100000]=ans*i;
			fa[-i+100000]=-ans*i;
		}
		else
			fa[i+100000]=fa[-i+100000]=p*ans*i;
		for(;abs(a[j].x)==i&&j<=q;j++)
		{
			if(a[j].s==0)
				if(mx<a[j].p)
				{
					mx=a[j].p;
					p=1;
				}
			if(a[j].s==1)
				if(mx<a[j].p)
				{
					mx=a[j].p;
					p=-1;
				}
		}
	}
	for(i=1;i<=n;i++)
		printf("%d ",fa[t[i]+100000]);
}