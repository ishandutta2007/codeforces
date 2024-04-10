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

const int N=3e5+5,mod=998244353;
int n,m,mmax,pos,jc[N],a[N],b[N],c[N],vis[N],x[N],y[N],ans;

map<int,int> mp;

inline int q_pow(int a,int b,int p);

signed main()
{
	n=read();jc[0]=1;
	for(int i=1;i<=2*n;++i)
	{
		a[i]=read();
		mp[a[i]]++;jc[i]=jc[i-1]*i%mod;
		int tmp=mp[a[i]];
		if(tmp>mmax)
		{
			mmax=tmp;
			pos=a[i];
		}
	}
	m=jc[2*n]*q_pow(jc[n]*jc[n]%mod,mod-2,mod)%mod;
	sort(a+1,a+1+n*2);
	if(1)
	{
		for(int i=1;i<=n;++i)
			ans=((ans-a[i]*m%mod)%mod+mod)%mod;
		for(int i=n+1;i<=n*2;++i)
			ans=(ans+a[i]*m%mod)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}

inline int q_pow(int a,int b,int p)
{
	int c=1;
	while(b>0)
	{
		if(b&1) c=a*c%p;
		b>>=1;a=a*a%p;
	}
	return c;
}