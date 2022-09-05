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
const int N = 666666;
int n,m;ll f[N];
int a[N],b[N],la,lb;
struct Ans{
	int u,v;ll w;
}s[N];int sz;
int main() {
	read(n);read(m);
	while(m--){
		int u,v,w;read(u);read(v);read(w);
		f[u]+=w;f[v]-=w;
	}
	rep(i,1,n)if(f[i]>0)a[++la]=i;
	rep(i,1,n)if(f[i]<0)b[++lb]=i;
	while(la){
		ll tmp=min(f[a[la]],-f[b[lb]]);
		s[++sz]=(Ans){a[la],b[lb],tmp};
		f[a[la]]-=tmp;f[b[lb]]+=tmp;
		if(!f[a[la]])la--;if(!f[b[lb]])lb--;
	}
	printf("%d\n",sz);
	rep(i,1,sz)printf("%d %d %lld\n",s[i].u,s[i].v,s[i].w);
	return 0;
}