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
const int maxn=105;
int head[maxn],t[maxn<<1],ne[maxn<<1];
const int mod=1e9+7;
inline int powmod(int a,int b){
	int res=1;for(;b;b>>=1){
		if(b&1)res=1ll*res*a%mod;a=1ll*a*a%mod;
	}return res;
}
int num,n,sz[maxn],f[maxn][maxn][maxn],g[maxn][maxn],C[maxn][maxn];
inline void prprpr(){
	rep(i,0,100){
		C[i][0]=1;
		rep(j,1,100)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
}
inline void addedge(int x,int y){
	ne[++num]=head[x];head[x]=num;t[num]=y;
	ne[++num]=head[y];head[y]=num;t[num]=x;
}
inline void dp(int x,int fa){
	f[x][0][1]=1;sz[x]=1;
	forE(i,x)if(t[i]!=fa){
		dp(t[i],x);
		memset(g,0,sizeof(g));
		rep(v1,0,sz[x])rep(v2,0,sz[t[i]])rep(v3,0,sz[x])rep(v4,0,sz[t[i]]){
			g[v1+v2][v3]=(g[v1+v2][v3]+1ll*f[x][v1][v3]*f[t[i]][v2][v4]%mod*v4%mod)%mod;
			g[v1+v2+1][v3+v4]=(g[v1+v2+1][v3+v4]+1ll*f[x][v1][v3]*f[t[i]][v2][v4]%mod)%mod;
		}sz[x]+=sz[t[i]];
		rep(v1,0,n)rep(v2,0,n)f[x][v1][v2]=g[v1][v2];
	}
}
int ans[maxn];
int main(){
	prprpr();
	read(n);rep(i,1,n)head[i]=-1;
	rep(i,1,n-1){
		int x,y;read(x);read(y);
		addedge(x,y);
	}
	dp(1,-1);
	// cerr<<f[1][0][3]<<endl;
	rep(i,0,n-2){
		rep(j,0,n)
			ans[i]=(ans[i]+1ll*f[1][i][j]*j%mod*powmod(n,n-i-2))%mod;
	}ans[n-1]=1;
	// cerr<<ans[0]<<endl;
	per(i,n-1,0){
		rep(j,i+1,n-1)ans[i]=(ans[i]-1ll*ans[j]*C[j][i]%mod+mod)%mod;
	}
	rep(i,0,n-1)printf("%d ",ans[i]);
	return 0;
}