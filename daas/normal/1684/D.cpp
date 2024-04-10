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
int T,n,K,a[200010],val[200010];
ll ans,pls;
int main()
{
	T=read();
	while(T--)
	{
		n=read(),K=read();
		ll ans=0;
		for(int i=1;i<=n;++i) a[i]=read(),ans+=a[i];
		for(int i=1;i<=n;++i) val[i]=n-i-a[i];
		sort(val+1,val+n+1);
		pls=0;
		ll cur=0;
		for(int i=0;i<=K;++i)
		{
			pls=min(pls,cur-(ll)(i-1)*i/2);
			cur+=val[i+1];
		}
		printf("%lld\n",ans+pls);
	}
	return 0;
}
//ore no turn,draw!