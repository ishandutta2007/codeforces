#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
int n,l,r,t,u,a[1000005],leng,f[1000005],i,j,k,tmp[1005],m,g;
int gcd(int a,int b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main(){
	srand(998244353);
	scanf("%d",&n);
	l=1;
	r=1000000000;
	while(l<r)
	{
		int mid=(l+r)/2;
		printf("> %d\n",mid);
		fflush(stdout);
		scanf("%d",&t);
		u++;
		if(t==1)
			l=mid+1;
		else
			r=mid;
	}
	for(i=1;i<=60-u&&i<=n;i++)
		a[i]=1ll*rand()*rand()%(n-i+1)+1;
	for(i=1;i<=60-u&&i<=n;i++)
	{
		k=0;
		for(j=1;j<=n;j++)
			if(f[j]==0)
			{
				k++;
				if(k==a[i])
					break;
			}
		f[j]=1;
		printf("? %d\n",j);
		fflush(stdout);
		scanf("%d",&t);
		tmp[++m]=t;
	}
	sort(tmp+1,tmp+1+m);
	g=tmp[2]-tmp[1];
	for(i=3;i<=m;i++)
		g=gcd(g,tmp[i]-tmp[i-1]);
	printf("! %d %d\n",l-g*(n-1),g);
	fflush(stdout);
}