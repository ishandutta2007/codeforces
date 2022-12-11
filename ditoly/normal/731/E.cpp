#include<cstdio>
int read()
{
	int x=0,f=1;char c;
	while((c=getchar())<'0'||c>'9')if(c=='-')f=-f;
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return x*f;
}
#define ll long long
#define MAXN 200000
int s[MAXN+5];
inline ll max(ll a,ll b){return a>b?a:b;}
int main()
{
	int n=read(),i;
	ll x,mx;
	for(i=1;i<=n;i++)s[i]=s[i-1]+read();
	for(mx=s[i=n];--i>1;)mx=max(mx,s[i]-mx);
	printf("%I64d",mx);
}