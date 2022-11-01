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
	freopen("christmas.in","r",stdin);
	freopen("christmas.out","w",stdout);
}
/*******************************head*******************************/
const int maxn=5005;
int f[maxn][maxn],l[1000005],fac[1000005],p,n,m;
int tfac[10000005];
inline void prprpr(){
	fac[m]=m;
	per(i,m-1,1)fac[i]=1ll*fac[i+1]*i%p;
	tfac[1]=1;
	rep(i,2,m)tfac[i]=1ll*tfac[i-1]*i%p;
}
int dp[2][maxn];
int main(){
    read(n);read(m);read(p);
    rep(i,1,n)read(l[i]);
    f[1][1]=1;
    rep(i,1,4999)rep(j,1,4999)if(f[i][j]){
    	f[i+1][j]=(f[i+1][j]+1ll*f[i][j]*(j-1))%p;
    	f[i+1][j+1]=(f[i+1][j+1]+f[i][j])%p;
    }prprpr();
    rep(i,1,min(m,l[1]))dp[1][i]=1ll*f[l[1]][i]*fac[m-i+1]%p;
    int ans=0,st=0,ed=1;
    if(n==1)
    	rep(i,1,l[1])ans=(ans+dp[1][i])%p;
    rep(i,2,n){
    	int sum=0;
    	rep(j,1,l[i-1])sum=(sum+dp[ed][j])%p;
    	rep(j,1,min(m,l[i])){
    		dp[st][j]=1ll*sum*f[l[i]][j]%p*fac[m-j+1]%p;
    		dp[st][j]-=1ll*dp[ed][j]*f[l[i]][j]%p*tfac[j]%p;
    		if(dp[st][j]<0)dp[st][j]+=p; 
    	}
    	rep(j,1,l[i-1])dp[ed][j]=0;
    	if(i==n)rep(j,1,l[i])ans=(ans+dp[st][j])%p;
    	st^=1;ed^=1;
    }cout<<ans;
    return 0;
}