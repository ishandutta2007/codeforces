#include<bits/stdc++.h>
using namespace std;
const int M=998244353,L=5000,N=1000005;
int n,i,t,m,j,a[N],b[N];
bool cmp(int a,int b)
{
	return a>b;
}
bool check(int d)
{
	for(i=n+1;i<=n+d;++i)
	{
		a[i]=100;
		b[i]=0;
	}
	int x=n+d-(n+d)/4;
	int s1=0,s2=0;
	for(i=n+d;i>n+d-x;--i)
		s1+=a[i];
	for(i=1;i<=x;++i)
		s2+=b[i];
	return s1>=s2;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)
			scanf("%d",&a[i]);
		for(i=1;i<=n;++i)
			scanf("%d",&b[i]);
		sort(a+1,a+1+n);
		sort(b+1,b+1+n,cmp);
		int l=0,r=n+5;
		while(l<r)
		{
			int mid=l+r>>1;
			if(check(mid))
				r=mid;
			else
				l=mid+1;
		}
		printf("%d\n",l);
	}
}