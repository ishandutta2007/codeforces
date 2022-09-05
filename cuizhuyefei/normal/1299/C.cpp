#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,ll> Pil;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=613;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1e6+11;
int n,a[N];Pil sta[N];int top;ll qz[N];
double ans[N];
ll Cross(Pil a, Pil b){return 1ll*a.fi*b.se-1ll*a.se*b.fi;}
Pil operator-(Pil a, Pil b){return Pil(a.fi-b.fi,a.se-b.se);}
int main() {
	read(n);rep(i,1,n)read(a[i]),qz[i]=qz[i-1]+a[i];
	sta[++top]=Pil(0,0);
	rep(i,1,n){
		while(top>1&&Cross(Pil(i,qz[i])-sta[top-1],sta[top]-sta[top-1])>=0)top--;
		sta[++top]=Pil(i,qz[i]);
	}
	rep(i,1,top-1)rep(j,sta[i].fi+1,sta[i+1].fi)ans[j]=1.0*(qz[sta[i+1].fi]-qz[sta[i].fi])/(sta[i+1].fi-sta[i].fi);
	rep(i,1,n)printf("%.11lf\n",ans[i]);
	return 0;
}