#include<cstdio>
inline int read()
{
	int x=0;char c;
	while((c=getchar())<'0'||c>'9');
	for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
	return x;
}
#define MX 100000
int a[MX+5],f[MX+5],p[MX+5],pn;
int main()
{
	int n=read(),i,j,k,x,ans=1;
	for(i=2;i<=MX;++i)
	{
		if(!f[i])f[i]=i,p[++pn]=i;
		for(j=1;i*p[j]<=MX;++j){f[i*p[j]]=p[j];if(i%p[j]==0)break;}
	}
	for(i=0;i<n;++i)for(x=read();f[x];)
	{
		++a[f[x]];
		for(j=f[x];f[x]==j;x/=j);
	}
	for(i=1;i<=pn;++i)if(a[p[i]]>ans)ans=a[p[i]];
	printf("%d",ans);
}