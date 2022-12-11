#include<cstdio>
#define ll long long
inline ll read()
{
	ll x=0;char c;
	while((c=getchar())<'0'||c>'9');
	for(;c>='0'&&c<='9';c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 100000
ll a[MN+5];
int main()
{
	ll s,t,p,n,i,mn=1LL<<60,ans;
	s=read();t=read();p=read();n=read();
	for(i=1;i<=n;++i)a[i]=read();a[++n]=1LL<<60;
	for(i=1;i<=n;++i)if(a[i]!=a[i-1])
	{
		if(s+p*i>t)break;
		if(s+p*(i-1)<a[i])return printf("%I64d",s+p*(i-1)),0;
		if(s+p*(i-1)-a[i]+1<mn)mn=s+p*(i-1)-a[i]+1,ans=a[i]-1;
	}
	printf("%I64d",ans);
}