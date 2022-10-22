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
//std::pair<ll,ll>pr[5000100];
//ll vis[5000100],fs[5000100],sd[5000100],a[1145141],c[1145141];
//ll cmp(ll x,ll y){
//	return a[x]<a[y];
//}
ll n,m,k,t;
ll a[1555555],b[1555555],c[1555555];
ll exgcd(ll a,ll b,ll&x,ll&y){
    ll t1;return b?t1=exgcd(b,a%b,y,x),y-=a/b*x,t1:(x=1,y=0,a);
}
ll div_down(ll a,ll b){
	return a<0?(a-(a%b+b)%b)/b:a/b;
}
ll div_up(ll a,ll b){
	return div_down(a-1,b)+1;
}
ll ansk[1555555],da[1555555];
ll check(ll mid){
//	ll up=2*max(n,m);
	ll ans=0;
	ll kk,lls,g=exgcd(n,m,kk,lls),cs=m/g;
	rep(s,1,t){
		ll i=c[s];
		ll c=a[i],d=b[i];
		if(c&&d){
//			printf("%lldk+%lld=%lldl+%lld<%lld\n",n,c,m,d,mid);
			//kn+c=lm+d
			//kn+c<=mid
			//kn-lm=d-c
//			ax+by=0
//			a'x+b'y=0
//			x=b'
			if(!~ansk[i]){
				ll k=kk;//,l=lls;
				ll t=d-c;
				if(t%g)continue;
				ll df=t/g;
				k=(k*df)%cs;
				ansk[i]=k;
				da[i]=div_up(div_up(1-c,n)-ansk[i],cs);
			}
			//rlk=k+d*cs
			//1<=kn+c<=mid
			//1<=(k+d*cs)*n+c<=mid
			//((1-c)/n-k)/cs<=d<=((mid-c)/n-k)/cs
//			printf("k=%lldd+%lld\n",cs,k);
//			printf("%lld %lld\n",div_down(div_down(mid-c,n)-k,cs),div_up(div_up(1-c,n)-k,cs));
			ans+=div_down(div_down(mid-c,n)-ansk[i],cs)-da[i]+1;
//			if(mid-ans< ::k)return 0;
//	printf("%lld\n",ans);
		}
	}
//	dprintf("%lld\n",ans);
	return mid-ans>=::k;
}
int main(void){
//    IO(P1912);
//	ll T=readll();
//	while(T --> 0){
//		ll n=readll();
//	} 
memset(ansk,-1,sizeof ansk);
//IO(B);
//64*500000
//=30000000
	n=readll(),m=readll(),k=readll(),t=0;
	rep(i,1,n)a[c[++t]=readll()]=i;
	rep(i,1,m)b[c[++t]=readll()]=i;
	std::sort(c+1,c+t+1);
	ll tt=t;t=0;
	rep(i,2,tt){
		if(c[i]==c[i-1])c[++t]=c[i];
	}
//	dprintf("%lld\n",t);
//	printf("%lld\n",check(4));//,exit(0);
	ll l=1,r=1e18;
	while(l<=r){
//		dprintf("%lld %lld\n",l,r);
		ll mid=(l+r)>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",r+1);
    return 0;
}