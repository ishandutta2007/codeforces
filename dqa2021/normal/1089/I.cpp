#include<bits/stdc++.h>
#define pb push_back
using namespace std;
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
typedef pair<int,int> P;
int mod;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)

const int n=400;
int fac[410],f[410],g[410],h[410][410];
void prework(){
	fac[0]=1; rep(i,1,n+3) fac[i]=1LL*fac[i-1]*i%mod;
	
	rep(i,1,n){
		g[i]=fac[i];
		rep(j,1,i-1) iadd(g[i],1LL*g[j]*fac[i-j]%mod);
	}
	
	h[0][0]=1;
	rep(i,1,n){
		rep(j,1,i){
			rep(k,1,i){
				add(h[i][j],1LL*h[i-k][j-1]*fac[k]%mod);
			}
		}
	}
	
	f[1]=1,f[2]=2,f[3]=0;
	rep(i,4,n){
		f[i]=fac[i];
		rep(j,1,i-1) iadd(f[i],2LL*g[j]*fac[i-j]%mod);
		rep(j,4,i-1) iadd(f[i],1LL*h[i][j]*f[j]%mod);
	}
}
void solve(){
	printf("%d\n",f[read()]);
}
int main()
{
	int T=read(); mod=read();
	prework();
	for (;T--;) solve();
	return 0;
}