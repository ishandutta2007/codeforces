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
		ll x=readll(),y=readll(),z=readll();
		ll maxx=x+z-y,minn=x-z-y;
		if(maxx>0&&minn>0) {
			puts("+");
			return;
		}
		if(maxx==0&&minn==0) {
			puts("0");
			return;
		}
		if(maxx<0&&minn<0) {
			puts("-");
			return;
		}
		puts("?");
	}
}
zjh ak ioi {
	//zjhakioi;
	Compile_Easily__Wonderful_Answer__Time_Limit_Enough::work();
	return 0;
}