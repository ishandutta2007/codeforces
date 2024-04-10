#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 404000, M = 10000000;
int n,f[N],rt[N],size[N];Vi dot[N];
int lc[M],rc[M],val[M],sz;
void build(int &k,int l,int r,int p){
	k=++sz;val[k]++;if(l==r)return;int mid=(l+r)>>1;
	if(p<=mid)build(lc[k],l,mid,p);else build(rc[k],mid+1,r,p);
}
inline int query(int k, int l, int r, int L, int R){
	if(!k)return L;if(val[k]==R-L+1)return 0;
	if(L==R)return L;int mid=(L+R)>>1;
	if(r<=mid)return query(lc[k],l,r,L,mid);
	if(l>mid)return query(rc[k],l,r,mid+1,R);
	int x=query(lc[k],l,mid,L,mid);if(x)return x;
	return query(rc[k],mid+1,r,mid+1,R);
}
inline int Merge(int x, int y){
	if(!x||!y)return x+y;
	lc[x]=Merge(lc[x],lc[y]);rc[x]=Merge(rc[x],rc[y]);
	val[x]=val[lc[x]]+val[rc[x]];return x;
}
inline int merge(int x, int y){
	x=f[x];y=f[y];if(x==y)return x;if(size[x]>size[y])swap(x,y);//
	per(i,SZ(dot[x])-1,0)dot[y].pb(dot[x][i]),f[dot[x][i]]=y;dot[x].clear();
	size[x]=0;size[y]=SZ(dot[y]);
	rt[y]=Merge(rt[x],rt[y]);return y;
}
int main() {//freopen("1.in","r",stdin);
	read(n);rep(i,1,n)f[i]=i,size[i]=1,dot[i].pb(i),build(rt[i],1,n,i);
	int q;read(q);
	while(q--){
		int op,x,y;read(op);read(x);read(y);
		if(op==1)merge(x,y);
		if(op==2){
			int u=f[x],v;
			while(v=query(rt[u],x,y,1,n))u=merge(u,v);
		}
		if(op==3)printf("%s\n",f[x]==f[y]?"YES":"NO");
	}
	return 0;
}