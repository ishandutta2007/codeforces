#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
inline int read()
{
	int x=0;char c;
	while((c=getchar())<'0'||c>'9');
	for(;c>='0'&&c<='9';c=getchar())x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 10000
#define INF (1LL<<60)
int a[MN+5],b[MN+5];
ll f[MN+5],ans=INF;
int main()
{
	int n=read(),c=read(),i,j;
	for(i=1;i<=n;++i)a[i]=read();
	for(i=1;i<=n;++i)b[i]=read();
	for(i=1;i<=n;++i)for(j=i;j>=0;--j)
		f[j]=min(j<i?f[j]+a[i]+(ll)c*j:INF,j?f[j-1]+b[i]:INF);
	for(i=0;i<=n;++i)ans=min(ans,f[i]);
	printf("%I64d",ans);
}