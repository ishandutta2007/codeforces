#include<bits/stdc++.h>
using namespace std;
const int N=1<<19|5,MOD=998244353;
inline int mo1(int x){ return x>=MOD?x-MOD:x; }
inline void mo(int& x){ x>=MOD?x-=MOD:0; }
inline int fpow(int x,int n,int ret=1){
	for(;n;n>>=1,x=1ll*x*x%MOD)
		if(n&1) ret=1ll*ret*x%MOD;
	return ret;
}
int inv[N];
struct II{
	II(){
		inv[1]=1;
		for(int i=2;i<N;++i)
			inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
	}
}__ii;
namespace POLY{
	int w[N<<1];
	struct II{
		II(){
			for(int s=1;s<=N;s<<=1){
				w[s]=1; int wn=fpow(3,(MOD-1)/(s+s));
				for(int i=1;i<s;++i) w[s+i]=1ll*w[s+i-1]*wn%MOD;
			}
		}
	}__ii;
	inline void NTT(int a[],int n,int t){
		for(int i=0,pos=0;i<n;++i){
			if(i<pos) swap(a[i],a[pos]);
			for(int p=n>>1;(pos^=p)<p;p>>=1);
		}
		for(int s=1,sx=2;s<n;sx=(s=sx)<<1)
			for(int i=0;i<n;i+=sx)
				for(int j=i;j<i+s;++j){
					int x=a[j],y=1ll*a[j+s]*w[s+j-i]%MOD;
					a[j]=x+y>=MOD?x+y-MOD:x+y;
					a[j+s]=x-y<0?x-y+MOD:x-y;
				}
		if(t==-1){
			reverse(a+1,a+n);
			for(int i=0;i<n;++i) a[i]=1ll*a[i]*inv[n]%MOD;
		}
	}
	inline void mul(int a[],int b[],int n){
		NTT(a,n,1); NTT(b,n,1);
		for(int i=0;i<n;++i) a[i]=1ll*a[i]*b[i]%MOD;
		NTT(a,n,-1);
	}
	inline void mul2(int a[],int b[],int c[],int n){
		static int x[N],y[N];
		for(int i=0;i<n;++i) x[i]=a[i],y[i]=b[i],x[i+n]=y[i+n]=0;
		mul(x,y,n+n);
		for(int i=0;i<n;++i) c[i]=x[i],c[i+n]=0;
	}
	inline void get_inv(int a[],int b[],int n){
		static int g[N]; b[0]=fpow(a[0],MOD-2);
		for(int s=2;s<=n;s<<=1){
			for(int i=s>>1;i<s+s;++i) g[i]=b[i]=0;
			for(int i=0;i<s;++i) g[i]=a[i];
			NTT(g,s+s,1); NTT(b,s+s,1);
			for(int i=0;i<s+s;++i)
				b[i]=(2ll+MOD-1ll*b[i]*g[i]%MOD)*b[i]%MOD;
			NTT(b,s+s,-1);
		}
		for(int i=n;i<n+n;++i) b[i]=0;
	}
}
int a[N],b[N],c[N],f[N],f2[N],g[N],s[N],h[N],v[N];
bool vis[N];
void solve(int a[],int b[],int c[],int l,int r){
	static int x[N],y[N];
	if(r-l<=1) return;
	int m=l+r>>1;
	int top=1; for(;top<r-l;top<<=1);
	for(int i=0;i<top;++i) x[i]=y[i]=0;
	for(int i=0;i<m-l;++i) x[i]=a[i+l];
	for(int i=0;i<r-m;++i) y[i]=b[i+m];
//	for(int i=0;i<top;++i) printf("[%d]",x[i]); puts("");
//	for(int i=0;i<top;++i) printf("[%d]",y[i]); puts("");
	POLY::mul(x,y,top);
//	for(int i=0;i<top;++i) printf("{%d}",x[i]); puts("");
	for(int i=0;i<r-l;++i) mo(c[i+l+m]+=x[i]);
	solve(a,b,c,l,m);
	solve(a,b,c,m,r);
}
int main(){
	int n,m; scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=m;++i){
		int x; scanf("%d",&x);
		vis[x]=1;
	}
	s[0]=1;
	for(int i=1;i<=n+n+n;++i) s[i]=1ll*s[i-1]*(i-n>=0&&vis[i-n]?2:1)%MOD;
	h[n+n+n]=1;
	for(int i=n+n+n-1;i>=0;--i) h[i]=1ll*h[i+1]*(i-n>=0&&vis[i-n]?2:1)%MOD;
	for(int i=0;i<=n+n+n;++i) v[i]=1;
	memset(f,0,sizeof(f));
	solve(s,h,f,0,n+n+n);
//	for(int i=0;i<=n+n+n+n;++i) printf("<%d>",s[i]); puts("");
//	for(int i=0;i<=n+n+n+n;++i) printf("<%d>",h[i]); puts("");
	solve(v,v,g,0,n+n+n);
	int ans=0;
	for(int i=1;i<=n;++i){
//		printf("{%d %d %d}",f[i+i+n+n],g[i+i+n+n],f2[i+i+n+n]);
		int cnt=(f[i+i+n+n]+MOD-g[i+i+n+n])%MOD;
//		printf("<%d>",cnt);
		mo(ans+=1ll*cnt*a[i]%MOD);
	}
	ans=1ll*ans*fpow(fpow(2,m)-1,MOD-2)%MOD;
	printf("%d\n",ans);
	return 0;
}