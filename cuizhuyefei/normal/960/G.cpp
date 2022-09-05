#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 466666, mo = 998244353;
int n,ans[N],fac[N],ifac[N];
inline int power(int a, int n) {
	int res=1;
	while (n) {
		if (n&1) res=1LL*res*a%mo;
		a=1LL*a*a%mo;
		n>>=1;
	}
	return res;
}
inline int inv(int a) {return power(a,mo-2);}

int a[N],b[N],w[N];
inline void fft(int *a, int n, int tp) {
	for (int i=1,j=0; i<n; i++) {
		for (int k=n>>1; !((j^=k)&k); k>>=1);
		if (i<j) swap(a[i],a[j]);
	}
	for (int j=2; j<=n; j<<=1) {
		w[0]=1; w[1]=power(3,(mo-1)/j); if (tp==-1) w[1]=inv(w[1]);
		rep(i,2,j>>1) w[i]=1LL*w[1]*w[i-1]%mo;
		for (int k=0; k<n; k+=j) rep(i,0,(j>>1)-1) {
			int x=a[i+k],y=1LL*w[i]*a[i+k+(j>>1)]%mo;
			a[i+k]=x+y<mo?x+y:x+y-mo;
			a[i+k+(j>>1)]=x-y>=0?x-y:x-y+mo;
		}
	}
}
inline void mul(int *_a, int *_b, int m, int *c) {
	int n=1; for (;n<=m+m;n<<=1);
	rep(i,0,n-1) a[i]=i<m?_a[i]:0;
	rep(i,0,n-1) b[i]=i<m?_b[i]:0;
	fft(a,n,1); fft(b,n,1);
	rep(i,0,n-1) a[i]=1LL*a[i]*b[i]%mo;
	fft(a,n,-1); int Inv=inv(n);
	rep(i,0,n-1) c[i]=1LL*a[i]*Inv%mo;
}

int B[N],C[N],A[N];
inline void solve(int n) {
	if (n==1) {ans[1]=1; return;}
	if (n&1) {
		solve(n-1);
		per(i,n,0) ans[i]=(ans[i-1]+1LL*ans[i]*(n-1))%mo;
		return;
	}
	solve(n>>1);
	rep(i,0,n) B[i]=1LL*fac[i]*ans[i]%mo;
	C[0]=1; rep(i,1,n) C[i]=1LL*C[i-1]*(n>>1)%mo*inv(i)%mo;
	reverse(C,C+n+1);
	mul(B,C,n+1,A); rep(i,0,n) A[i]=1LL*A[i+n]*ifac[i]%mo;
	mul(ans,A,n+1,ans);
}

int main() { //freopen("1.in","r",stdin);
	read(n); int a,b;read(a);read(b);
	if(!a||!b) {puts("0"); return 0;}
	fac[0]=1; rep(i,1,n) fac[i]=1LL*fac[i-1]*i%mo;
	ifac[n]=inv(fac[n]); per(i,n-1,0) ifac[i]=1LL*ifac[i+1]*(i+1)%mo;
	if (n-1==0) {printf("%d",a+b-2==0); return 0;}
	solve(n-1);
	printf("%lld",1LL*ans[a+b-2]*fac[a+b-2]%mo*ifac[a-1]%mo*ifac[b-1]%mo);
	return 0;
}