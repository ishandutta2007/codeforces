#include<cstdio>
#include<algorithm>
#include<cctype>
#include<vector>
#define pb push_back
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
typedef long long ll;

int n,m,k; ll ans;
struct Edge{
	int to,nxt;
}edge[300010];
int cnt=1,last[150010];
inline void addedge(int x,int y){
	edge[++cnt]=(Edge){y,last[x]},last[x]=cnt;
	edge[++cnt]=(Edge){x,last[y]},last[y]=cnt;
}
struct Rec{
	int u,v,l;
}rec[150010];
int gnd[150010][18],dep[150010],siz[150010],son[150010]; int id[150010],idtot;
void dfs0(int cur,int dep){
	::dep[cur]=dep; siz[cur]=1; id[cur]=++idtot;
	for (int i=1;i<18&&gnd[cur][i-1];i++) gnd[cur][i]=gnd[gnd[cur][i-1]][i-1];
	for (int i=last[cur],v;i;i=edge[i].nxt)
		if ((v=edge[i].to)^gnd[cur][0]){
			gnd[v][0]=cur; dfs0(v,dep+1); siz[cur]+=siz[v];
			if (!son[cur]||siz[son[cur]]<siz[v]) son[cur]=v;
		}
}
int getlca(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int t=dep[x]-dep[y];
	for (int i=0;i<18;i++) if (t>>i&1) x=gnd[x][i];
	if (x==y) return x;
	for (int i=17;i>=0;i--) if (gnd[x][i]^gnd[y][i]) x=gnd[x][i],y=gnd[y][i];
	return gnd[x][0];
}
int lift(int x,int t){
	for (int i=0;i<18;i++) if (t>>i&1) x=gnd[x][i]; return x;
}
int tri[150010],vrn[150010],tim;
void add(int x,int v){
	for (;x<=n;x+=x&-x){
		if (vrn[x]^tim) vrn[x]=tim,tri[x]=0;
		tri[x]+=v;
	}
}
int ask(int x){
	int res=0;
	for (;x;x-=x&-x) if (vrn[x]^tim); else res+=tri[x];
	return res;
}
vector<int> A[150010],B[150010],C[150010];
void dfs1(int cur){
	for (int i=last[cur],v;i;i=edge[i].nxt)
		if((v=edge[i].to)^gnd[cur][0]) dfs1(v);
	for (int i=0;i<A[cur].size();i++){
		int u=rec[A[cur][i]].u,v=rec[A[cur][i]].v;
		ans+=ask(id[u])+ask(id[v]);
	}
	for (int i=0;i<A[cur].size();i++){
		int u=rec[A[cur][i]].u,v=rec[A[cur][i]].v;
		if (dep[u]-dep[cur]>=k){
			u=lift(u,dep[u]-dep[cur]-k);
			add(id[u],1); add(id[u]+siz[u],-1);
		}
		if (dep[v]-dep[cur]>=k){
			v=lift(v,dep[v]-dep[cur]-k);
			add(id[v],1); add(id[v]+siz[v],-1);
		}
	}
}
void upd2(int u,int v,int d){
	int l=getlca(u,v);
	if (dep[l]>=d) return;
	int len=d-dep[l]+1,t;
	if (len>=k) t=dep[v]-dep[l]-1;
	else if (k-len>dep[v]-dep[l]-1) return;
	else t=dep[v]-dep[l]-1-k+len;
	v=lift(v,t);
	ans+=ask(id[v]+siz[v]-1)-ask(id[v]-1);
}
void upd3(int u,int v,int d){
	int l=getlca(u,v);
	if (dep[l]>d-k) return;
	u=lift(u,dep[u]-dep[l]-1);
	ans+=ask(id[l]+siz[l]-1)-ask(id[l]-1)-ask(id[u]+siz[u]-1)+ask(id[u]-1);
	if (v==l) return;
	v=lift(v,dep[v]-dep[l]-1);
	ans-=ask(id[v]+siz[v]-1)-ask(id[v]-1);
}
void ins(int v){add(id[v],1);}
int stk[150010],stktop;
void dfs3(int cur){
	stk[++stktop]=cur;
	for (int i=last[cur],v;i;i=edge[i].nxt)
		if((v=edge[i].to)^gnd[cur][0])
			dfs3(v);
}
void dfs2(int cur,bool S){
	if (siz[cur]==1){
		++tim;
		if (S) for (int i=0;i<C[cur].size();i++) upd3(cur,C[cur][i],dep[cur]),ins(C[cur][i]);
		else for (int i=0;i<B[cur].size();i++) upd2(cur,B[cur][i],dep[cur]),ins(B[cur][i]);
		return;
	}
	for (int i=last[cur],v;i;i=edge[i].nxt)
		if (((v=edge[i].to)^gnd[cur][0])&&(v^son[cur]))
			dfs2(v,S);
	dfs2(son[cur],S);
	if (S) for (int i=0;i<C[cur].size();i++) upd3(cur,C[cur][i],dep[cur]),ins(C[cur][i]);
	else for (int i=0;i<B[cur].size();i++) upd2(cur,B[cur][i],dep[cur]),ins(B[cur][i]);
	for (int o=last[cur],v;o;o=edge[o].nxt)
		if (((v=edge[o].to)^gnd[cur][0])&&(v^son[cur])){
			stktop=0; dfs3(v);
			for (int i=1;i<=stktop;i++){
				int u=stk[i];
				if (S) for (int j=0;j<C[u].size();j++) upd3(u,C[u][j],dep[cur]);
				else for (int j=0;j<B[u].size();j++) upd2(u,B[u][j],dep[cur]);
			}
			for (int i=1;i<=stktop;i++){
				int u=stk[i];
				if (S) for (int j=0;j<C[u].size();j++) ins(C[u][j]);
				else for (int j=0;j<B[u].size();j++) ins(B[u][j]);
			}
		}
}
int main()
{
	n=read(),m=read(),k=read();
	if (k==n) return puts("0"),0;
	for (int i=1;i<n;i++) addedge(read(),read());
	dfs0(1,1);
	for (int i=1;i<=m;i++){
		int u=read(),v=read(),l=getlca(u,v); if (id[u]>id[v]) swap(u,v);
		rec[i]=(Rec){u,v,l};
		A[l].pb(i); if (u^l) B[u].pb(v),C[u].pb(v); C[v].pb(u);
	}
	dfs1(1); //printf("ans1 %lld\n",ans);
	dfs2(1,0); //printf("ans2 %lld\n",ans);
	dfs2(1,1); //printf("ans3 %lld\n",ans);
	printf("%I64d\n",ans);
	return 0;
}