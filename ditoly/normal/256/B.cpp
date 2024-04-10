#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
ll cal(ll n,ll m,ll t)
{
	if(n>m)swap(n,m);
	if(t<=n)return t*(t+1)/2;
	if(t<=m)return (t-n)*n+n*(n+1)/2;
	t=max(n+m-1-t,0LL);
	return n*m-t*(t+1)/2;
}
int main()
{
	int n,x,y,c,l,r,mid,ans;
	scanf("%d%d%d%d",&n,&x,&y,&c);--c;
	for(l=0,r=2*n;l<=r;)
	{
		mid=l+(r-l)/2;
		if(cal(x-1,n-y+1,mid)+cal(n-x+1,n-y,mid)+
		   cal(n-x,y,mid)+cal(x,y-1,mid)<c)l=mid+1;
		else ans=mid,r=mid-1;
	}
	printf("%d",ans);
}