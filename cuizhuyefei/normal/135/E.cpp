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
const int N=1222222,mo=1e9+7;
int k,w,fac[N],ifac[N];
int power(int a, int n){
	int res=1;
	while(n){
		if(n&1)res=1LL*res*a%mo;a=1LL*a*a%mo;n>>=1;
	}
	return res;
}
inline int A(int n, int m){return m>=0&&m<=n?1LL*fac[n]*ifac[n-m]%mo:0;}
void init(int n){
	fac[0]=1;rep(i,1,n)fac[i]=1LL*fac[i-1]*i%mo;
	ifac[n]=power(fac[n],mo-2);per(i,n-1,0)ifac[i]=1LL*ifac[i+1]*(i+1)%mo;
}
int solve(int w){
	int res=k!=1?1LL*k*(1-power(k,w-1))%mo*power(1-k,mo-2)%mo:w-1;res=(res+mo)%mo;
//	printf("%d:%d\n",w,res);
	for(int n=w;n<2*w&&n-w<=k;n++)res=(res+1LL*power(A(k,n-w),2)*power(k,2*w-n))%mo;
//	printf("%d:%d\n",w,res);
	for(int n=2*w;n<=w+k;n++)res=(res+1LL*A(k,n-2*w)*power(A(k-(n-2*w),w),2))%mo;
//	printf("%d:%d\n",w,res);
	return res;
}
int main() {
	init(N-1);read(k);read(w);
	cout<<(solve(w)-solve(w-1)+mo)%mo;
	return 0;
}