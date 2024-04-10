#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353,N=1<<17|5;
int inv[N],fac[N],ifac[N],bitcount[N];
inline int fpow(int x,int n,int ret=1){
	for(;n;n>>=1,x=1ll*x*x%MOD)
		n&1?ret=1ll*ret*x%MOD:0;
	return ret;
}
struct Initer{
	Initer(){
		fac[0]=ifac[0]=inv[1]=1; bitcount[0]=0;
		for(int i=1;i<N;++i){
			fac[i]=1ll*fac[i-1]*i%MOD;
			if(i>1) inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
			ifac[i]=1ll*ifac[i-1]*inv[i]%MOD;
			bitcount[i]=bitcount[i-(i&-i)]+1;
//			assert(1ll*ifac[i]*fac[i]%MOD==1);
		}
	}
}__initer;
inline void mo(int& x){x>=MOD?x-=MOD:0;}
inline int mo1(int x){ return x>=MOD?x-MOD:x; }
struct Poly{
	vector<int> a;
	Poly(){ a.resize(17); }
	size_t size(){ return a.size(); }
	int& operator[](const size_t& x){ return a[x]; }
	Poly operator+(Poly b){
		Poly c;
		for(int i=0;i<a.size();++i)
			mo(c[i]=a[i]+b[i]);
		return c;
	}
	Poly operator-(Poly b){
		Poly c;
		for(int i=0;i<a.size();++i)
			mo(c[i]=a[i]+MOD-b[i]);
		return c;
	}
	Poly operator*(Poly b){
		Poly c;
		for(int i=0;i<a.size();++i)
			for(int j=0;i+j<c.size();++j)
				c[i+j]=(c[i+j]+1ll*a[i]*b[j])%MOD;
		return c;
	}
	Poly operator*(int t){
		Poly b;
		for(int i=0;i<a.size();++i)
			b[i]=1ll*a[i]*t%MOD;
		return b;
	}
	Poly exp(){
		Poly b; b[0]=1;
		for(int n=0;n+1<a.size();++n){
			for(int i=0;i<=n;++i)
				mo(b[n+1]+=1ll*b[i]*a[n-i+1]%MOD*(n-i+1)%MOD);
			b[n+1]=1ll*b[n+1]*inv[n+1]%MOD;
		}
		return b;
	}
	Poly ln(){
		Poly b; b[0]=0;
		for(int n=0;n+1<b.size();++n){
			b[n+1]=1ll*(n+1)*a[n+1]%MOD;
			for(int i=1;i<=n;++i)
				mo(b[n+1]+=MOD-1ll*a[i]*b[n-i+1]%MOD*(n-i+1)%MOD);
			b[n+1]=1ll*b[n+1]*inv[n+1]%MOD;
		}
		return b;
	}
};
ostream& operator<<(ostream& s,Poly x){
	s<<"[";
	for(int i=0;i<x.size();++i) 
		s<<x[i]<<" ";
	s<<"]";
	return s;
}
Poly f[N],g[N];
int ans[N];
void FWT(Poly a[],int n,int t){
	for(int s=1,sx=2;s<n;sx=(s=sx)<<1){
		for(int i=0;i<n;i+=sx)
			for(int j=i;j<i+s;++j){
				Poly x=a[j],y=a[j+s];
				a[j]=x+y;
				a[j+s]=x-y;
			}
	}
	if(t==-1)
		for(int i=0;i<n;++i) a[i]=a[i]*inv[n];
}
int h[N];
int tag[N];
map<int,int> mp;
int main(){
	int all=0,n,k,c;
	scanf("%d%d%d",&n,&k,&c);	
	for(int i=0;i<n;++i){
		int x,k=0; scanf("%d",&x);
		k+=x&15;
		x-=x&15;
		k+=x&-x;
		x-=x&-x;
		all^=x;
		mp[k]++;
	}
	for(int sta=0;sta<1<<k;++sta){
		Poly c; c[0]=1;
		for(int i=1;i<=k;++i){
			c[i]=ifac[i];
			if((sta>>i-1)&1)
				mo(c[i]=MOD-c[i]);
		}
		f[sta]=c.ln();
	}
	for(auto t:mp){
		memset(h,0,sizeof(int)*(1<<c));
		for(int j=0;j<=k;++j)
			for(int i=0;i<1<<c;++i)
				h[i]|=(bitcount[(t.first-j)&i]&1)<<j;
		for(int i=0;i<1<<c;++i){
			if(h[i]&1){
				for(int j=0;j<=k;++j)
					h[i]^=1<<j;
				tag[i]^=t.second&1;
			}
			g[i]=g[i]+f[h[i]>>1]*t.second;
		}
	}
	for(int i=0;i<1<<c;++i){
		g[i]=g[i].exp();
		if(tag[i]&1){
			for(int j=0;j<g[i].size();++j)
				g[i][j]=mo1(MOD-g[i][j]);
		}
	}
	FWT(g,1<<c,-1);
	for(int i=0;i<1<<c;++i)
		ans[i^all]=g[i][k];
	int key=1ll*fpow(n,MOD-1-k)*fac[k]%MOD;
	for(int i=0;i<1<<c;++i){
		ans[i]=1ll*ans[i]*key%MOD;
		printf("%d ",ans[i]);
	}
	return 0;
}