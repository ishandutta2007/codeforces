/**/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <queue>
#include <iostream>
#define ll long long
#define longinf 0x3f3f3f3f3f3f3f3f
#define zjhakioi \
freopen("cf.in","r",stdin);\
freopen("cf.out","w",stdout)
#define zjh int
#define ak main
#define ioi ()
namespace Compile_Easily__Wonderful_Answer__Time_Limit_Enough{
	ll zt[111],next[1<<13],f[111][1<<13];
	ll readll(void)
	{
		ll x=0,w=1;char c=getchar();
		for(;c<'0'||c>'9';(c-'-')||(w*=-1),c=getchar());
		for(;c>='0'&&c<='9';x=(x<<1)+(x<<3)+(c^48),c=getchar());
		return x*w;
	}
	char readchar(void)
	{
		char c=getchar();
		for(;c<'0'||c>'9';c=getchar());
		return c;
	}
	ll a[111111],b[111111],c[111111],n;
	void work2(ll x) {
		for(ll i=1;i<=n;i++)b[i]=0ll;
		for(ll i=x;i;i--)b[x-i+1]=a[i];
		for(ll i=n;i>x;i--)b[n-i+1]+=a[i];
		//printf("%lld\n",x);
		//for(ll i=n;i;i--)putchar(int(b[i]+48));
		//puts("");
		for(ll i=1;i<=n;i++)b[i+1]+=b[i]/10,b[i]%=10;
		for(ll i=n;i;i--)
		if(c[i]<b[i]) {
			return;
		}
		else
		if(c[i]>b[i]){
			break;
		}
		for(ll i=1;i<=n;i++)c[i]=b[i];
	}
	void work(void) {
		//...
		n=readll();
		for(ll i=1;i<=n;i++)a[i]=readchar()-48,c[i]=9;
		ll ii=n/2;
		for(ii=n/2;a[ii+1]==0&&ii;ii--);
		//printf("%lld\n",ii);
		work2(ii);
		//ii=n/2+1;
		for(ii=n/2+1;a[ii+1]==0&&ii<=n;ii++);
		//printf("%lld\n",ii);
		work2(ii);
		//for(ll i=n;i;i--)putchar(int(c[i]+48));
		//puts("");
		for(ll i=n,p=0;i;i--) {
			if(c[i])p=1;
			if(p) {
				putchar(int(c[i]+48));
			}
		}
	}
}
zjh ak ioi {
	//zjhakioi;
	Compile_Easily__Wonderful_Answer__Time_Limit_Enough::work();
	return 0;
}