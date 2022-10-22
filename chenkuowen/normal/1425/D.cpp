#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7,N=5+2e3;
inline int fpow(int x,int n,int ret=1){
	for(;n;n>>=1,x=1ll*x*x%MOD)
		n&1?ret=1ll*ret*x%MOD:0;
	return ret;
}
inline void mo(int& x){x>=MOD?x-=MOD:0;}
inline int mo1(int x){ return x>=MOD?x-MOD:x; }
int fac[N],inv[N],ifac[N];
struct Initer{
	Initer(){
		fac[0]=ifac[0]=inv[1]=1;
		for(int i=1;i<N;++i){
			fac[i]=1ll*fac[i-1]*i%MOD;
			if(i>1) inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
			ifac[i]=1ll*ifac[i-1]*inv[i]%MOD;
		}
	}
}__initer;
inline int comb(int n,int m){
	if(n<0||m<0||n<m) return 0;
	return 1ll*fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;
}
struct C{ int x,y,b; }a[N];
int s[1005][1005];
inline int calc(int x1,int y1,int x2,int y2){
	if(x1>x2||y1>y2) return 0;
	if(x1<1) x1=1;
	if(y1<1) y1=1;
	if(x2>1000) x2=1000;
	if(y2>1000) y2=1000; 
	return mo1(mo1(s[x2][y2]+s[x1-1][y1-1])+MOD
		-mo1(s[x2][y1-1]+s[x1-1][y2]));
}
int main(){
	int n,m,r; scanf("%d%d%d",&n,&m,&r);
	for(int i=1;i<=n;++i){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].b);
		s[a[i].x][a[i].y]++;
	}
	for(int i=1;i<=1000;++i)
		for(int j=1;j<=1000;++j)
			s[i][j]=mo1(mo1(s[i][j]+MOD-s[i-1][j-1])
				+mo1(s[i-1][j]+s[i][j-1]));
	int ans=0;
	for(int i=1;i<=n;++i){
//		int c=calc(a[i].x-r,a[i].y-r,a[i].x+r,a[i].y+r);
//		ans+=1ll*(comb(n,m)+MOD-comb(n-c,m))*a[i].b%MOD*a[i].b%MOD;
		for(int j=1;j<=n;++j){
			int c0=calc(a[i].x-r,a[i].y-r,a[i].x+r,a[i].y+r);
			int c1=calc(a[j].x-r,a[j].y-r,a[j].x+r,a[j].y+r);
			int c2=calc(max(a[i].x-r,a[j].x-r),max(a[i].y-r,a[j].y-r)
				,min(a[i].x+r,a[j].x+r),min(a[i].y+r,a[j].y+r));
			c0-=c2; 
			c1-=c2;
			int k=(0ll+comb(n,m)+MOD-comb(n-c2-c0,m)+MOD-comb(n-c2-c1,m)+comb(n-c2-c1-c0,m))%MOD;
			ans=(ans+1ll*a[i].b*a[j].b%MOD*k)%MOD;
		}
	}
	printf("%d\n",ans);
	return 0;
}