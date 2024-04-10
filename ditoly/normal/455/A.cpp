#include<iostream>
#include<cstdio>
#define MN 100000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int num[MN+5],n;
long long f[MN+5],F[MN+5],ans=0;
int main()
{
	n=read();
	for(int i=1;i<=n;++i) ++num[read()],f[i]=F[i]=-1e18;
	for(int i=1;i<=MN;++i)
	{
		f[i]=max(f[i-1],F[i-1]);
		F[i]=f[i-1]+1LL*num[i]*i;	
	}
	for(int i=1;i<=MN;++i) ans=max(ans,F[i]);
	printf("%lld\n",ans);
	return 0;
}