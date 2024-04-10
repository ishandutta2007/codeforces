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
	void work(void) {
		//...
		ll x=readll(),y=readll(),z=readll();
		ll xz=x%z,xdz=x/z,yz=y%z,ydz=y/z;
		if(xz+yz>=z) {
			printf("%lld %lld\n",xdz+ydz+1,std::min(z-xz,z-yz));
		}
		else {
			printf("%lld %lld\n",xdz+ydz,0ll);
		}
	}
}
zjh ak ioi {
	//zjhakioi;
	Compile_Easily__Wonderful_Answer__Time_Limit_Enough::work();
	return 0;
}