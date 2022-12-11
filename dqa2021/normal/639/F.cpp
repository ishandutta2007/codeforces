#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
#undef G

int n,m,q,nn,col[300010];
struct Edge{
	int to,nxt;
}edge[600010];
int cnt=1,last[300010];
inline void addedge(int x,int y){
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y]},last[y]=cnt;
}
namespace T
{
	
struct Edge{
	int to,nxt;
}edge[600010];
int cnt=1,last[300010];
inline void addedge(int x,int y){
//	printf("T::addedge %d %d\n",x,y);
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y]},last[y]=cnt;
}
int fat[300010],siz[300010],son[300010],dep[300010],rt[300010];
int top[300010],id[300010];
void dfs1(int cur,int fat,int dep,int rt){
	T::fat[cur]=fat; T::dep[cur]=dep; T::rt[cur]=rt; siz[cur]=1;
	for (int i=last[cur],v;i;i=edge[i].nxt)
		if ((v=edge[i].to)^fat){
			dfs1(v,cur,dep+1,rt);
			siz[cur]+=siz[v];
			if (!son[cur]||siz[v]>siz[son[cur]]) son[cur]=v;
		}
}
void dfs2(int cur,int top){
	T::top[cur]=top; id[cur]=++*id;
	if (siz[cur]==1) return;
	dfs2(son[cur],top);
	for (int i=last[cur],v;i;i=edge[i].nxt)
		if (((v=edge[i].to)^fat[cur])&&(v^son[cur]))
			dfs2(v,v);
}
int getlca(int x,int y){
//	if (rt[x]!=rt[y]) printf("Err no lca for %d %d\n",x,y);
	while (top[x]^top[y])
		if (dep[top[x]]<dep[top[y]]) y=fat[top[y]];
		else x=fat[top[x]];
	return dep[x]<dep[y]?x:y;
}
int ni,mi,a[300010],b[300010],c[300010],seq[900010],seqtot;
namespace V
{

struct Edge{
	int to,nxt;
}edge[1200010];
int cnt=1,last[300010];  //cnt=1
inline void addedge(int x,int y){
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y]},last[y]=cnt;
}
int dfn[300010],low[300010],col[300010];
int stk[300010],stktop; int vrn[300010],tim;
void tarjan(int cur,int fid){
	dfn[cur]=low[cur]=++*dfn; vrn[cur]=tim; stk[++stktop]=cur;
	for (int i=last[cur],v;i;i=edge[i].nxt)
		if (vrn[v=edge[i].to]^tim){
			tarjan(v,i^1); low[cur]=min(low[cur],low[v]);
		}
		else if (i^fid) low[cur]=min(low[cur],dfn[v]);
	if (dfn[cur]^low[cur]) return;
	++*col;
	while (1){
		int x=stk[stktop--];
		col[x]=*col;
		if (x==cur) return;
	}
}

}
int stk[300010],stktop;
bool cmp(int x,int y){return id[x]<id[y];}
bool work(int msk){
	ni=read(),mi=read(); seqtot=0;
	for (int i=1;i<=ni;i++) seq[++seqtot]=a[i]=col[(read()-1+msk)%n+1];
	for (int i=1;i<=mi;i++) seq[++seqtot]=b[i]=col[(read()-1+msk)%n+1],seq[++seqtot]=c[i]=col[(read()-1+msk)%n+1];
	sort(seq+1,seq+seqtot+1,cmp); seqtot=unique(seq+1,seq+seqtot+1)-seq-1;
	for (int i=1,t=seqtot;i<t;i++) if (rt[seq[i]]==rt[seq[i+1]]){
		seq[++seqtot]=getlca(seq[i],seq[i+1]);
	}
	sort(seq+1,seq+seqtot+1,cmp); seqtot=unique(seq+1,seq+seqtot+1)-seq-1;
	for (int i=1;i<=seqtot;i++){
		if (i==1||(rt[seq[i]]^rt[seq[i-1]])){stk[stktop=1]=seq[i]; continue;}
		while (id[stk[stktop]]+siz[stk[stktop]]<=id[seq[i]]) stktop--;
		V::addedge(stk[stktop],seq[i]); stk[++stktop]=seq[i];
	}
	for (int i=1;i<=mi;i++) V::addedge(b[i],c[i]);
	V::tim++; (*V::dfn)=0; *(V::col)=0;
	for (int i=1;i<=seqtot;i++) if (V::vrn[seq[i]]^V::tim) V::tarjan(seq[i],0);
	bool flg=1; for (int i=2;i<=ni;i++) if (V::col[a[i]]^V::col[a[1]]){flg=0;break;}
	
	V::cnt=1; for (int i=1;i<=seqtot;i++) V::last[seq[i]]=0;
	return flg;
}

}
int dfn[300010],low[300010];
int stk[300010],stktop;
void tarjan(int cur,int fid){
	dfn[cur]=low[cur]=++*dfn; stk[++stktop]=cur;
	for (int i=last[cur],v;i;i=edge[i].nxt)
		if (!dfn[v=edge[i].to]){
			tarjan(v,i^1);
			low[cur]=min(low[cur],low[v]);
		}
		else if (i^fid) low[cur]=min(low[cur],dfn[v]);
	if (low[cur]^dfn[cur]) return;
	++*col;
	while (1){
		int x=stk[stktop];
		col[x]=*col; //printf("col %d: %d\n",x,col[x]);
		for (int i=last[x],v;i;i=edge[i].nxt)
			if (col[v=edge[i].to]&&(col[v]^col[x]))
				T::addedge(col[v],col[x]);
		if (stk[stktop--]==cur) return;
	}
}
int main()
{
	n=read(),m=read(),q=read();
	for (int i=1;i<=m;i++) addedge(read(),read());
	for (int i=1;i<=n;i++) if (!dfn[i]) tarjan(i,0); nn=col[0];
	for (int i=1;i<=nn;i++) if (!T::rt[i]) T::dfs1(i,0,1,i),T::dfs2(i,i);
	for (int i=1,lastans=0;i<=q;i++){
		if (T::work(lastans)) lastans=(lastans+i)%n,puts("YES");
		else puts("NO");
	}
	return 0;
}