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
const int N = 404000,M=15000000;
char s[N];int n,fa[N],Max[N],ch[N][26],lst=1,cnt=1;
int rt[N],lc[M],rc[M],val[M],tot,f[N],res,dot[N];Vi e[N];
void ins(int &k, int p, int l, int r){
	if(!k)k=++tot;val[k]++;if(l==r)return;
	int mid=(l+r)>>1;if(p<=mid)ins(lc[k],p,l,mid);else ins(rc[k],p,mid+1,r);
}
int merge(int x, int y){
	if(!x||!y)return x+y;int o=++tot;
	lc[o]=merge(lc[x],lc[y]);rc[o]=merge(rc[x],rc[y]);
	val[o]=val[lc[o]]+val[rc[o]];return o;
}
bool query(int k, int l, int r, int L, int R){
	if(!k||l==L&&r==R)return val[k];
	int mid=(L+R)>>1;
	if(r<=mid)return query(lc[k],l,r,L,mid);
	if(l>mid)return query(rc[k],l,r,mid+1,R);
	return query(lc[k],l,mid,L,mid)||query(rc[k],mid+1,r,mid+1,R);
}
void ins(int c, int pos){
	int p=lst,np=++cnt;lst=np;Max[np]=Max[p]+1;
	for(;!ch[p][c];p=fa[p])ch[p][c]=np;
	if(!p)fa[np]=1;
	else{
		int q=ch[p][c];
		if(Max[q]==Max[p]+1)fa[np]=q;
		else{
			int nq=++cnt;Max[nq]=Max[p]+1;
			memcpy(ch[nq],ch[q],104);
			fa[nq]=fa[q];fa[q]=fa[np]=nq;
			for(;ch[p][c]==q;p=fa[p])ch[p][c]=nq;
		}
	}
	ins(rt[np],pos,1,n);dot[np]=pos;//dot[]:max right
}
void dfs1(int u){
	rep(i,0,SZ(e[u])-1){
		dfs1(e[u][i]);rt[u]=merge(rt[u],rt[e[u][i]]);
		umax(dot[u],dot[e[u][i]]);
	}
}
inline bool ck(int x, int y, int p){//[p-Max[y]+1,p]
	int l=p-Max[y]+Max[x],r=p-1;
	if(l<=r)return query(rt[x],l,r,1,n);return 0;
}
int sta[N],top;//sta[1..top]
void dfs(int u){
	int l=2,r=top,pos=0;
	while(l<=r){
		int mid=(l+r)>>1;
	//	if(u==3)cerr<<sta[mid]<<' '<<u<<' '<<dot[u]<<endl;
		if(ck(sta[mid],u,dot[u]))pos=mid,l=mid+1;else r=mid-1;
	}
	if(u>1){
		f[u]=f[sta[pos]]+1;umax(res,f[u]);
	}
//	if(u==3)cerr<<ck(2,3,dot[3])<<' '<<pos<<endl;
//	printf("[%d,%d]:%d\n",dot[u]-Max[u]+1,dot[u],f[u]);
	rep(i,0,SZ(e[u])-1){
		sta[++top]=u;dfs(e[u][i]);top--;
	}
}
int main() {
	read(n);scanf("%s",s+1);
	rep(i,1,n)ins(s[i]-'a',i);
//	rep(i,1,cnt)printf("%d:%d %d\n",i,fa[i],Max[i]);
	rep(i,2,cnt)e[fa[i]].pb(i);
	dfs1(1);dfs(1);cout<<res;
	return 0;
}