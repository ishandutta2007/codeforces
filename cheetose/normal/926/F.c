#include<stdio.h>
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
typedef long long ll;
ll min(ll a,ll b)
{
    if(a<b)return a;
    return b;
}
int n;
ll p,m;
ll d[100001],t[100000];
int main() {
	scanf("%d%I64d%I64d",&n,&p,&m);
	fup(i,0,n-1,1)
		scanf("%I64d%I64d",d+i,t+i);
	d[n]=m+1;
	ll now=-(d[0]-1)*p,ans=0;
	fup(i,0,n-1,1)
	{
		now+=t[i];
		ll l=d[i+1]-d[i];
		ll T=now/p;
		if(T<0)T=0;
		ans+=min(l,T);
		now-=l*p;
	}
	printf("%I64d",m-ans);
}