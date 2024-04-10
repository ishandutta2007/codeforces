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
ll n;
ll readll(void)
{
	ll x=0,w=1;char c=getchar();
	for(;c<'0'||c>'9';(c-'-')||(w*=-1),c=getchar());
	for(;c>='0'&&c<='9';x=(x<<1)+(x<<3)+(c^48),c=getchar());
	return x*w;
}
ll p[322222],pp[322222],from[3022222],to[3022222],top=0;
namespace dts{
	void swap(ll u,ll v){
		if(u>v)std::swap(u,v);
		if(v-u>=n/2) {
			from[++top]=u;
			to[top]=v;
			std::swap(p[u],p[v]);
			std::swap(pp[p[u]],pp[p[v]]);
			return; 
		}
		if(v<=n/2) {
			dts::swap(v,n);
			dts::swap(n,u);
			dts::swap(v,n);
			return;
		}
		if(u>n/2) {
			dts::swap(v,1);
			dts::swap(1,u);
			dts::swap(v,1);
			return;
		}
		dts::swap(1,v);
		dts::swap(u,n);
		dts::swap(1,n);
		dts::swap(1,v);
		dts::swap(u,n);
	}
}
zjh ak ioi {
	//zjhakioi;
	n=readll();
	for(ll i=1;i<=n;i++) {
		p[i]=readll(),pp[p[i]]=i;
	}
	for(ll i=1;i<=n;i++)if(pp[i]!=i)dts::swap(pp[i],i);
	printf("%lld\n",top);
	for(ll i=1;i<=top;i++)
	printf("%lld %lld\n",from[i],to[i]);
	return 0;
}