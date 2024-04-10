#include<bits/stdc++.h>
using namespace std;
const int S=555555;
vector<int>v[S];
#define lc c[0][p]
#define rc c[1][p]
int c[2][S],f[S],lz[S],sz[S],imp[S],n,ex[S],ey[S];
bool nr(int p){return c[0][f[p]]==p||c[1][f[p]]==p;}
void up(int p){sz[p]=sz[lc]+sz[rc]+imp[p];}
void spin(int p){
	int F=f[p],G=f[F],d=c[1][F]==p,B=c[!d][p];
	if(nr(F))c[c[1][G]==F][G]=p; c[!d][p]=F; c[d][F]=B;
	f[f[f[B]=F]=p]=G; up(F);
}
void rev(int p){swap(lc,rc);lz[p]^=1;}
void down(int p){if(lz[p])rev(lc),rev(rc),lz[p]=0;}
void push(int p){if(nr(p))push(f[p]);down(p);}
void splay(int p){push(p);for(int F;F=f[p],nr(p);spin(p))if(nr(F))spin((c[1][f[F]]==F)==(c[1][F]==p)?F:p);up(p);}
void access(int r){for(int p=r,y=0;p;p=f[y=p])splay(p),rc=y,up(p);splay(r);}
void make(int p){access(p);rev(p);}
void link(int a,int b){make(b);f[b]=a;}
void split(int a,int b){make(a);access(b);}
void cut(int a,int b){split(a,b);c[0][b]=f[a]=0;up(b);}
int find(int p){down(p);return sz[lc]?find(lc):(p>n?p:find(rc));}
void dfs(int p,int fa){
	for(int i=0,y;y=i<v[p].size()?v[p][i]:0;++i)if(y!=fa)dfs(y,p);
	if(p==1)return;
	split(p,fa);splay(p); int x=find(p); printf("%d %d %d %d\n",fa,p,ex[x],ey[x]);
	cut(ex[x],x); cut(ey[x],x); link(p,fa);
}
int main(){
	scanf("%d",&n);printf("%d\n",n-1);
	for(int i=1,a,b;i<n;++i)scanf("%d%d",&a,&b),v[a].push_back(b),v[b].push_back(a);
	for(int i=1+n,a,b;i<n+n;++i)scanf("%d%d",&ex[i],&ey[i]),imp[i]=1,link(ex[i],i),link(i,ey[i]);
	dfs(1,0);
}