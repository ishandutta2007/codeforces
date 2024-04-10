#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return x;
}
#define MN 200000
int a[MN+5],b[MN+5],c[MN+5],d[MN+5];
int main()
{
	int n,m,k,x,s,i,j;long long ans=4e18;
	n=read();m=read();k=read();a[0]=x=read();s=read();
	for(i=1;i<=m;++i)a[i]=read();
	for(i=1;i<=m;++i)b[i]=read();
	for(i=1;i<=k;++i)c[i]=read();
	for(i=1;i<=k;++i)d[i]=read();
	for(i=0;i<=m;++i)if(b[i]<=s)
	{
		j=upper_bound(d,d+k+1,s-b[i])-d-1;
		ans=min(ans,1LL*max(n-c[j],0)*a[i]);
	}
	printf("%I64d",ans);
}