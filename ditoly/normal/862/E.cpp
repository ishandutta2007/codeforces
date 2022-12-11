#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
inline int read()
{
	int x,f=1;char c;
	while((c=getchar())<'0'||c>'9')if(c=='-')f=0;
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return f?x:-x;
}
#define MN 100000
ll n,m,b[MN+5],z[MN+5],s;
ll query()
{
	int x=lower_bound(z+n-1,z+m+2,s)-z;
	return min(z[x]-s,s-z[x-1]);
}
int main()
{
	int q,i,l;
	n=read();m=read();q=read();
	for(i=1;i<=n;++i)s+=(i&1?1:-1)*read();
	for(i=1;i<=m;++i)
	{
		b[i]=b[i-1]+(i&1?1:-1)*read();
		if(i>=n)z[i]=((i-n)&1?-1:1)*(b[i]-b[i-n]);
	}
	sort(z+n,z+m+1);z[n-1]=-1e18;z[m+1]=1e18;
	printf("%I64d\n",query());
	while(q--)
	{
		if(l=read(),(read()-l+1)&1)s+=(l&1?1:-1)*read();else read();
		printf("%I64d\n",query());
	}
}