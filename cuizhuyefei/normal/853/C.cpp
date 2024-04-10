#include<bits/stdc++.h>
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 404040, M = N * 30;
int n,q,a[N],rt[N],lc[M],rc[M],val[M],sz;
inline void ins(int &k, int K, int p, int l, int r){
	k=++sz;val[k]=val[K]+1;if(l==r)return;
	int mid=(l+r)>>1;
	if(p<=mid)ins(lc[k],lc[K],p,l,mid),rc[k]=rc[K];
	else ins(rc[k],rc[K],p,mid+1,r),lc[k]=lc[K];
}
inline int query(int k, int K, int l, int r, int L, int R){
	if(r<L||l>R||!k)return 0;if(l<=L&&r>=R)return val[k]-val[K];int mid=(L+R)>>1;
	return query(lc[k],lc[K],l,r,L,mid)+query(rc[k],rc[K],l,r,mid+1,R);
}
ll f(ll x){return 1LL*x*(x-1)/2;}
inline int calc(int x, int y, int l, int r){
	if(x>y||l>r)return 0;return query(rt[y],rt[x-1],l,r,1,n);
}
int main() {
	read(n);read(q);rep(i,1,n)read(a[i]);
	rep(i,1,n)ins(rt[i],rt[i-1],a[i],1,n);
	while(q--){
		int l,d,r,u;read(l);read(d);read(r);read(u);
		ll res=f(n)-f(calc(1,l-1,1,n))-f(calc(r+1,n,1,n))-f(calc(1,n,1,d-1))-f(calc(1,n,u+1,n));
		res+=f(calc(1,l-1,1,d-1))+f(calc(r+1,n,1,d-1))+f(calc(1,l-1,u+1,n))+f(calc(r+1,n,u+1,n));
		printf("%lld\n",res);
	}
	return 0;
}