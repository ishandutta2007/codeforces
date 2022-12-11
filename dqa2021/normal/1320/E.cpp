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

int n,q;
struct Edge{
	int to,nxt;
}edge[400010];
int cnt=1,last[200010];
inline void addedge(int x,int y){
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y]},last[y]=cnt;
}
int fat[200010],son[200010],siz[200010],dep[200010];
int id[200010],dfn[200010],top[200010];
void dfs1(int cur,int fat,int dep)
{
	::fat[cur]=fat; ::dep[cur]=dep; siz[cur]=1;
	for (int i=last[cur],v;i;i=edge[i].nxt)
		if (v=edge[i].to,v^fat){
			dfs1(v,cur,dep+1);
			siz[cur]+=siz[v];
			if (!son[cur]||siz[v]>siz[son[cur]]) son[cur]=v;
		}
}
void dfs2(int cur,int top){
	::top[cur]=top; id[cur]=++*id; dfn[++*dfn]=cur;
	if (siz[cur]==1) return;
	dfs2(son[cur],top);
	for (int i=last[cur],v;i;i=edge[i].nxt)
		if (v=edge[i].to,(v^fat[cur])&&(v^son[cur]))
			dfs2(v,v);
}
int getlca(int x,int y){
	while (top[x]^top[y])
		if (dep[top[x]]<dep[top[y]]) y=fat[top[y]];
		else x=fat[top[x]];
	return dep[x]<dep[y]?x:y;
}
int getdis(int x,int y){
	return dep[x]+dep[y]-2*dep[getlca(x,y)];
}

int vvrn[200010],vid[200010]; int pos[200010],s[200010];
int seq[400010],seqtot,vrn[200010],tim;
int ask[200010];
bool cmp(int x,int y){
	return id[x]<id[y];
}
namespace V
{
	struct Edge{
		int to,nxt;
	}edge[200010];
	int cnt,last[200010];
	inline void addedge(int x,int y){
//		printf("addedge %d %d\n",x,y);
		edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
	}
	int getmin(int x,int y,int z)  //x y first occupy z
	{
		if (x==-1) return y;
		if (y==-1) return x;
		int a=(getdis(pos[x],z)+s[x]-1)/s[x];
		int b=(getdis(pos[y],z)+s[y]-1)/s[y];
		if (a^b) return a<b?x:y;
		return x<y?x:y;
	}
	int f[200010],g[200010];
	void dfs1(int cur){
		f[cur]=(vvrn[cur]==tim?vid[cur]:-1);
		for (int i=last[cur],v;i;i=edge[i].nxt)
			dfs1(v=edge[i].to),f[cur]=getmin(f[cur],f[v],cur);
//		printf("f %d = %d\n",cur,f[cur]);
	}
	void dfs2(int cur,int gfat){
//		printf("dfs2 %d %d\n",cur,gfat);
		int fstmax,secmax;
		if (vvrn[cur]==tim) fstmax=vid[cur],secmax=gfat;
		else fstmax=gfat,secmax=-1;
		for (int i=last[cur],v;i;i=edge[i].nxt)
		{
			v=edge[i].to;
			if (fstmax==-1||getmin(fstmax,f[v],cur)==f[v]) secmax=fstmax,fstmax=f[v];
			else if (secmax==-1||getmin(secmax,f[v],cur)==f[v]) secmax=f[v];
		}
		g[cur]=fstmax;
//		printf("g %d = %d\n",cur,g[cur]);
		for (int i=last[cur],v;i;i=edge[i].nxt)
		{
			v=edge[i].to;
			if (f[v]==fstmax) dfs2(v,secmax);
			else dfs2(v,fstmax);
		}
	}
}
int stk[200010],stktop;
int main()
{
	n=read();
	for (int i=1;i<n;i++) addedge(read(),read());
	dfs1(1,0,1); dfs2(1,1);	
	
	q=read();
	while (q--){
		int tot1=read(),tot2=read(); tim++; seqtot=0;
		for (int i=1,x,y;i<=tot1;i++){
			x=read(),y=read();
			vvrn[x]=tim; vid[x]=i; s[i]=y;
			seq[++seqtot]=x; vrn[x]=tim; pos[i]=x;
		}
		for (int i=1;i<=tot2;i++) vrn[ask[i]=seq[++seqtot]=read()]=tim;
//		puts("test");
		sort(seq+1,seq+seqtot+1,cmp); seqtot=unique(seq+1,seq+seqtot+1)-seq-1;
		for (int i=1,t=seqtot,j;i<t;i++)
			if (vrn[j=getlca(seq[i],seq[i+1])]^tim)
				vrn[j]=tim,seq[++seqtot]=j;
		sort(seq+1,seq+seqtot+1,cmp);
		stk[stktop=1]=seq[1];
		for (int i=2;i<=seqtot;i++){
			while (id[stk[stktop]]+siz[stk[stktop]]-1<id[seq[i]]) stktop--;
			V::addedge(stk[stktop],seq[i]); stk[++stktop]=seq[i];
		}
		V::dfs1(seq[1]); V::dfs2(seq[1],-1);
		for (int i=1;i<=tot2;i++) printf("%d ",V::getmin(V::f[ask[i]],V::g[ask[i]],ask[i])); puts("");
		
		//init
		V::cnt=0; for (int i=1;i<=seqtot;i++) V::last[seq[i]]=0;
	}
	return 0;
}