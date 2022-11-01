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
const int maxn=200005;
const int mod=1e9+7;
int n,fac[maxn],facinv[maxn];
inline int powmod(int a,int b){
	int res=1;for(;b;b>>=1){
		if(b&1)res=1ll*res*a%mod;a=1ll*a*a%mod;
	}return res;
}
inline void prprpr(){
	fac[0]=1;
	rep(i,1,n)fac[i]=1ll*fac[i-1]*i%mod;
	facinv[n]=powmod(fac[n],mod-2);
	per(i,n-1,0)facinv[i]=1ll*facinv[i+1]*(i+1)%mod;
}
inline int C(int n,int m){
	return 1ll*fac[n]*facinv[m]%mod*facinv[n-m]%mod;
}
int op[maxn];
int ne[maxn];
inline void gen1(int n){
	rep(i,1,n)op[i]=C((n/2-1),(i+1)/2-1);
	if(n%4==0){
		rep(i,1,n)if(i%2==0)op[i]=mod-op[i];
	}
}
inline void gen2(int n){
	int rev=1;ne[1]=1;
	rep(i,2,n){
		if(rev){
			ne[i]=(op[i-1]+op[i])%mod;
		}else{
			ne[i]=(op[i]-op[i-1]+mod)%mod;
		}rev^=1;
	}
}
int main(){
    read(n);prprpr();
    gen1(n/2*2);
    if(n&1){
    	gen2(n);
    	rep(i,1,n)op[i]=ne[i];
    }int res=0;
    rep(i,1,n){
    	int x;read(x);
    	res=(res+1ll*x*op[i])%mod;
    }cout<<res<<endl;
}