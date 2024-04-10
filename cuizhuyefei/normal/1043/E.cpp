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
const int N = 303000;
int n,m,x[N],y[N],id[N];
ll qz[N],hz[N],ans[N];
bool cmp(int a, int b){return x[a]-y[a]<x[b]-y[b];}
int main() {
	read(n);read(m);
	rep(i,1,n)read(x[i]),read(y[i]),id[i]=i;
	sort(id+1,id+n+1,cmp);
	rep(i,1,n)qz[i]=qz[i-1]+x[id[i]];
	per(i,n,1)hz[i]=hz[i+1]+y[id[i]];
	rep(i,1,n){//ans[id[i]]
		ans[id[i]]=qz[i-1]+1LL*y[id[i]]*(i-1)+hz[i+1]+1LL*x[id[i]]*(n-i);
	}
	while(m--){
		int a,b;read(a);read(b);
		ans[a]-=min(x[a]+y[b],y[a]+x[b]);
		ans[b]-=min(x[a]+y[b],y[a]+x[b]);
	}
	rep(i,1,n)printf("%lld ",ans[i]);
	return 0;
}