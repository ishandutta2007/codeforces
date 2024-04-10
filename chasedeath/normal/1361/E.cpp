#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int,int> Pii;
#define reg register
#define mp make_pair
#define pb push_back
#define Mod1(x) ((x>=P)&&(x-=P))
#define Mod2(x) ((x<0)&&(x+=P))
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
template <class T> inline void cmin(T &a,T b){ ((a>b)&&(a=b)); }
template <class T> inline void cmax(T &a,T b){ ((a<b)&&(a=b)); }

char IO;
template <class T=int> T rd(){
	T s=0; int f=0;
	while(!isdigit(IO=getchar())) f|=IO=='-';
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=2e5+10,INF=1e9+10;

int n,m,k;
struct Edge{
	int to,nxt;
} e[N<<1];
int head[N],ecnt;
void AddEdge(int u,int v){
	e[++ecnt]=(Edge){v,head[u]};
	head[u]=ecnt;
}
#define erep(u) for(int i=head[u],v=e[i].to;i;i=e[i].nxt,v=e[i].to)
int fa[N],fl;
int s[N],P[N];
int vis[N],lst[N],dep[N];
void Upd(int &u,int v){ if(dep[u]>dep[v]) u=v; }
void dfs(int u) {
	if(!fl) return;
	vis[u]=1,lst[u]=u,dep[u]=dep[fa[u]]+1;
	erep(u) {
		if(!vis[v]) fa[v]=u,dfs(v),s[u]+=s[v],Upd(lst[u],lst[v]);
		else if(vis[v]==2) fl=0;
		else s[u]++,s[v]--,Upd(lst[u],v);
	}
	vis[u]=2;
}

void dfs2(int u){
	if(fa[u]) assert(s[u]);
	s[u]=s[u]>1,s[u]|=s[lst[u]];
	erep(u) if(fa[v]==u) dfs2(v);
}

int main(){
	rep(_,1,rd()) {
		n=rd(),m=rd();
		rep(i,1,n) head[i]=0;
		ecnt=0;
		rep(i,1,m){
			int u=rd(),v=rd();
			AddEdge(u,v);
		}
		rep(i,1,n) P[i]=i;
		random_shuffle(P+1,P+n+1);
		int cnt=0,rt=-1;
		rep(i,1,n) {
			int u=P[i];
			if(++cnt>30) break;
			rep(j,1,n) vis[j]=s[j]=0;
			fl=1,fa[u]=0,dfs(u);
			if(fl) { 
				rt=u; 
				rep(j,1,n) assert(vis[j]);
				break; 
			}
		}
		if(rt==-1){ puts("-1"); continue; }
		cnt=0,dfs2(rt);
		rep(i,1,n) if(!s[i]) cnt++; 
		//cout<<cnt<<endl;
		if(5*cnt<n) puts("-1");
		else {
			rep(i,1,n) if(!s[i]) printf("%d ",i);
			puts("");
		}
	}
}