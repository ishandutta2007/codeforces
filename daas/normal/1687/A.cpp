#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int T,n,K,val[200010];
ll pre[200010];
int main()
{
	T=read();
	while(T--)
	{
		n=read(),K=read();
		for(int i=1;i<=n;++i) val[i]=read();
		if(K>n)
		{
			ll ans=(ll)(K-n+1+K)*n/2-n;
			for(int i=1;i<=n;++i) ans+=val[i];
			printf("%lld\n",ans);
		}
		else
		{
			ll ans=(ll)(K+1)*K/2-K,maxn=0;
			for(int i=1;i<=n;++i) pre[i]=pre[i-1]+val[i];
			for(int i=K;i<=n;++i) maxn=max(maxn,pre[i]-pre[i-K]);
			ans+=maxn;
			printf("%lld\n",ans);
		}
	}
	return 0;
}
//ore no turn,draw!