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

int n,m,q;
int w[200010],iw[200010];
struct Rec{
	int t,u,v,id;
}rec[300010];
bool cmp(const Rec &x,const Rec &y){return x.t>y.t;}
struct Qry{
	int o,x;
}qry[500010];

struct Edge{
	int to,nxt;
}edge[400010];
int cnt,last[400010]; int idtot;
inline void addedge(int x,int y){
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
}
int ok_before[400010];
int gnd[19][400010];
int dfn[400010],siz[400010],id[400010];
void dfs(int x,int f){
	gnd[0][x]=f;
	for (int i=1;i<19&&gnd[i-1][x];i++) gnd[i][x]=gnd[i-1][gnd[i-1][x]];
	siz[x]=1; dfn[++*dfn]=x; id[x]=++*id;
	for (int i=last[x],v;i;i=edge[i].nxt){
		v=edge[i].to;
		dfs(v,x); siz[x]+=siz[v];
	}
}

#define ls (x<<1)
#define rs (x<<1|1)
#define mid (l+r>>1)
int node[1<<20];
void build(int x,int l,int r){
	if (l==r) return node[x]=dfn[l]<=n?w[dfn[l]]:0,void();
	build(ls,l,mid); build(rs,mid+1,r);
	node[x]=max(node[ls],node[rs]);
}
void modify(int x,int l,int r,int p){
	if (l==r) return node[x]=0,void();
	if (p<=mid) modify(ls,l,mid,p);
	else modify(rs,mid+1,r,p);
	node[x]=max(node[ls],node[rs]);
}
int query(int x,int l,int r,int ql,int qr){
	if (ql<=l&&r<=qr) return node[x];
	int res=0;
	if (ql<=mid) res=query(ls,l,mid,ql,qr);
	if (mid<qr) res=max(res,query(rs,mid+1,r,ql,qr));
	return res;
}
#undef ls
#undef rs
#undef mid


int f[400010];
int find(int x){return f[x]?f[x]=find(f[x]):x;}
int main()
{
	n=read(),m=read(),q=read(); idtot=n;
	for (int i=1;i<=n;i++) iw[w[i]=read()]=i;
	for (int i=1;i<=m;i++){
		int u=read(),v=read();
		rec[i]=(Rec){-1,u,v,i};
	}
	for (int i=1;i<=q;i++){
		int &o=qry[i].o,&x=qry[i].x;
		o=read(),x=read();
		if (o==2){
			rec[x].t=i;
		}
	}
	for (int i=1;i<=m;i++) if (!~rec[i].t) rec[i].t=q+1;
	sort(rec+1,rec+m+1,cmp);
	for (int i=1;i<=n;i++) ok_before[i]=q+1;
	for (int i=1;i<=m;i++){
		int u=rec[i].u,v=rec[i].v;
		int x=find(u),y=find(v);
		if (x==y) continue;
		int z=++idtot; f[x]=f[y]=z;
		addedge(z,x); addedge(z,y);
		ok_before[z]=rec[i].t;
	}
	for (int i=1;i<=idtot;i++) if (find(i)==i) dfs(i,0);
	build(1,1,idtot);
	for (int i=1;i<=q;i++){
		int &o=qry[i].o,&x=qry[i].x;
		if (o==2) continue;
		int y=x;
		for (int j=18;~j;j--) if (gnd[j][y]&&ok_before[gnd[j][y]]>i) y=gnd[j][y];
		int z=query(1,1,idtot,id[y],id[y]+siz[y]-1);
		printf("%d\n",z);
		if (!z) continue;
		z=iw[z]; z=id[z];
		modify(1,1,idtot,z);
	}
	return 0;
}