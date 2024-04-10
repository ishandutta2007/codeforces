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
const int N = 1003000,mx=1e6;
int n,m,a[N],b[N],val[N<<2],lzy[N<<2];
inline void pushdown(int k, int l, int r){
	if(lzy[k]){
		int mid=(l+r)>>1;
		val[k<<1]+=lzy[k];val[k<<1|1]+=lzy[k];
		lzy[k<<1]+=lzy[k];lzy[k<<1|1]+=lzy[k];
		lzy[k]=0;
	}
}
void modify(int k, int l, int r, int v, int L, int R){
	if(l==L&&r==R){val[k]+=v;lzy[k]+=v;return;}
	pushdown(k,L,R);
	int mid=(L+R)>>1;
	if(r<=mid)modify(k<<1,l,r,v,L,mid);
	else if(l>mid)modify(k<<1|1,l,r,v,mid+1,R);
	else modify(k<<1,l,mid,v,L,mid),modify(k<<1|1,mid+1,r,v,mid+1,R);
	val[k]=max(val[k<<1],val[k<<1|1]);
}
int query(int k, int l, int r){
	if(l==r)return val[k]>0?l:-1;
	pushdown(k,l,r);int mid=(l+r)>>1;
	if(val[k<<1|1]>0)return query(k<<1|1,mid+1,r);
	return query(k<<1,l,mid);
}
int main() {
	read(n);read(m);
	rep(i,1,n)read(a[i]),modify(1,1,a[i],1,1,mx);
	rep(i,1,m)read(b[i]),modify(1,1,b[i],-1,1,mx);
	int q;read(q);
	while(q--){
		int op,i,x;read(op);read(i);read(x);
		if(op==1)modify(1,1,a[i],-1,1,mx),a[i]=x,modify(1,1,a[i],1,1,mx);
		else modify(1,1,b[i],1,1,mx),b[i]=x,modify(1,1,b[i],-1,1,mx);
		printf("%d\n",query(1,1,mx));
	}
	return 0;
}