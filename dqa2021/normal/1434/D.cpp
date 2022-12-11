#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")


#include<cstdio>
#include<algorithm>
#include<cctype>
#include<vector>
#include<queue>
#define pb push_back
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
const int INF=1e9;

int n,m;
struct Edge{
	int to,nxt,c;
}edge[1000010];
int cnt=1,last[500010];
inline void addedge(int x,int y,int v){
	edge[++cnt]=(Edge){y,last[x],v},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y],v},last[y]=cnt;
}
int siz[500010],dep[500010];
int id[500010],dfn[1000010],_id[500010],_dfn[500010];
int bt[1000010],st[20][1000010];
bool w[500010];
void dfs(int x,int f,int d,bool c){
	dep[x]=d; siz[x]=1; dfn[++*dfn]=x; id[x]=*dfn;
	_id[x]=++*_id,_dfn[++*_dfn]=x;
	w[x]=c;
	for (int i=last[x],v;i;i=edge[i].nxt)
		if ((v=edge[i].to)^f){
			dfs(v,x,d+1,c^edge[i].c);
			siz[x]+=siz[v];
			dfn[++*dfn]=x;
		}
}
int getlca(int x,int y){
	if (x>y) swap(x,y);
	int &t=bt[y-x+1],&u=st[t][x],&v=st[t][y-(1<<t)+1];
	return dep[u]<dep[v]?u:v;
}
int getdis(int x,int y){
	if (!~x||!~y) return -INF;
	return dep[x]+dep[y]-2*dep[getlca(id[x],id[y])];
}

#define ls (x<<1)
#define rs (x<<1|1)
#define mid (l+r>>1)

int A[2][1<<20],B[2][1<<20],L[2][1<<20];
bool tag[1<<20];
inline void pushdown(int x){
	if (!tag[x]) return; tag[x]=0;
	swap(A[0][ls],A[1][ls]); swap(B[0][ls],B[1][ls]);
	swap(A[0][rs],A[1][rs]); swap(B[0][rs],B[1][rs]);
	swap(L[0][ls],L[1][ls]); swap(L[0][rs],L[1][rs]);
	tag[ls]^=1; tag[rs]^=1;
}
inline void check(int &x,int &y,int &l,const int &X,const int &Y,int L){
	if (!~L) L=getdis(X,Y);
	if (L>l) x=X,y=Y,l=L;
//	if (getdis(X,Y)>getdis(x,y)) x=X,y=Y;
}
inline void pushup(int x){
	int &A0=A[0][x],&B0=B[0][x],&A1=A[1][x],&B1=B[1][x],&L0=L[0][x],&L1=L[1][x];
	A0=A1=B0=B1=-1,L0=L1=-INF;
	check(A0,B0,L0,A[0][ls],B[0][ls],L[0][ls]);
	check(A0,B0,L0,A[0][rs],B[0][rs],L[0][rs]);
	check(A0,B0,L0,A[0][ls],A[0][rs],-1);
	check(A0,B0,L0,A[0][ls],B[0][rs],-1);
	check(A0,B0,L0,B[0][ls],A[0][rs],-1);
	check(A0,B0,L0,B[0][ls],B[0][rs],-1);
	
	check(A1,B1,L1,A[1][ls],B[1][ls],L[1][ls]);
	check(A1,B1,L1,A[1][rs],B[1][rs],L[1][rs]);
	check(A1,B1,L1,A[1][ls],A[1][rs],-1);
	check(A1,B1,L1,A[1][ls],B[1][rs],-1);
	check(A1,B1,L1,B[1][ls],A[1][rs],-1);
	check(A1,B1,L1,B[1][ls],B[1][rs],-1);
}
void build(int x,int l,int r){
	if (l==r){
		bool t=w[_dfn[l]]; int s=_dfn[l];
		A[t][x]=B[t][x]=s,A[t^1][x]=B[t^1][x]=-1,L[t][x]=0,L[t^1][x]=-INF;
		return;
	}
	build(ls,l,mid); build(rs,mid+1,r);
	pushup(x);
}
void modify(int x,int l,int r,int ql,int qr){
	if (ql<=l&&r<=qr){
		tag[x]^=1;
		swap(A[0][x],A[1][x]); swap(B[0][x],B[1][x]);
		swap(L[0][x],L[1][x]);
		return;
	}
	pushdown(x);
	if (ql<=mid) modify(ls,l,mid,ql,qr);
	if (mid<qr) modify(rs,mid+1,r,ql,qr);
	pushup(x);
}

#undef ls
#undef rs
#undef mid

int main()
{
	n=read();
	for (int i=1;i<n;i++){
		int u=read(),v=read(),c=read();
		addedge(u,v,c);
	}
	dfs(1,0,1,0);
	bt[0]=-1; for (int i=1;i<=*dfn;i++) bt[i]=bt[i>>1]+1,st[0][i]=dfn[i];
	for (int j=1;j<20;j++)
		for (int i=1;i+(1<<j)-1<=*dfn;i++){
			int u=st[j-1][i],v=st[j-1][i+(1<<j-1)];
			if (dep[u]<dep[v]) st[j][i]=u;
			else st[j][i]=v;
		}
	build(1,1,n);
	m=read();
	while (m--){
		int e=read()<<1;
		if (dep[edge[e].to]<dep[edge[e^1].to]) e^=1;
		int u=edge[e].to;
		modify(1,1,n,_id[u],_id[u]+siz[u]-1);
//		printf("  test %d %d  %d %d\n",A[0][1],B[0][1],A[1][1],B[1][1]);
		printf("%d\n",max(L[0][1],L[1][1]));
	}
	return 0;
}