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
const int N = 502000,M=8008800;
int lc[M],rc[M],val[M],pos[M],tot;char s[N];
int n,m,q,cnt=1,lst=1,ch[155000][26],Max[N],fa[N],rt[N],jmp[150000][18];
int A[N],B[N],C[N],D[N];Pii ans[N];
vector<int>que[N];Vi e[N];
inline void upd(int k){
	val[k]=max(val[lc[k]],val[rc[k]]);
	pos[k]=val[lc[k]]==val[k]?pos[lc[k]]:pos[rc[k]];
}
void ins(int &k, int p, int l, int r){//assert(p>=l&&p<=r);
	if(!k)k=++tot,pos[k]=l;if(l==r){val[k]++;return;}
	int mid=(l+r)>>1;
	if(p<=mid)ins(lc[k],p,l,mid);else ins(rc[k],p,mid+1,r);
	upd(k);
}
int merge(int x, int y, int l, int r){
	if(!x||!y)return x+y;int o=++tot,mid=(l+r)>>1;
	if(l==r){val[o]=val[x]+val[y];pos[o]=l;return o;}
	lc[o]=merge(lc[x],lc[y],l,mid);rc[o]=merge(rc[x],rc[y],mid+1,r);
	upd(o);return o;
}
inline Pii merge_Pii(Pii a, Pii b){
	if(a.se>b.se||a.se==b.se&&a.fi<b.fi)return a;return b;
}
Pii qry(int k, int l, int r, int L, int R){
	if(l==L&&r==R)return Pii(pos[k],val[k]);
	int mid=(L+R)>>1;
	if(r<=mid)return qry(lc[k],l,r,L,mid);
	if(l>mid)return qry(rc[k],l,r,mid+1,R);
	return merge_Pii(qry(lc[k],l,mid,L,mid),qry(rc[k],mid+1,r,mid+1,R));
}
void ins(int c, int id){
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
	ins(rt[np],id,1,m);//cerr<<"cur="<<np<<' '<<id<<endl;
}
void dfs1(int u){
	rep(i,0,SZ(e[u])-1)
		dfs1(e[u][i]),rt[u]=merge(rt[u],rt[e[u][i]],1,m);//,cerr<<u<<' '<<e[u][i]<<endl;
}
int jump_tree(int x, int len){
	per(i,17,0)if(len<=Max[fa[jmp[x][i]]])x=jmp[x][i];
	if(len<=Max[x]&&len>Max[fa[x]])return x;
	x=fa[x];assert(len<=Max[x]&&len>Max[fa[x]]);
	return x;
}
int main() {
	scanf("%s",s+1);n=strlen(s+1);
	read(m);rep(i,1,m){
		static char t[N];scanf("%s",t+1);int len=strlen(t+1);
		lst=1;rep(j,1,len)ins(t[j]-'a',i);
	}
	/*rep(i,1,cnt){
		cerr<<i<<' '<<fa[i]<<' '<<Max[i]<<endl;
		rep(j,0,25)if(ch[i][j])printf("ch[%d][%c]=%d\n",i,'a'+j,ch[i][j]);
	}
	cerr<<cnt<<endl;*/
	rep(i,1,cnt)e[fa[i]].pb(i);dfs1(1);
	rep(i,1,cnt)jmp[i][0]=fa[i];
	rep(j,1,17)rep(i,1,cnt)jmp[i][j]=jmp[jmp[i][j-1]][j-1];
	read(q);
	rep(i,1,q)read(A[i]),read(B[i]),read(C[i]),read(D[i]),que[D[i]].pb(i);
	for(int i=1,x=1,cur=0;i<=n;i++){
		while(x>1&&!ch[x][s[i]-'a'])x=fa[x],cur=Max[x];
		if(ch[x][s[i]-'a'])x=ch[x][s[i]-'a'],cur++;
	//	cerr<<i<<' '<<x<<' '<<cur<<endl;
		rep(j,0,SZ(que[i])-1){
			int idx=que[i][j];
			if(D[idx]-C[idx]+1>cur){ans[idx].fi=A[idx];continue;}
			int y=jump_tree(x,D[idx]-C[idx]+1);
		//	if(idx==1||idx==2)cerr<<cur<<' '<<y<<' '<<qry(rt[y],1,1,1,m).se<<endl;
			ans[idx]=qry(rt[y],A[idx],B[idx],1,m);if(!ans[idx].fi)ans[idx].fi=A[idx];
		}
	}
	rep(i,1,q)printf("%d %d\n",ans[i].fi,ans[i].se);
	return 0;
}