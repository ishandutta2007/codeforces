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

const int mod=1e9+7;
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
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define all(x) (x).begin(),(x).end()
#define forall(x,y) for (const int &y: e[x])
int fac[200100],ifac[200100],inv[200100];
void init(int x){
	inv[1]=1; rep(i,2,x) inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
	fac[0]=ifac[0]=1;
	rep(i,1,x){
		fac[i]=1LL*fac[i-1]*i%mod;
		ifac[i]=1LL*ifac[i-1]*inv[i]%mod;
	}
}
int C(int n,int m){return 0<=m&&m<=n?1LL*fac[n]*ifac[n-m]%mod*ifac[m]%mod:0LL;}
int iC(int n,int m){return 0<=m&&m<=n?1LL*ifac[n]*fac[n-m]%mod*fac[m]%mod:0LL;}

int n,k;
void solve(){
	n=read(),k=read();
	int z=1;
	rep(i,1,n){
		if (n-1LL*(i-1)*(k-1)<0) break;
		add(z,1LL*iC(n,i)*C(n-(i-1)*(k-1),i)%mod);
//		printf("test %d / %d\n",C(n-i*(k-1),i),C(n,i));
	}
	printf("%d\n",z);
}

int main()
{
	init(2e5+10);
	for (int T=read();T--;) solve();
	return 0;
}