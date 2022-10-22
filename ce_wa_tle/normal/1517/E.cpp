#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=414514,inf=0x3f3f3f3f3f3f3f3f;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;char c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}
int readchar(){char c=getchar();for(;c<'A'||c>'z';c=getchar());return c;}
ll s_[N],*s=s_+4,f[N];
struct bit{
	#define lowbit(x)((x)&-(x))
	ll n,s;aN f;void set(ll n_){memset(f,s=0,sizeof(ll)*((n=n_)+1));}
	void add(ll u,ll c){s+=c;while(u<=n)f[u]+=c,u+=lowbit(u);}
	ll query(ll u){u--;ll ans=0;while(u)ans+=f[u],u-=lowbit(u);return s-ans;}
}ds[2];
struct pr{ll x,y;operator ll()const{return-y;}
void print()const{printf("%lld %lld\n",x,y);};}ps[N],pf[N];
ll a[N];
int main(){
	//IO(E);
	ll T=readll();
	while(T --> 0){
		ll n=readll();
		//p?c+(pc)*p+c?
		//cccpcpcpcpppp
		//[ ][    ][  ]
		//i=3,j=10
		//i<=j,i^j%2=1
		//s[j-1]+s[i-1]<f[i+1]+f[j+1]
		//s[i-1]-f[i+1](-2*a[1](i>1))<f[j+1]-s[j-1]-(2*a[n](j<n))
		//pppppccccc
		ds[0].set(n),ds[1].set(n);rep(i,1,n)a[i]=readll();
		s[-1]=s[0]=0;rep(i,1,n)s[i]=a[i]+s[i-2];
		f[n+1]=f[n+2]=0;per(i,n,1)f[i]=a[i]+f[i+2];
		ll ans=0;rep(i,0,n)if(s[i]+s[i-1]>f[i+1]+f[i+2])ans++;//,
//		printf("i=%lld\n",i);
//		else printf("%lld %lld %lld\n",i,s[i]+s[i-1],f[i+1]+f[i+2]);//p*c*
		ll cnts=0,cntf=0,nf=0;
		rep(i,1,n){
			ps[++cnts]=(pr){i,s[i-1]-f[i+1]};
			if(i!=1)ps[++cnts]=(pr){i,s[i-1]-f[i+1]-2*a[1]};
			pf[++cntf]=(pr){i,f[i+1]-s[i-1]};
			if(i!=n)pf[++cntf]=(pr){i,f[i+1]-s[i-1]-2*a[n]};
		}
//		printf("ans=%lld\n",ans%998244353ll);
		std::sort(ps+1,ps+cnts+1),std::sort(pf+1,pf+cntf+1);
//		puts("s=");rep(i,1,cnts)ps[i].print();
//		puts("f=");rep(i,1,cntf)pf[i].print();
		rep(ns,1,cnts){
			while(nf<cntf&&pf[nf+1]<ps[ns])++nf,ds[pf[nf].x&1].add(pf[nf].x,1);
			ans+=ds[(ps[ns].x&1)^1].query(ps[ns].x);
//			printf("ns=%lld %lld %lld\n",ns,ans,ds[(ps[ns].x&1)^1].s);
		}
		printf("%lld\n",ans%998244353ll);
	}
	return 0;
}