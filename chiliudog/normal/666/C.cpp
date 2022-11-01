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
int fac[maxn],facinv[maxn];
const int mod=1e9+7;
inline int powmod(int a,int b){
	int res=1;for(;b;b>>=1){
		if(b&1)res=1ll*res*a%mod;a=1ll*a*a%mod;
	}return res;
}
inline void prprpr(){
	fac[0]=1;
	rep(i,1,100000)fac[i]=1ll*fac[i-1]*i%mod;
	rep(i,0,100000)facinv[i]=powmod(fac[i],mod-2);
}
inline int C(int n,int m){
	return 1ll*fac[n]*facinv[m]%mod*facinv[n-m]%mod;
}
inline int Gans(int x,int n,int *a){
	if(n<x)return 0;
	return a[n-x+1]*1ll*powmod(26,n)%mod;
}
inline void calc(int x,int *&a){
	a=(int*)malloc(140005*sizeof(int));
	int inv=powmod(26,mod-2);
	int v1=powmod(inv,x),v2=1;
	rep(i,x,100000){
		a[i-x+1]=1ll*C(i-1,x-1)*v2%mod*v1%mod;
		v1=1ll*v1*inv%mod;v2=1ll*v2*(26-1)%mod;
		a[i-x+1]=(a[i-x+1]+a[i-x])%mod;
	}
}
char s[maxn];
int nowlen;
map<int,int*> zball;
int main(){
	prprpr();
	int m;read(m);scanf("%s",s+1);nowlen=strlen(s+1);calc(nowlen,zball[nowlen]);
	rep(i,1,m){
		int x;read(x);
		if(x==2){
			int v;read(v);printf("%d\n",Gans(nowlen,v,zball[nowlen]));
		}
		else{
			scanf("%s",s+1);nowlen=strlen(s+1);
			if(!zball.count(nowlen))calc(nowlen,zball[nowlen]);
		}
	}
	return 0;
}