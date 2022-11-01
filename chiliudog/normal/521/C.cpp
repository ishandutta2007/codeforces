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
const int maxn=100005;
const int mod=1e9+7;
int sum[maxn],pw[maxn],fac[maxn],n,k;
int facinv[maxn];
inline int powmod(int a,int b){
	int res=1;for(;b;b>>=1){
		if(b&1)res=1ll*res*a%mod;a=1ll*a*a%mod;
	}return res;
}
inline int C(int n,int m){
	if(n<0)return 0;
	if(m<0)return 0;
	if(n<m)return 0;
	return 1ll*fac[n]*facinv[m]%mod*facinv[n-m]%mod;
}
inline void prprpr(){
	fac[0]=1;
	rep(i,1,100000)fac[i]=1ll*fac[i-1]*i%mod;
	facinv[100000]=powmod(fac[100000],mod-2);
	per(i,99999,0)facinv[i]=1ll*facinv[i+1]*(i+1)%mod;
	pw[0]=1;
	rep(i,1,100000)pw[i]=10ll*pw[i-1]%mod;
	sum[0]=C(n-2,k-1);
	rep(i,1,n){
		sum[i]=(sum[i-1]+1ll*pw[i]*C(n-2-i,k-1)%mod)%mod;
	}
}
char s[maxn];
int main(){
  //  judge();
    read(n);read(k);scanf("%s",s+1);i64 ans=0;prprpr();
    if(k==0){
    	int ans=0;
    	rep(i,1,n){
    		ans=10ll*ans%mod;
    		ans+=s[i]-'0';
    	}cout<<ans;
    	return 0;
    }
    rep(i,1,n){
    	if(i!=n)ans=(ans+1ll*(s[i]-'0')*sum[n-i-1])%mod;
    	if(i!=1)ans=(ans+1ll*(s[i]-'0')*pw[n-i]%mod*C(i-1,k)%mod)%mod;
    }cout<<ans;
    return 0;
}