#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define int long long

using namespace std;

int read()
{
	int ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const int N=1e6+5,mod=1e9+7;
int n,a[N],vis[N],ans=1;

inline int q_pow(int a,int b,int p);

signed main()
{
	n=read();
	for(int i=1;i<=n;++i)
		ans=(ans*i)%mod;
	ans=((ans-q_pow(2,n-1,mod))%mod+mod)%mod;
	printf("%lld\n",ans);
	return 0;
}


inline int q_pow(int a,int b,int p)
{
	int c=1;
	while(b)
	{
		if(b&1) c=a*c%p;
		b>>=1;
		a=a*a%p;
	}
	return c;
}