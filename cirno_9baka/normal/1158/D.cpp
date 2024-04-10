#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
const int M=998244353;
typedef long long ll;
int n,i,m,j,x[2005],y[2005],vis[10005],p[10005],s;
char c[2005];
ll clac(ll a1,ll a2,ll b1,ll b2)
{
	return a1*b2-a2*b1;
}
bool rp(int j,int i,int l)
{
	ll a1=x[j]-x[l],a2=x[i]-x[l],b1=y[j]-y[l],b2=y[i]-y[l];
	ll tmp=clac(a1,a2,b1,b2);
	if(tmp>0)
		return true;
	return false;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d %d",&x[i],&y[i]);
	scanf("%s",c+1);
	s=1;
	for(i=1;i<=n;i++)
	{
		if(x[i]==x[s])
			if(y[i]<y[s])
				s=i;
		if(x[i]<x[s])
			s=i;
	}
	vis[s]=1;
	p[1]=s;
	for(i=1;i<=n-2;i++)
	{
		s=0;
		if(c[i]=='R')
		{
			for(j=1;j<=n;j++)
				if(vis[j]==0)
					if(s==0)
						s=j;
					else
						if(rp(s,j,p[i]))
							s=j;
			vis[s]=1;
			p[i+1]=s;
		}
		else
		{
			for(j=1;j<=n;j++)
				if(vis[j]==0)
					if(s==0)
						s=j;
					else
						if(!rp(s,j,p[i]))
							s=j;
			vis[s]=1;
			p[i+1]=s;
		}
	}
	for(i=1;i<=n;i++)
		if(vis[i]==0)
			p[n]=i;
	for(i=1;i<=n;i++)
		printf("%d ",p[i]);
}