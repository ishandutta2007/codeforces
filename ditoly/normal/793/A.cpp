#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 100000
int a[MN+5];
int main()
{
	int n=read(),k=read(),i,mn=0x7FFFFFFF;
	long long ans=0;
	for(i=1;i<=n;++i)mn=min(mn,a[i]=read());
	for(i=1;i<=n;++i)if((a[i]-mn)%k)return 0*puts("-1");else ans+=(a[i]-mn)/k;
	printf("%I64d",ans);
}