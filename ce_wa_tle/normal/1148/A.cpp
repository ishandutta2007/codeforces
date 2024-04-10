#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <queue>
#include <iostream>
using namespace std;
#define ll long long
#define longinf 0x3f3f3f3f3f3f3f3f
#define zjhakioi \
freopen("cf.in","r",stdin);\
freopen("cf.out","w",stdout)
#define zjh int
#define ak main
#define ioi ()
ll n,m,s,t;
ll readll(void)
{
	ll x=0,w=1;char c=getchar();
	for(;c<'0'||c>'9';(c-'-')||(w*=-1),c=getchar());
	for(;c>='0'&&c<='9';x=(x<<1)+(x<<3)+(c^48),c=getchar());
	return x*w;
}
zjh ak ioi {
	//zjhakioi;
	ll a=readll(),b=readll(),c=readll();
	printf("%lld\n",(c<<1)+min(a+b,min(a,b)<<1|1));
	return 0;
}