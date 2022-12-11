#include<cstdio>
inline int read()
{
	int x;char c;
	while((c=getchar())<'0'||c>'9');
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=(x<<3)+(x<<1)+c-'0';
	return x;
}
#define MN 200000
long long a[MN+5];
int main()
{
	int n,k,i;double ans=0;
	n=read();k=read();
	for(i=1;i<=n;++i)a[i]=a[i-1]+read();
	for(i=k;i<=n;++i)ans+=(double)(a[i]-a[i-k])/(n-k+1);
	printf("%.10lf",ans);
}