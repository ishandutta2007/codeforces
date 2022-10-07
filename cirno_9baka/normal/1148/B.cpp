#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
const int N=100005,M=1000000007;
int a[500005],n,m,ta,tb,i,k,b[500005],ans,l,r;
int main(){
	scanf("%d %d %d %d %d",&n,&m,&ta,&tb,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]+=ta;
	}
	if(k>=n||k>=m)
	{
		printf("-1");
		return 0;
	}
	for(i=1;i<=m;i++)
		scanf("%d",&b[i]);
	r=m;
	for(i=k;i>=0;i--)
	{
		while(b[r]>=a[i+1])
			r--;
		if(r+k-i>=m)
		{
			printf("-1");
			return 0;
		}
		ans=max(ans,b[r+k-i+1]);
	}
	cout<<ans*1ll+tb;
}