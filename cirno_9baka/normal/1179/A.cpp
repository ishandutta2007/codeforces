#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<set>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
const ll M=998244353;
const int N=1000005;
int n,m,q,i,a[N],p[N],l,r,ans1[N],ans2[N],mx,k;
long long x;
int main()
{
	scanf("%d %d",&n,&q);
	mx=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(mx<a[i])
			mx=a[i];
	}
	l=1;
	r=n;
	while(1)
	{
		int t1=a[l];
		int t2=a[l+1];
		ans1[++k]=t1;
		ans2[k]=t2;
		if(t1<t2)
		{
			a[++r]=t1;
			l++;
		}
		else
		{
			a[++r]=t2;
			a[++l]=t1;
		}
		if(a[l]==mx)
			break;
	}
	for(i=l+1;i<=r;i++)
		p[i-l]=a[i];
	for(i=1;i<=q;i++)
	{
		scanf("%I64d",&x);
		if(x<=k)
			printf("%d %d\n",ans1[x],ans2[x]);
		else
		{
			x=(x-k-1)%(n-1)+1;
			printf("%d %d\n",mx,p[x]);
		}
	}
}