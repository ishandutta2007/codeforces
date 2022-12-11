#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long long ll;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define fi first
#define se second

const int mod=998244353;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}

//typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)

const int X=1<<18|100;

int fac[X],ifac[X],inv[X];
void global_init(int x){
	inv[1]=1; rep(i,2,x) inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
	fac[0]=ifac[0]=1;
	rep(i,1,x){
		fac[i]=1LL*fac[i-1]*i%mod;
		ifac[i]=1LL*ifac[i-1]*inv[i]%mod;
	}
}

namespace NTT{

int MXW,imaxw[30];
vector<int> Wn[32];
void prepare(int x){
	for (int i=0;i<=25;i++) imaxw[i]=qpow(2,mod-1-i);
	for (MXW=1;MXW<=x;MXW<<=1);
	rep(i,1,26){
		if ((1<<i)>MXW) break;
		vector<int> &C=Wn[i];
		C.resize((1<<i)+1);
		C[0]=1; const int v=qpow(3,mod-1>>i);
		rep(j,1,1<<i) C[j]=1LL*C[j-1]*v%mod;
	}
}
int maxw,btw,id[X],I;
void init(int x,bool tp=1){
	for (maxw=1,btw=0;maxw<=x;maxw<<=1,btw++); I=imaxw[btw];
	if (tp) for (int i=1,s=btw-1;i<maxw;i++) id[i]=(id[i>>1]>>1)|((i&1)<<s);
}
void ntt(int *w,int tp){
	for (int i=0;i<maxw;i++) if (i<id[i]) swap(w[i],w[id[i]]);
	for (int md=1,len=2,b=1;md<maxw;md=len,len<<=1,++b){
		const vector<int> &C=Wn[b];
		for (int l=0;l<maxw;l+=len)
			for (int u=0,x,y;u<md;++u){
				x=w[u+l],y=1LL*w[u+l+md]*C[~tp?u:len-u]%mod;
				w[u+l]=upd(x+y-mod);
				w[u+l+md]=upd(x-y);
			}
	}
}

void getinv(int n,int *f,int *g){
	if (!n) return g[0]=qpow(f[0],mod-2),void();  //caution
	getinv(n>>1,f,g); init(n<<1);
	static int h[X];
	rep(i,0,n) h[i]=f[i]; rep(i,n+1,maxw-1) h[i]=0;
	ntt(g,1); ntt(h,1); rep(i,0,maxw-1) g[i]=(2-1LL*g[i]*h[i])%mod*g[i]%mod,g[i]=upd(g[i]); ntt(g,-1);
	rep(i,0,n) g[i]=1LL*g[i]*I%mod; rep(i,n+1,maxw-1) g[i]=0;
}

void getln(int n,int *f,int *g){
	if (!n) return;
	getinv(n-1,f,g);
	static int h[X];
	init(n-1<<1);
	rep(i,0,n-1) h[i]=1LL*f[i+1]*(i+1)%mod; rep(i,n,maxw-1) h[i]=0;
	ntt(g,1); ntt(h,1); rep(i,0,maxw-1) g[i]=1LL*g[i]*h[i]%mod; ntt(g,-1);
	per(i,1,n) g[i]=1LL*g[i-1]*I%mod*inv[i]%mod; g[0]=0; rep(i,n+1,maxw-1) g[i]=0;
}

void getexp(int l,int r,int *f,int *g){
	if (l==r){
		if (!l) g[0]=1;
		else g[l]=1LL*g[l]*inv[l]%mod;
		return;
	}
	int mid=l+r>>1;
	getexp(l,mid,f,g);
	static int A[X],B[X];
	init(r-l);
	rep(i,l,mid) A[i-l]=g[i]; rep(i,mid-l+1,maxw-1) A[i]=0;
	rep(i,0,r-l) B[i]=f[i]; rep(i,r-l+1,maxw-1) B[i]=0;
	ntt(A,1); ntt(B,1); rep(i,0,maxw-1) A[i]=1LL*A[i]*B[i]%mod; ntt(A,-1);
	rep(i,mid+1,r) add(g[i],1LL*A[i-l]*I%mod);
	getexp(mid+1,r,f,g);
}

}
using namespace NTT;

int n,m;

int F[X],G[X];

void solve(){
	n=read(),m=read();
	prepare(m+3<<1); init(m+3<<1);
	global_init(m+5);
	rep(i,0,m) F[i]=1LL*(i&1?mod-1:1)*ifac[i]%mod;
	rep(i,0,m) G[i]=1LL*ifac[i]*qpow(i,m)%mod;
	ntt(F,1); ntt(G,1); rep(i,0,maxw-1) F[i]=1LL*F[i]*G[i]%mod; ntt(F,-1);
	rep(i,0,m) F[i]=1LL*F[i]*I%mod;
	//rep(i,0,m) printf("S %d = %d\n",i,F[i]);
	
	int z=0;
	for (int j=0,s=1;j<=m&&j<=n;s=1LL*s*(n-j)%mod,++j){
		add(z,1LL*F[j]*s%mod*qpow(n+1,n-j)%mod);
	}
	printf("%d\n",z);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}