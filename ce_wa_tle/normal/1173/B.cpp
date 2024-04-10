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
	ll readll(void)
	{
		ll x=0,w=1;char c=getchar();
		for(;c<'0'||c>'9';(c-'-')||(w*=-1),c=getchar());
		for(;c>='0'&&c<='9';x=(x<<1)+(x<<3)+(c^48),c=getchar());
		return x*w;
	}
	void work(void) {
		ll n=readll();
		printf("%lld\n",(n>>1)+1);
		for(ll i=1,a=1,b=1;i<=n;i++)
		if (i&1) {
			printf("%lld %lld\n",a,b++);
		}
		else {
			printf("%lld %lld\n",a++,b);
		}
	} 
}
zjh ak ioi {
	//zjhakioi;
	Compile_Easily__Wonderful_Answer__Time_Limit_Enough::work();
	return 0;
}