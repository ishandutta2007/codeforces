#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
#define IO(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);
#define rep(i,l,u) rfor(ll i=l;i<=u;i++)
#define per(i,l,u) rfor(ll i=l;i>=u;i--)
#define rfor(x...) for(register x)
#define ifn(x...) if(!(x))
#define max(x,y) std::max(ll(x),ll(y))
#define min(x,y) std::min(ll(x),ll(y))
#define lower_bound std::lower_bound
typedef long long ll;
typedef long double ld;
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline ll readll(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline bool blank(const char ch){
	return ch==' '||ch=='\n'||ch=='\t'||ch=='\r'||ch==-1;
}
inline void reads(char*s){
	char ch=gc();
	while(blank(ch))ch=gc();
	while(!blank(ch))*s++=ch,ch=gc();
	*s=0;
}
const ll inf=0x3f3f3f3f3f3f3f;
ll cnt=0,n,head[444444],next[444444],to[444444],a[444444],longest[444444],longson[444444],*dp1[444444],*dp2[444444],top1[444444],top2[444444];
ll*new_arr(ll size){static ll r0[5556555],*s=r0;s+=size;return s-size;}
inline void add(ll u,ll v){
	++cnt;
	to[cnt]=v;
	next[cnt]=head[u];
	head[u]=cnt;
}
void dfs1(ll u,ll fa){
	longest[u]=1,longson[u]=0;
	rfor(ll i=head[u];i;i=next[i])(to[i]^fa)&&(dfs1(to[i],u),longest[to[i]]>=longest[u]&&(longest[u]=-~longest[longson[u]=to[i]]));
}
ll ans=0;
void dfs2(ll u,ll fa){
//	rep(i,1,longest[u])dp1[u][i]=inf,dp2[u][i]=-inf;
	if(longson[u]){
		dp1[longson[u]]=dp1[u],dp2[longson[u]]=dp2[u];
		dfs2(longson[u],u);
		top1[u]=top1[longson[u]],top2[u]=top2[longson[u]];
//	printf("%lld %lld\n",dp1[u][top1[u]],dp2[u][top2[u]]);
	}
	else{
		dp1[u][top1[u]=1]=a[u],dp2[u][top2[u]=1]=a[u];
//	printf("%lld %lld\n",dp1[u][top1[u]],dp2[u][top2[u]]);
		ans=max(ans,1ll);
		return;
	}	
//	return;
	//dp[u]=min(dp[v])
	rfor(ll i=head[u];i;i=next[i])
	if(to[i]^fa&&to[i]^longson[u]){
		register ll v=to[i];
		dp1[v]=new_arr(longest[v]+3);
		dp2[v]=new_arr(longest[v]+3);
		dfs2(v,u);
		register ll k=top2[u];
		rep(j,1,top1[v]){
			while(dp2[u][k]<=dp1[v][j]&&k)k--;
//			ll lk=k;
//			k=lower_bound(dp2[u]+1,dp2[u]+top2[u]+1,dp1[v][j],std::greater<ll>())-dp2[u]-1;
//			if(k!=lk){
//				printf("You die.%lld %lld %lld %lld\n",u,lk,k,dp1[v][j]);
//				rep(i,1,top2[u]){
//					printf("%lld ",dp2[u][i]);
//				}
//			}
			ans=max(ans,k+j);
		}
		ans=max(ans,lower_bound(dp2[u]+1,dp2[u]+top2[u]+1,a[u],std::greater<ll>())-dp2[u]-1
		+lower_bound(dp1[v]+1,dp1[v]+top1[v]+1,a[u])-dp1[v]-1+1);
		k=top1[u];
		rep(j,1,top2[v]){
			while(dp1[u][k]>=dp2[v][j]&&k)k--;
			ans=max(ans,k+j);
		}
		ans=max(ans,lower_bound(dp1[u]+1,dp1[u]+top1[u]+1,a[u])-dp1[u]-1
		+lower_bound(dp2[v]+1,dp2[v]+top2[v]+1,a[u],std::greater<ll>())-dp2[v]-1+1);
		rep(j,1,top1[v]){
			dp1[u][j]=j<=top1[u]?min(dp1[u][j],dp1[v][j]):dp1[v][j];
		}
		rep(j,1,top2[v]){
			dp2[u][j]=j<=top2[u]?max(dp2[u][j],dp2[v][j]):dp2[v][j];
		}
		top1[u]=max(top1[u],top1[v]);
		top2[u]=max(top2[u],top2[v]);
	}
//	printf("%lld %lld\n",dp1[u][top1[u]],dp2[u][top2[u]]);
	if(a[u]>dp1[u][top1[u]]){
		dp1[u][++top1[u]]=a[u];
	}
	else{
		*lower_bound(dp1[u]+1,dp1[u]+top1[u]+1,a[u])=a[u];
	}
	if(a[u]<dp2[u][top2[u]]){
		dp2[u][++top2[u]]=a[u];
	}
	else{
		*lower_bound(dp2[u]+1,dp2[u]+top2[u]+1,a[u],std::greater<ll>())=a[u];
	}
	ans=max(ans,max(top1[u],top2[u]));
}
int main(){
	//IO(sub);
	n=readll();
	rep(i,1,n)a[i]=readll();//,min=min(v[i],min),max=max(v[i],max);
	rep(i,1,n-1){
		ll x=readll(),y=readll();
		add(x,y);
		add(y,x);
	}
	dfs1(1,0);
	dp1[1]=new_arr(longest[1]);
	dp2[1]=new_arr(longest[1]);
//	return 0;
	dfs2(1,0);
	printf("%lld\n",ans);
	return 0;
}
//ll n,rt2=0,rt1=0,p1=1,p2=1,min=1e9+7,max=-min;
//void ad(ll x){
//	if(d[x]>1){
////		printf("%lld\n",d[x]);
//		if(rt2&&rt2!=x)p2=0;
//		else rt2=x;
//	}
//	if(d[x]>2){
//		p1=0;
//	}
//}
//		d[x]++,d[y]++;
//		ad(x);ad(y);
//	if(p1){
//		rep(i,1,n)if(d[i]==1)rt1=i;
//		ll u=rt1;
////			printf("%lld\n",u);
//		ll top1=1,top2=1;s1[0]=-1e9+7;s2[0]=1e9+7;s1[1]=v[u],s2[1]=v[u];
//		vis[u]=1;
//		rfor(ll i=2;i<=n;i++){
//			rfor(ll j=head[u];j;j=next[j])
//			if(!vis[to[j]]){u=to[j];break;}
//			vis[u]=1;
////			printf("%lld\n",u);
//			if(v[u]>s1[top1]){
//				s1[++top1]=v[u];
//			}
//			else{
//				*std::lower_bound(s1+1,s1+top1+1,v[u])=v[u];
//			}
//			if(v[u]<s2[top2]){
//				s2[++top2]=v[u];
//			}
//			else{
//				*std::lower_bound(s2+1,s2+top2+1,v[u],std::greater<ll>())=v[u];
//			}
//		}
//		printf("%lld\n",max(top1,top2));
//		return 0;
//	}
//	if(p2){
//		printf("%lld\n",max==min?1ll:max>v[rt2]&&min<v[rt2]?3ll:2ll);
//		return 0;
//	}