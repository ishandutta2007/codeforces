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
const int N = 202000, M = 400000*20;
int n,q;char s[N];
int ch[N][26],fa[N],Max[N],cnt=1,lst=1;Vi e[N];
int lc[M],rc[M],tot,val[M],rt[N],sz;
void modify(int &k, int p, int l, int r){
	if(!k)k=++tot;val[k]++;if(l==r)return;
	int mid=(l+r)>>1;
	if(p<=mid)modify(lc[k],p,l,mid);else modify(rc[k],p,mid+1,r);
}
int merge(int x, int y){
	if(!x||!y)return x+y;
	int o=++tot;lc[o]=merge(lc[x],lc[y]);rc[o]=merge(rc[x],rc[y]);
	val[o]=val[lc[o]]+val[rc[o]];return o;
}
int query(int k, int l, int r, int L, int R){
	if(!k||l==L&&r==R)return val[k];
	int mid=(L+R)>>1;
	if(r<=mid)return query(lc[k],l,r,L,mid);
	if(l>mid)return query(rc[k],l,r,mid+1,R);
	return query(lc[k],l,mid,L,mid)||query(rc[k],mid+1,r,mid+1,R);
}
void ins(int c, int t){
	int p=lst,np=++cnt;lst=np;Max[np]=Max[p]+1;
	for(;p&&!ch[p][c];p=fa[p])ch[p][c]=np;
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
	modify(rt[np],t,1,n);
}
void dfs(int u){
	rep(i,0,SZ(e[u])-1)dfs(e[u][i]),rt[u]=merge(rt[u],rt[e[u][i]]);
}
void solve(int l, int r, int n){//s[1..n]
	static int a[N];a[0]=1;
	rep(i,1,n)a[i]=!a[i-1]?0:ch[a[i-1]][s[i]-'a'];
//	rep(i,1,n)printf("<%d>",a[i]);puts("");
	per(i,n,0)if(a[i])rep(j,(i+1<=n?s[i+1]-'a'+1:0),25){
		int u=ch[a[i]][j];//1..i (i+1)
		if(u&&l+i<=r&&query(rt[u],l+i,r,1,sz)){
			rep(p,1,i)printf("%c",s[p]);printf("%c",'a'+j);puts("");
			return;
		}
	}
	puts("-1");
}
int main() {
	scanf("%s",s+1);n=strlen(s+1);sz=n;
	rep(i,1,n)ins(s[i]-'a',i);
	rep(i,2,cnt)e[fa[i]].pb(i);dfs(1);
	/*rep(i,1,cnt){
		printf("%d:%d %d %d\n",i,Max[i],fa[i],query(rt[i],1,n,1,n));
		rep(j,0,25)if(ch[i][j])printf("ch[%d][%c]=%d\n",i,'a'+j,ch[i][j]);
	}*/
	rep(i,0,25)assert(!ch[0][i]);
	read(q);
	while(q--){
		int l,r;read(l);read(r);scanf("%s",s+1);
		int len=strlen(s+1);solve(l,r,len);
		
	}
	return 0;
}