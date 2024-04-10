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
const int N = 433333,M=28000000;
int n,m,k,fa[N],A[N],B[N];Vi e[N];
ll lzy[M],val[M],add[M];int ch[M][2],rt[N],tot;
inline void upd(int x){
	val[x]=max(val[ch[x][0]],val[ch[x][1]]);
}
inline void pushzhi(int x, ll c){
	add[x]=0;val[x]=lzy[x]=c;
}
inline void pushadd(int x, ll c){
	if(lzy[x])lzy[x]+=c;else add[x]+=c;
	val[x]+=c;
}
inline void pushdown(int x){
	if(lzy[x]){
		if(!ch[x][0])ch[x][0]=++tot;
		if(!ch[x][1])ch[x][1]=++tot;
		pushzhi(ch[x][0],lzy[x]);pushzhi(ch[x][1],lzy[x]);
		lzy[x]=0;
	}
	if(add[x]){
		if(!ch[x][0])ch[x][0]=++tot;
		if(!ch[x][1])ch[x][1]=++tot;
		pushadd(ch[x][0],add[x]);pushadd(ch[x][1],add[x]);
		add[x]=0;
	}
}
int merge(int x, int y){
	if(!x||!y)return x+y;
	if(!ch[x][0]&&!ch[x][1])swap(x,y);
	if(!ch[y][0]&&!ch[y][1]){
		assert(add[y]+lzy[y]==val[y]);pushadd(x,val[y]);
		return x;
	}
	pushdown(x);pushdown(y);
	ch[x][0]=merge(ch[x][0],ch[y][0]);
	ch[x][1]=merge(ch[x][1],ch[y][1]);
	upd(x);return x;
}
ll query(int k, int p, int l, int r){
	if(!k||l==r)return val[k];
	int mid=(l+r)>>1;pushdown(k);
	if(p<=mid)return query(ch[k][0],p,l,mid);
	return query(ch[k][1],p,mid+1,r);
}
int query(int k, int p, ll x, int l, int r){
	if(l>=p&&val[k]<=x)return r;//!k --> val[k]=0
	if(l==r)return 0;
	int mid=(l+r)>>1;pushdown(k);
	if(p>mid)return query(ch[k][1],p,x,mid+1,r);
	if(val[ch[k][0]]>x)return query(ch[k][0],p,x,l,mid);
	return max(mid,query(ch[k][1],p,x,mid+1,r));
}
void modify(int &k, int l, int r, ll x, int L, int R){
	if(!k)k=++tot;
	if(l==L&&r==R){pushzhi(k,x);return;}
	int mid=(L+R)>>1;pushdown(k);
	if(r<=mid)modify(ch[k][0],l,r,x,L,mid);
	else if(l>mid)modify(ch[k][1],l,r,x,mid+1,R);
	else{
		modify(ch[k][0],l,mid,x,L,mid);
		modify(ch[k][1],mid+1,r,x,mid+1,R);
	}
	upd(k);
}
void dfs(int u){
	rep(i,0,SZ(e[u])-1)dfs(e[u][i]),rt[u]=merge(rt[u],rt[e[u][i]]);
	if(A[u]){
		ll val=query(rt[u],A[u],1,k)+B[u];
		int r=query(rt[u],A[u],val,1,k);assert(A[u]<=r&&r<=k);
		modify(rt[u],A[u],r,val,1,k);
	}
//	cerr<<u<<' '<<tot<<endl;
//	cerr<<u<<':';rep(i,1,k)cerr<<query(rt[u],i,1,k)<<' ';cerr<<endl;
}
int main() {
	read(n);read(m);read(k);
	rep(i,2,n)read(fa[i]),e[fa[i]].pb(i);
	rep(i,1,m){
		int u,d,w;read(u);read(d);read(w);
		A[u]=d;B[u]=w;
	}
	dfs(1);cout<<query(rt[1],k,1,k)<<endl;
	cerr<<tot<<endl;
	return 0;
}