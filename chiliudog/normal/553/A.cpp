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
const int maxn=1005;
const int mod=1000000007;
int n,c[maxn];
int fac[2000005];
int facinv[2000005];
inline int powmod(int a,int b){
	int res=1;for(;b;b>>=1){
		if(b&1)res=1ll*res*a%mod;a=1ll*a*a%mod;
	}return res;
}
inline void prprpr(){
	fac[0]=1;
	rep(i,1,2000000)fac[i]=1ll*fac[i-1]*i%mod;
	facinv[2000000]=powmod(fac[2000000],mod-2);
	per(i,1999999,1)facinv[i]=1ll*facinv[i+1]*(i+1)%mod;facinv[0]=1;
}
inline int C(int n,int m){
	return 1ll*fac[n]*facinv[m]%mod*facinv[n-m]%mod;
}
inline int get(int x,int k){
	return C(x+k-1,k);
}
int main(){
    //judge();
    prprpr();
    read(n);rep(i,1,n)read(c[i]);int ans=1,sum=c[1];
    rep(i,2,n){
    	ans=1ll*ans*get(sum+1,c[i]-1)%mod;
    	sum+=c[i];
    }
    cout<<ans;
    return 0;
}