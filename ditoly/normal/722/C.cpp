#include<cstdio>
int read()
{
	int x=0;char c;
	while((c=getchar())<'0'||c>'9');
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return x;
}
#define ll long long
#define MAXN 100000
int d[MAXN+5],l[MAXN+5],r[MAXN+5];
ll s[MAXN+5],ans[MAXN+5];
int gf(int*f,int k){return f[k]?f[k]=gf(f,f[k]):k;}
int main()
{
	int n=read(),i;ll mx=0,t;
	for(i=1;i<=n;i++)s[i]=s[i-1]+read();
	for(i=1;i<=n;i++)d[i]=read();
	for(i=n;i;i--)
	{
		ans[i]=mx;
		t=s[gf(r,d[i])]-s[gf(l,d[i])-1];
		if(t>mx)mx=t;
		r[d[i]-1]=d[i];l[d[i]+1]=d[i];
	}
	for(i=1;i<=n;i++)printf("%I64d\n",ans[i]);
}