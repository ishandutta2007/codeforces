#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353,N=1<<19|5;
inline void mo(int& x){x>=MOD?x-=MOD:0;}
inline int mo1(int x){ return x>=MOD?x-MOD:x; }
inline int fpow(int x,int n,int ret=1){
	for(;n;n>>=1,x=1ll*x*x%MOD)
		if(n&1) ret=1ll*ret*x%MOD;
	return ret;
}
int inv[N];
namespace POLY{
	vector<int> w[23];
	struct II{
		II(){
			inv[1]=1;
			for(int i=2;i<N;++i) inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
			for(int l=1;l<=19;++l){
				w[l].resize(1<<l-1); w[l][0]=1;
				int wn=fpow(3,MOD-1>>l);
				for(int i=1;i<w[l].size();++i)
					w[l][i]=1ll*w[l][i-1]*wn%MOD;
			}
		}
	}__ii;
	inline void NTT(int a[],int n,int t){
		for(int i=0,pos=0;i<n;++i){
			if(i<pos) swap(a[i],a[pos]);
			for(int p=n>>1;(pos^=p)<p;p>>=1);
		}
		for(int s=1,sx=2,p=1;s<n;sx=(s=sx)<<1,++p)
			for(int i=0;i<n;i+=sx)
				for(int j=i;j<i+s;++j){
					int x=a[j],y=1ll*a[j+s]*w[p][j-i]%MOD;
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
		memset(x+n,0,sizeof(int)*n);
		memset(y+n,0,sizeof(int)*n);
		memcpy(x,a,sizeof(int)*n);
		memcpy(y,b,sizeof(int)*n);
		mul(x,y,n+n);
		memset(c+n,0,sizeof(int)*n);
		memcpy(c,x,sizeof(int)*n);
	}
	inline void get_inv(int a[],int b[],int n){
		static int g[N];
		b[0]=fpow(a[0],MOD-2);
		for(int s=2;s<=n;s<<=1){
			for(int i=s>>1;i<s+s;++i) g[i]=b[i]=0;
			for(int i=0;i<s;++i) g[i]=a[i];
			NTT(b,s+s,1); NTT(g,s+s,1);
			for(int i=0;i<s+s;++i)
				b[i]=(2ll+MOD-1ll*g[i]*b[i]%MOD)*b[i]%MOD;
			NTT(b,s+s,-1);
		}
		for(int i=n;i<n+n;++i) b[i]=0;
	}
	inline void sqrt(int a[],int b[],int n){
		static int g[N],x[N];
		b[0]=1;
		for(int s=2;s<=n;s<<=1){
			for(int i=s>>1;i<s+s;++i) b[i]=0;
			get_inv(b,g,s);
			mul2(g,a,g,s);
			for(int i=0;i<s;++i)
				b[i]=1ll*(b[i]+g[i])*(MOD+1>>1)%MOD;
		}
		for(int i=n;i<n+n;++i) b[i]=0;
	}
}
int g[N],a[N],b[N];
int main(){
	int n,m; scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		int x; scanf("%d",&x);
		g[x]=1;
	}
	int top=1; for(;top<=m+m;top<<=1);
	for(int i=0;i<top;++i) a[i]=(int(i==0)+MOD-4ll*g[i]%MOD)%MOD;
	POLY::sqrt(a,b,top);
	for(int i=0;i<top;++i) b[i]=mo1(int(i==0)+MOD-b[i]);
	int k=0; while(g[k]==0&&b[k]==0) ++k;
	for(int i=0;i<top;++i){
		if(i+k>=top) g[i]=0;
		else g[i]=g[i+k];
	}
	for(int i=0;i<top;++i){
		if(i+k>=top) b[i]=0;
		else b[i]=b[i+k];
	}
	POLY::get_inv(g,a,top);
	for(int i=0;i<top;++i) a[i]=1ll*a[i]*(MOD+1>>1)%MOD;
	POLY::mul2(a,b,a,top);
	for(int i=1;i<=m;++i) printf("%d\n",a[i]);
	return 0;
}