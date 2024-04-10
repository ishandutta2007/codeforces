#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;++i)
#define ref(i,l,r) rfor(ll i=l;i<r;++i)
#define per(i,l,r) rfor(ll i=l;i>=r;--i)
#define rfor(x...) for(register x)
#define IO(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout)
#define dprintf(x...)fprintf(stderr,x)
#define _cl_lj(a,b) a##b
#define cl_lj(a,b) _cl_lj(a,b)
#define calc_in_func_df(calcer_t,calcer,code...) struct calcer_t{calcer_t(){code}};static calcer_t calcer
#define calc_in_func(code...) calc_in_func_df(cl_lj(calcer_t,__LINE__),cl_lj(calcer,__LINE__),code)
typedef long long ll;typedef long double ld;
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
inline void writell(ll x,int c='\0'){
	static ll s[112];ll*n=s;
	while(x||n==s)*++n=x%10,x/=10;
	while(n!=s)putchar(*n--^48);
	if(c)putchar(c);
}
inline ll iabs(ll x){
	return max(x,-x);
}
inline int readchar(void){
	int ch=getchar();
	for(;ch==' '||ch=='\n'||ch=='\r'||ch=='\t';ch=getchar());
	return ch;
}
//const ll mod=998244353;
//typedef ll arr[314514];
//inline ll pow(ll a,ll b){/*printf("%lld^%lld=",a,b);*/ll ans=1;while(b)b&1&&(ans=ans*a%mod),a=a*a%mod,b>>=1;/*printf("%lld\n",ans);*/return ans;}
//arr rev,loghighbit;
//void NTT(ll*a,ll len,ll f){
////	if(len>400000)fprintf(stderr,"YD");
//	ref(i,0,len)if(i<rev[i])std::swap(a[i],a[rev[i]]);
//	static arr wnk;wnk[0]=1;
//	rfor(ll mid=1;mid<len;mid<<=1){
//		ll wn=pow(~f?3:332748118,s/mid);
//		ref(j,1,mid)wnk[j]=wnk[j-1]*wn%mod;
//		rfor(ll i=0;i<len;i+=(mid<<1)){
//			rfor(ll j=0;j<mid;j++){
//				ll x=a[i|j],y=wnk[j]*a[i|j|mid]%mod;
//				a[i|j]=q(x+y),a[i|j|mid]=q(x-y+mod);
//			}
//		}
//	}
//	if(!~f){ll ni=pow(len,mod-2);ref(i,0,len)a[i]=a[i]*ni%mod;}
//}
std::pair<ll,ll>pr[5000100];
ll vis[5000100],fs[5000100],sd[5000100],a[1145141],c[1145141];
ll cmp(ll x,ll y){
	return a[x]<a[y];
}
int main(void){
//    IO(P1912);
//	ll T=readll();
//	while(T --> 0){
//		ll n=readll();
//	} 
//	ll n=readll();
//	rep(i,1,n)f[a[i]=readll()]++;
//	ll len=1;
//	while(len<n*2)len<<=1;
//	NTT(f,len,1);
//	ref(i,0,len)f[i]=f[i]*f[i];
	ll n=readll();
	rep(i,1,n)a[i]=readll(),a[i][fs[a[i]]?sd:fs]=i,c[i]=i;
	std::sort(c+1,c+n+1,cmp);
	ll p=0;
	rep(i,1,n)if(a[c[i]]==a[c[i-1]]){
		if(++p==3)
		return printf("YES\n%lld %lld %lld %lld\n",c[i],c[i-1],c[i-2],c[i-3]),0;
		
	}else p=0;
//	exit(0);
	ll lst=0;
	rep(i,1,n){
		if(sd[a[i]]){
		if(lst&&a[lst]!=a[i])return printf("YES\n%lld %lld %lld %lld\n",fs[a[lst]],fs[a[i]],sd[a[lst]],sd[a[i]]),0;
		else lst=i;
		}
	}
//	exit(0);
//	std::pair<i,j>lst=make_pair(0,0);
//	rep(i,1,n)if(a[c[i]]==a[c[i]-1]){
//		if(p++){
//			lst=make_pair(c[i],c[i]-1);
//		}
//	}
	rep(i,1,n)rep(j,i+1,n){
		if(vis[a[i]+a[j]]){
			ll x=i,y=j,z=pr[a[i]+a[j]].first,w=pr[a[i]+a[j]].second;
			if(x!=z&&x!=w&&y!=z&&y!=w){
				printf("YES\n%lld %lld %lld %lld\n",x,y,z,w);
				return 0;
			}
		}
		vis[a[i]+a[j]]=1;
		pr[a[i]+a[j]]=std::make_pair(i,j);
	}
	puts("NO");
	//if a+b=a+d
	//b=d
	//
	//n*(n-1)/2 number in [2,5e6]
//	if(n*(n-1)/2>5e6-1){
//		puts("Yes");
//	}
    return 0;
}