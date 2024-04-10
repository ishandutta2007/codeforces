#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7,N=1<<21|5;
inline int mo1(int x){ return x>=MOD?x-MOD:x; }
inline void mo(int& x){x>=MOD?x-=MOD:0;}
inline int fpow(int x,int n,int ret=1){
	for(;n;n>>=1,x=1ll*x*x%MOD)
		if(n&1) ret=1ll*ret*x%MOD;
	return ret;
}
int inv[N],fac[N],ifac[N];
inline int comb(int n,int m){
	if(n<m||n<0||m<0) return 0;
	return 1ll*fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;
}
struct II{
	II(){
		inv[1]=fac[0]=ifac[0]=1;
		for(int i=1;i<N;++i){
			fac[i]=1ll*fac[i-1]*i%MOD;
			if(i>1) inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
			ifac[i]=1ll*ifac[i-1]*inv[i]%MOD;
		}
	}
}__ii;
namespace POLY{
	int w[N<<1];
	struct II{
		II(){
			for(int s=1;s<N;s<<=1){
				w[s]=1; int wn=fpow(3,(MOD-1)/(s<<1));
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
	inline void mul2(int a[],int b[],int c[],int n,int t=1){
		static int x[N],y[N];
		for(int i=0;i<n;++i) x[i]=a[i],y[i]=b[~t?i:n-1-i],x[i+n]=y[i+n]=0;
		mul(x,y,n+n);
		for(int i=0;i<n;++i) c[i]=x[~t?i:n-1+i];
	}
}
int mex(vector<int> a){
	unordered_map<int,int> mp;
	for(auto x:a) mp[x]=1;
	for(int i=0;;++i)
		if(!mp[i]) return i;
}
int f[N][2];
int main(){
	int n,ans=0; scanf("%d",&n);
/*	f[0][1]=0;
	for(int n=1;n<=10;++n){
		vector<int> g0,g1;
		for(int i=2;i<n;++i)
			g0.push_back(f[i-1][0]^f[n-i][0]);
		for(int i=1;i<=n;++i)
			g0.push_back(f[i-1][1]^f[n-i][1]);
		for(int i=2;i<=n;++i)
			g1.push_back(f[i-1][0]^f[n-i][1]);
		f[n][0]=mex(g0);
		f[n][1]=mex(g1);
	}
	for(int n=1;n<=10;++n) printf("(%d %d)",f[n][0],f[n][1]);
*/
	for(int i=n/4;i<=n/2;++i){
		ans=(ans+2ll*(comb(i+i-1,n-i-i)+2ll*comb(i+i-1,n-i-i-1))%MOD*fac[i+i])%MOD;
	}
	printf("%d\n",ans);
	return 0;
}