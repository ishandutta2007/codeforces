#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define reg register
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)

char IO;
inline int rd(){
	int s=0,f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}


const int N=1e5+10;

int n,m;

int mk[N];


struct Edge{
	int to,nxt,w;
}e[N<<1];
int head[N],ecnt;
void AddEdge(int u,int v,int w){
	e[++ecnt]=(Edge){v,head[u],w};
	head[u]=ecnt;
}
#define erep(u,i) for(int i=head[u];i;i=e[i].nxt)

int fa[N][20],dep[N];

void pre_dfs(int u,int f){
	fa[u][0]=f;
	for(int i=1;(1<<i)<=dep[u];i++) fa[u][i]=fa[fa[u][i-1]][i-1];
	erep(u,i){
		int v=e[i].to;
		if(v==f) continue;
		dep[v]=dep[u]+1;
		pre_dfs(v,u);
	}
}

int LCA(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	//cout<<x<<' '<<y<<' '<<dep[x]<<' '<<dep[y]<<endl;
	for(int i=0,del=dep[x]-dep[y];(1<<i)<=del;i++) if(del&(1<<i)) x=fa[x][i];
	//cout<<x<<' '<<y<<endl;
	if(x==y) return x;
	drep(i,18,0) if(dep[x]>=(1<<i) && fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	//cout<<x<<' '<<y<<endl;
	return fa[x][0];
}



struct node{
	int ma[10];
	int lca;
	void merge(int t,int l,int u){
		if(t>ma[0]) lca=l;
		else if(t==ma[0]) lca=u;
		ma[3]=t;
		sort(ma,ma+4,greater<int>());
	}
}up[N],down[N];


void dfs1(int u,int f){
	memset(down[u].ma,-10,sizeof down[u].ma);
	if(mk[u]) {
		down[u].ma[0]=0;
		down[u].lca=u;
	}
	erep(u,i){
		int v=e[i].to;
		if(v==f) continue;
		dfs1(v,u);
		if(down[v].ma[0]<0) continue;
		down[u].merge(down[v].ma[0]+e[i].w,down[v].lca,u);
	}
	//cout<<"$"<<u<<' '<<down[u].ma[0]<<' '<<down[u].lca<<endl;
}

int s[N];
void mark(int x,int y){
	s[x]++,s[y]++;
	int lca=LCA(x,y);
	//cout<<"# "<<x<<' '<<y<<' '<<lca<<endl;
	s[lca]--;
	s[fa[lca][0]]--;
}

struct Node{
	int x,y;
	bool operator < (const Node __) const {
		return x>__.x;
	}
	bool operator == (const Node __) const {
		return x==__.x&&y==__.y;
	}
}V[N][6],tmp[100];

int tcnt=0;



void dfs2(int u,int f,int dis){
	memset(up[u].ma,-10,sizeof up[u].ma);
	if(mk[f]) up[u].ma[0]=dis,up[u].lca=f;
	if(u!=1){
		up[u].merge(up[f].ma[0]+dis,up[f].lca,f);
		tcnt=0;
		rep(i,0,3) if(!(V[f][i]==(Node){down[u].ma[0]+dis,down[u].lca}) && V[f][i].x>0 )  tmp[++tcnt]=V[f][i],tmp[tcnt].x+=dis;
		//cout<<"#$ "<<u<<' '<<t.x<<' '<<t.y<<endl;
		rep(i,1,tcnt) up[u].merge(tmp[i].x,tmp[i].y,f);
	}
	if(mk[u]){
		int lca;
		if(up[u].ma[0]>down[u].ma[0]) lca=up[u].lca;
		else if(up[u].ma[0]<down[u].ma[0]) lca=down[u].lca;
		else lca=u;
		//cout<<"$ "<<u<<' '<<up[u].ma[0]<<' '<<up[u].lca<<' '<<down[u].ma[0]<<' '<<down[u].lca<<endl;
		mark(u,lca);
	}
	rep(i,0,5) V[u][i].x=V[u][i].y=-1e9;
	erep(u,i){
		int v=e[i].to;
		if(v==f) continue;
		V[u][3].x=down[v].ma[0]+e[i].w;
		V[u][3].y=down[v].lca;
		sort(V[u],V[u]+4);
	}
	erep(u,i) {
		int v=e[i].to;
		if(v==f) continue;
		dfs2(v,u,e[i].w);
	}
}


int ans=-1,ansc=0;

void dfs_getans(int u,int f){
	erep(u,i){
		int v=e[i].to;
		if(v==f) continue;
		dfs_getans(v,u);
		s[u]+=s[v];
	}
	if(!mk[u]){
		if(ans<s[u]) ans=s[u],ansc=1;
		else if(ans==s[u]) ansc++;
	}
}




int main() {
	n=rd(),m=rd();
	rep(i,1,m) mk[rd()]=1;
	rep(i,2,n) {
		int u=rd(),v=rd(),w=rd();
		AddEdge(u,v,w);
		AddEdge(v,u,w);
	}
	pre_dfs(1,0);
	dfs1(1,0);
	dfs2(1,0,0);
	dfs_getans(1,0);
	printf("%d %d\n",ans,ansc);
}