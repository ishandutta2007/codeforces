#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;++i)
#define ref(i,l,r) rfor(ll i=l;i<r;++i)
#define per(i,l,r) rfor(ll i=l;i>=r;--i)
#define rfor(x...) for(register x)
#define IO(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout)
#define dprintf(x...) (void)(0)
#define _cl_lj(a,b) a##b
#define cl_lj(a,b) _cl_lj(a,b)
#define calc_in_func_df(calcer_t,calcer,code...) struct calcer_t{calcer_t(){code}};static calcer_t calcer
#define calc_in_func(code...) calc_in_func_df(cl_lj(calcer_t,__LINE__),cl_lj(calcer,__LINE__),code)
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3f;
using std::max;
using std::min;
inline ll readll(void){
	ll x=0,w=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch-'-'||(w=-w),ch=getchar());
	for(;ch>='0'&&ch<='9';x=(x<<1)+(x<<3)+(ch^48),ch=getchar());
	return x*w;
}
inline ll iabs(ll x){
	return max(x,-x);
}
//#define a=b a=0-b
//#define b y,
inline int readchar(void){
	int ch=getchar();
	for(;ch==' '||ch=='\n'||ch=='\r'||ch=='\t';ch=getchar());
	return ch;
}
ll a[114514];
int main(int QwQcOrZ,char*Recall_902_[]){
//	IO(A);
	ll t=readll();
	while(t --> 0){
		ll n=readll(),k=readll();
		printf("%lld\n",(n&1?k-1+(k-1)/(n/2):k-1)%n+1);
		//n/2
		//3 1
		// 2 3
		// 1 2
		// 3 1
		// 2 3
		// 1 2
		
		//5 1
		//4 2
		// 3 4
		//2 5
		// 1 2
		//5 3
		// 4 5
		//3 1
		// 2 3
		//1 4
	}
	return 0;
}