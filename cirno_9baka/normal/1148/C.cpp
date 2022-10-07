#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
const int N=100005,M=1000000007;
int n,a[300005],f[300005],i,j,ansa[2000005],ansb[2000005],m;
void Swap(int i,int j)
{
	swap(f[a[i]],f[a[j]]);
	swap(a[i],a[j]);
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		f[a[i]]=i;
	}
	for(i=2;i<=n/2;i++)
	{
		if(f[i]>n/2)
		{
			ansa[++m]=f[i];
			ansb[m]=1;
			Swap(f[i],1);
		}
		ansa[++m]=n;
		ansb[m]=f[i];
		Swap(f[i],n);
		ansa[++m]=i;
		ansb[m]=f[i];
		Swap(f[i],i);
	}
	for(i=n/2+1;i<n;i++)
	{
		if(f[i]<=n/2)
		{
			ansa[++m]=f[i];
			ansb[m]=n;
			Swap(f[i],n);
		}
		ansa[++m]=1;
		ansb[m]=f[i];
		Swap(f[i],1);
		ansa[++m]=i;
		ansb[m]=f[i];
		Swap(f[i],i);
	}
	if(f[1]!=1)
	{
		ansa[++m]=1;
		ansb[m]=n;
	}
	printf("%d\n",m);
	for(i=1;i<=m;i++)
		printf("%d %d\n",ansa[i],ansb[i]);
}