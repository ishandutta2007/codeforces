#include<bits/stdc++.h>
using namespace std;
const int maxn=3e2+10;
int n,now,Top,cur[maxn];
int Q[maxn],leaf,L[maxn],a[maxn],tag[maxn][maxn],Ans[maxn*maxn];
int gett[maxn*2],nxt[maxn*2],fir[maxn],f[maxn][11],top,dep[maxn];
inline void add(int x,int y){
	gett[++top]=y; nxt[top]=fir[x]; fir[x]=top;
}
void dfs(int x,int fa){
	f[x][0]=fa; dep[x]=dep[fa]+1; for (int i=1;i<=10;++i) f[x][i]=f[f[x][i-1]][i-1]; bool Leaf=0;
	for (int i=fir[x];i;i=nxt[i]){
		int v=gett[i];
		if (v==fa) continue;
		Leaf=1; dfs(v,x);
	}
	if (!Leaf) L[++leaf]=x;
}
inline int lca(int x,int y){
	if (dep[x]>dep[y]) swap(x,y);
	for (int i=10;i>=0;--i) if (dep[f[y][i]]>=dep[x]) y=f[y][i];
	if (x==y) return x;
	for (int i=10;i>=0;--i) if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}
inline void Over(){
	puts("-1"); exit(0);
}
inline void doit1(int x){
	while (now!=x){
		tag[now][f[now][0]]++; 
		if (tag[x][f[x][0]]>2) Over();
		now=f[now][0];  Ans[++top]=now; 
	}
}
inline void doit2(int x){
	Top=0; int k=x;
	while (x!=now){
		cur[++Top]=x; tag[x][f[x][0]]++; 
		if (tag[x][f[x][0]]>2) Over(); x=f[x][0];
	} //cur[++Top]=x; 
	for (int i=Top;i;--i) Ans[++top]=cur[i]; now=k;
}
void Gao(int x,int fa){
	for (int i=1,LCA;i<=leaf;++i){
		LCA=lca(now,a[i]);
		//printf("now:%d LCA:%d\n",now,LCA);
		if (now!=LCA) doit1(LCA);
		//printf("now:%d leaf:%d\n",now,a[i]);
		if (x!=a[i]) doit2(a[i]);
		//printf("now:%d\n",now);
	}
}
int main(){
	//freopen(".in","r",stdin);
	scanf("%d",&n);
	for (int i=1,x,y;i<n;++i){
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	} top=0;
	dfs(1,0); Ans[++top]=1;
	for (int i=1;i<=leaf;++i) scanf("%d",&a[i]);
	now=1; Gao(1,0);
	if (now!=1) doit1(1);
	for (int i=1;i<=top;++i) printf("%d ",Ans[i]);
	return 0;
}