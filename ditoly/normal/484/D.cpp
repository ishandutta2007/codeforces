#include<cstdio>
#include<algorithm>
using namespace std;
inline int read()
{
	int x=0,f=1;char c;
	while((c=getchar())<'0'||c>'9')if(c=='-')f=0;
	for(x=c-'0';(c=getchar())>='0'&&c<='9';)x=x*10+c-'0';
	return f?x:-x;
}
#define MN 1000000
int a[MN+5];long long f[MN+5],mx1,mx2;
int main()
{
	int n=read(),i;
	for(i=1;i<=n;++i)a[i]=read();mx1=-a[1];mx2=a[1];
	for(i=1;i<=n;++i)f[i]=max(mx1+a[i],mx2-a[i]),mx1=max(mx1,f[i]-a[i+1]),mx2=max(mx2,f[i]+a[i+1]);
	printf("%I64d",f[n]);
}