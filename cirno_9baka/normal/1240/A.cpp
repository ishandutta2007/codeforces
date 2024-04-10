#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
const int M=1000000007;
#define ri register int 
int n,p[200005],i,x,a,y,b,l,r,visa[200005],visb[200005],q;
ll k;
bool cmp(int a,int b)
{
	return a>b;
}
bool check(int m)
{
	ll ans=0;
	memset(visa,0,sizeof(visa));
	memset(visb,0,sizeof(visb));
	for(i=1;i<=m;i++)
	{
		if(i%a==0)
			visa[i]=1;
		if(i%b==0)
			visb[i]=1;
	}
	int o,e,t;
	o=e=t=0;
	for(i=1;i<=m;i++)
		if(visa[i]&&visb[i])
			t++;
		else
			if(visa[i])
				o++;
			else
				if(visb[i])
					e++;
	for(i=1;i<=t;i++)
		ans+=p[i]/100*(x+y);
	for(i=t+1;i<=t+o;i++)
		ans+=p[i]/100*x;
	for(i=t+o+1;i<=t+o+e;i++)
		ans+=p[i]/100*y;
	return (ans>=k);
}
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",&p[i]);
		sort(p+1,p+1+n,cmp);
		scanf("%d %d",&x,&a);
		scanf("%d %d",&y,&b);
		if(x<y)
		{
			swap(x,y);
			swap(a,b);
		}
		scanf("%lld",&k);
		l=1;r=n+1;
		while(l<r)
		{
			int mid=(l+r)/2;
			if(check(mid))
				r=mid;
			else
				l=mid+1;
		}
		if(l==n+1)
			printf("-1\n");
		else
			printf("%d\n",l);
	}
}