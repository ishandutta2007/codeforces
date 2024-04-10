#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef pair<int,int> pin;
#define mk(a,b) make_pair(a,b)
#define lowbit(x) ((x)&(-(x)))
#define sqr(a) ((a)*(a))
#define clr(a) (memset((a),0,sizeof(a)))
#define ls ((x)<<1)
#define rs (((x)<<1)|1)
#define mid (((l)+(r))>>1)
#define pb push_back
#define w1 first
#define w2 second
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
/*******************************head*******************************/
const int maxn=100005,mod=1e9+7;
typedef long double ld;
const ld pi=acos(-1.0);
int k,fac[maxn],facinv[maxn],pw2[maxn];
inline int C(int n,int m){
	if(m<0)return 0;
	if(n<m)return 0;
	return 1ll*fac[n]*facinv[m]%mod*facinv[n-m]%mod;
}
struct sim{
	ld r,i;
	inline sim(){}
	inline sim(ld _r,ld _i){r=_r;i=_i;}
	friend inline sim operator + (const sim &a,const sim &b){
		return sim(a.r+b.r,a.i+b.i);
	}
	friend inline sim operator - (const sim &a,const sim &b){
		return sim(a.r-b.r,a.i-b.i);
	}
	friend inline sim operator * (const sim &a,const sim &b){
		return sim(a.r*b.r-a.i*b.i,a.i*b.r+a.r*b.i);
	}
};
inline int powmod(int a,int b,int mod){
	int res=1;for(;b;b>>=1){
		if(b&1)res=1ll*res*a%mod;a=1ll*a*a%mod;
	}return res;
}
namespace poly{
	int rev[maxn],len,lim;
	inline void init(int n,int m){
		len=1;while(n+m>=len)len<<=1,lim++;
		rep(i,0,len-1)rev[i]=(rev[i>>1]>>1)|((i&1)<<(lim-1));
	}
	inline void fft(sim a[],int on){
		rep(i,0,len-1)if(i<rev[i])swap(a[i],a[rev[i]]);
		for(int h=2;h<=len;h<<=1){
			sim wn=sim(cos(2*pi*on/h),sin(2*pi*on/h));
			for(int j=0;j<len;j+=h){
				sim w=sim(1,0);
				rep(k,0,h/2-1){
					sim u=a[j+k],t=(a[j+k+h/2]*w);
					a[j+k]=u+t;a[j+k+h/2]=u-t;w=w*wn;
				}
			}
		}
	}
	sim a1[maxn],a2[maxn],b1[maxn],b2[maxn],c1[maxn],c2[maxn],c3[maxn];
	const int bl=1<<15;
	inline void mul(int x[],int y[],int z[],int n,int mod){
		rep(i,0,n)a1[i]=sim(x[i]/bl,0),a2[i]=sim(x[i]%bl,0),b1[i]=sim(y[i]/bl,0),b2[i]=sim(y[i]%bl,0);
		rep(i,n+1,len)a1[i]=a2[i]=b1[i]=b2[i]=sim(0,0);
		fft(a1,1);fft(a2,1);fft(b1,1);fft(b2,1);
		rep(i,0,len-1)c1[i]=a1[i]*b1[i],c2[i]=a2[i]*b2[i],c3[i]=a1[i]*b2[i]+a2[i]*b1[i];
		fft(c1,-1);fft(c2,-1);fft(c3,-1);
		rep(i,0,n){
			int v1=(i64)floor(c1[i].r/len+0.5)%mod,v2=(i64)floor(c2[i].r/len+0.5)%mod,v3=((i64)(((i64)floor(c3[i].r/len+0.5))%mod)+mod)%mod;
			z[i]=(1ll*(1ll*v1*bl%mod+v3)*bl%mod+v2)%mod;
		}
	}
}
inline void prprpr(){
	fac[0]=1;
	rep(i,1,30000)fac[i]=1ll*fac[i-1]*i%mod;
	rep(i,0,30000)facinv[i]=powmod(fac[i],mod-2,mod);
	pw2[0]=1;
	rep(i,1,30000)pw2[i]=(pw2[i-1]<<1)%mod;
}
inline void merge(int dp[],int dp1[],int dp2[],int left,int right){
	static int a[maxn],b[maxn],c[maxn];
	rep(i,0,k)a[i]=1ll*dp1[i]*facinv[i]%mod*powmod(pw2[i],right,mod)%mod;
	rep(i,0,k)b[i]=1ll*dp2[i]*facinv[i]%mod;
	poly::mul(a,b,c,k,mod);
	rep(i,0,k)dp[i]=1ll*c[i]*fac[i]%mod;
}
int res[maxn],f[maxn];
int tres,tf;
i64 n;
int main(){
//	judge();
	prprpr();
	cin>>n;read(k);poly::init(k,k);
	if(n>k){
		puts("0");
		return 0;
	}
	tres=1;tf=0;
	rep(i,1,k)res[i]=1;
	f[0]=1;
	for(;n;n>>=1){
		if(n&1)merge(f,f,res,tf,tres),tf+=tres;
		merge(res,res,res,tres,tres);tres+=tres;
//		rep(i,0,k)printf("%d ",res[i]);puts("");
	}
	int ans=0;
//	rep(i,0,k)printf("%d ",f[i]);
	rep(i,0,k)ans=(ans+1ll*f[i]*C(k,i))%mod;
	cout<<ans<<endl;
	return 0;
}