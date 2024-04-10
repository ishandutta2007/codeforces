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
const int N = 500500;
int n,k,m,q,A[N],B[N],C[N],D[N],nxt[N],col[N],top;
pair<int*,int>sta[9000200];
vector<Pii> mrk[N<<2];
struct DSU{
	int fa[N],val[N],sz[N];
	void ini(){
		rep(i,1,n)fa[i]=i,sz[i]=1;
	}
	inline int find(int x){
		while(fa[x]!=x)x=fa[x];return x;
	}
	inline int qry(int x){
		int y=0;while(fa[x]!=x)y^=val[x],x=fa[x];return y;
	}
	void merge(int u, int v){
	//	cerr<<"merge "<<u<<' '<<v<<endl;
		int x=qry(u)^qry(v);
		u=find(u);v=find(v);if(u==v)return;
		if(sz[u]>sz[v])swap(u,v);
		sta[++top]=make_pair(fa+u,fa[u]);
		sta[++top]=make_pair(sz+v,sz[v]);
		sta[++top]=make_pair(val+u,val[u]);
		fa[u]=v;sz[v]+=sz[u];val[u]=1^x;
	}
	bool ck(int u, int v){
		int x=qry(u)^qry(v);u=find(u);v=find(v);
	//	cerr<<"ck "<<(u==v)<<endl;
		return (u!=v||x==1);
	}
}f[52];
void recycle(int lst){
	while(top>lst)*sta[top].fi=sta[top].se,top--;
}
void insert(int k, int l, int r, Pii x, int L, int R){
	if(l==L&&r==R){mrk[k].pb(x);return;}
	int mid=(L+R)>>1;
	if(r<=mid)insert(k<<1,l,r,x,L,mid);
	else if(l>mid)insert(k<<1|1,l,r,x,mid+1,R);
	else insert(k<<1,l,mid,x,L,mid),insert(k<<1|1,mid+1,r,x,mid+1,R);
}
void solve(int k,int l,int r){
	int lst=top;
	rep(i,0,SZ(mrk[k])-1)f[mrk[k][i].fi].merge(A[mrk[k][i].se],B[mrk[k][i].se]);
	if(l==r){
		int c;
		if(f[D[l]].ck(A[C[l]],B[C[l]]))puts("YES"),c=D[l];
		else puts("NO"),c=col[C[l]];
		col[C[l]]=c;if(l+1<=nxt[l]&&c)insert(1,l+1,nxt[l],Pii(c,C[l]),1,q);
		recycle(lst);return;
	}
	int mid=(l+r)>>1;solve(k<<1,l,mid);
	solve(k<<1|1,mid+1,r);recycle(lst);
}
int main() {
	read(n);read(m);read(k);read(q);
	rep(i,1,k)f[i].ini();
	rep(i,1,m)read(A[i]),read(B[i]);
	static int buc[N];rep(i,1,m)buc[i]=q;
	rep(i,1,q)read(C[i]),read(D[i]),nxt[i]=q;
	per(i,q,1)nxt[i]=buc[C[i]],buc[C[i]]=i;
	solve(1,1,q);
	return 0;
}