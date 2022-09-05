#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1505,mo=1e9+7;
inline void add(int &x, int y){x=x+y<mo?x+y:x+y-mo;}
inline int power(int a, int n) {
	int res=1;
	while (n) {
		if (n&1) res=1LL*res*a%mo;
		a=1LL*a*a%mo; n>>=1;
	}
	return res;
}
int fac[166666],ifac[166666];
void iniC(int n){
	fac[0]=1;rep(i,1,n)fac[i]=1LL*fac[i-1]*i%mo;
	ifac[n]=power(fac[n],mo-2);
	per(i,n-1,0)ifac[i]=1LL*ifac[i+1]*(i+1)%mo;
}
inline int C(int n, int m){return m>=0&&m<=n?1LL*fac[n]*ifac[m]%mo*ifac[n-m]%mo:0;}
int n,m,c[N],g[2][N],qz[2][N],qzc[N];
int main() {
	read(n);read(m);
	int A,B;read(A);read(B);int p=1LL*A*power(B,mo-2)%mo;
	int k;read(k);iniC(k);
	rep(i,0,min(m-1,k))c[i]=1LL*C(k,i)*power(p,i)%mo*power(1-p+mo,k-i)%mo;
	qzc[0]=c[0];rep(i,1,m)qzc[i]=(qzc[i-1]+c[i])%mo;
	g[0][0]=1;rep(i,0,m-1)qz[0][i]=1;
	rep(t,1,n){
		int p=t&1,q=p^1;//q-->p
		rep(j,0,m-1)g[p][m-j-1]=1LL*c[j]*(qz[q][m-1]-qz[q][m-j-1]+mo)%mo;
		per(j,m-1,1)add(g[p][j-1],g[p][j]);
		rep(i,0,m-1)g[p][i]=(1LL*qz[q][m-i-1]*qzc[m-i-1]-g[p][i]+mo)%mo*c[i]%mo;
	//	rep(i,0,m-1)cerr<<g[p][i]<<' ';cerr<<endl;
		qz[p][0]=g[p][0];
		rep(i,1,m-1)qz[p][i]=(qz[p][i-1]+g[p][i])%mo;
	}
	cout<<qz[n&1][m-1];
	return 0;
}