#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
//const ld PI=acosl(-1),EPS=1e-10;
template<class T> inline void chmin(T& x,T y){ y<x?x=y:0; }
template<class T> inline void chmax(T& x,T y){ y>x?x=y:0; }
/*
const int N=5+1e5,MOD=998244353;
inline int fpow(int x,int n,int ret=1,int mod=MOD){
	for(;n;n>>=1,x=1ll*x*x%mod)
		n&1?ret=1ll*ret*x%mod:0;
	return ret;
}
inline void mo(int& x){ x>=MOD?x-=MOD:0; }
inline int mo1(int x){ return x>=MOD?x-MOD:x; }
int inv[N],fac[N],ifac[N];
struct IniterFacInv{
	IniterFacInv(){
		fac[0]=ifac[0]=inv[1]=1;
		for(int i=1;i<N;++i){
			fac[i]=1ll*fac[i-1]*i%MOD;
			if(i>1) inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
			ifac[i]=1ll*ifac[i-1]*inv[i]%MOD;
		}
	}
}__initer_comb;
inline int comb(int n,int m){
	if(n<0||m<0||n<m) return 0;
	return 1ll*fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;
}
inline int rcomb(int n,int m){
	if(n<0||m<0||n<m) return 0;
	return 1ll*ifac[n]*fac[m]%MOD*fac[n-m]%MOD;
}
*/
const int N=5+1e5;
ll lg(ll x){ 
	if(x==1) return 0;
	return lg(x>>1)+1;
}
void opera(ll& x,ll y){
	ll z=0,t=0;
	for(int i=0;i<30;++i){
		int bx=(x>>i)&1,by=(y>>i)&1;
		if((bx^t)==by) continue;
		if(~(x>>(i+1))&1) z|=1<<i;
		if(bx+t>=2) t=1;
		else t=0;
	}
	x+=z;
}
void print(ll x){
	if(x>=2) print(x/2);
	printf("%lld",x%2);
}
bool solve(ll x,ll y){
	if(x>y) return false;
//	print(x); putchar(' ');
//	print(y); putchar(' ');
	int flag=0;
	for(int i=29;i>=0;--i){
		if(flag==0&&((x>>i)&1)&&((y>>i)&1)) continue;
		if((x>>i)&1) flag=max(flag-1,0);
		if(((y>>i)&1)) flag++;
	}
	return flag==0;
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	int q; scanf("%d",&q);
	while(q--){
		ll x,y; scanf("%lld%lld",&x,&y);
//		printf("%x %x\n",int(x),int(y));
//		for(int i=0;i<10;++i) printf("%0x",(x>>i)&1); 
		
		/*
		while(x<=y){
			ll t=0,z=0;
			for(int i=0;i<30;++i){
				int bx=(x>>i)&1,by=(y>>i)&1;
				if((bx^t)!=by){
					if(bx){
						z|=1<<i;
						++t;
					}
				}
				if((bx+t)>1) t=1;
				else t=0;
			}
			x+=z;
//			printf("(%lld %lld)\n",x,y);
			if((x&y)==x) break;
		}
		if(x!=y) puts("NO");
		else puts("YES");
		*/
		if(!solve(x,y)) puts("NO");
		else puts("YES");
	}
	return 0;
}