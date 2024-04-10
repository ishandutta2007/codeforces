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
const int N = 102000,mo=1e9+7;
int n,a[N],tot,f[N],inv[N],qz[N];
int power(int a, int n){
	int res=1;
	while(n){
		if(n&1)res=1LL*res*a%mo;a=1LL*a*a%mo;n>>=1;
	}
	return res;
}
void init(int lim, int n){//f[1..lim]
//	inv[1]=1;rep(i,2,lim)inv[i]=1LL*(mo-mo/i)*inv[mo%i]%mo;
	rep(i,1,lim)qz[i]=(qz[i-1]+power(n-i,mo-2))%mo;
	rep(x,1,lim)f[x]=((1LL*(n-1)*(n-x)%mo*qz[x]-1LL*(n-1)*x%mo*power(n,mo-2))%mo+mo)%mo;
}
int main() {
	read(n);int mx=0;if(n==1){puts("0");return 0;}
	rep(i,1,n)read(a[i]),tot+=a[i],umax(mx,a[i]);
	init(min(N-2,mx),tot);
	int res=0;rep(i,1,n)res=(res+f[a[i]])%mo;
	cout<<res;
	return 0;
}