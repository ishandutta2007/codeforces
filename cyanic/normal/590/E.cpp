#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

namespace G{
	const int N=100005,inf=1e9;
	struct edge{int v,f,c,p;};
	vector<edge> e[N];
	int d[N],r[N],in[N],n,m,s,t;
	void init(int _n,int _s,int _t){
		n=_n,s=_s,t=_t,m=0;
	}
	void add(int a,int b,int c){
		e[a].pb((edge){b,0,c,(int)e[b].size()});
		e[b].pb((edge){a,0,0,(int)e[a].size()-1});
	}
	int bfs(){
		static int q[N]; int l=0,r=0;
		fill(d+1,d+n+1,0),d[s]=1;
		for(l=r=0,q[r++]=s;l<r;){
			int u=q[l++];
			REP(i,e[u].size()){
				edge &v=e[u][i];
				if(!d[v.v]&&v.f<v.c){
					d[q[r++]=v.v]=d[u]+1;
					if(v.v==t)return 1;
				}
			}
		}
		return 0;
	}
	int dfs(int u,int a){
		if(u==t)return a;
		int res=0; in[u]=1;
		for(int &k=r[u];k<e[u].size();k++){
			edge &v=e[u][k];
			if(v.f<v.c&&d[v.v]==d[u]+1&&!in[v.v]){
				int now=dfs(v.v,min(a,v.c-v.f));
				v.f+=now,e[v.v][v.p].f-=now,res+=now;
				if(!(a-=now))break;
			}
		}
		return in[u]=0,res;
	}
	int flow(){
		int res=0;
		while(bfs()){
			fill(r+1,r+n+1,0);
			res+=dfs(s,inf);
		}
		return res;
	}
}

const int N=1505,M=10001005;
int f[N][N],t[M][2],fail[M],g[M],p[N],vis[N],cur[N];
int n,sz=1,rt=1;
char s[M];
vi e[N];

void ins(char s[],int id){
	int o=rt;
	for(int i=0;s[i];i++){
		if(!t[o][s[i]-'a'])
			t[o][s[i]-'a']=++sz;
		o=t[o][s[i]-'a'];
	}
	g[o]=id;
}

void build(){
	static int q[M];
	int l=0,r=0,u;
	REP(c,2)
		if(!t[rt][c])t[rt][c]=rt;
		else fail[q[r++]=t[rt][c]]=rt;
	while(l<r){
		u=q[l++];
		if(!g[u])g[u]=g[fail[u]];
		REP(c,2)
			if(!t[u][c])t[u][c]=t[fail[u]][c];
			else fail[q[r++]=t[u][c]]=t[fail[u]][c];
	}
}

void walk(char s[],int id){
	int o=rt;
	for(int i=0;s[i];i++)
		o=t[o][s[i]-'a'],f[id][g[o]]=1;
	f[id][g[fail[o]]]=1;
}

void dfs(int u){
	vis[u]=1;
	for(auto v:e[u])
		if(cur[v]&&!vis[v])vis[v]=1,dfs(cur[v]);
}

int main(){
	read(n);
	rep(i,1,n){
		scanf("%s",s+p[i]);
		ins(s+p[i],i);
		p[i+1]=p[i]+strlen(s+p[i])+1;
	}
	build();
	rep(i,1,n) walk(s+p[i],i);
	rep(k,1,n)rep(i,1,n)rep(j,1,n)
		f[i][j]|=f[i][k]&f[k][j];
	int S=n+n+1,T=S+1;
	G::init(T,S,T);
	rep(i,1,n)G::add(S,i,1),G::add(i+n,T,1);
	rep(i,1,n)rep(j,1,n)
		if(f[i][j]&&i!=j){
			G::add(i,n+j,1);
			e[n+j].pb(i);
			e[i].pb(n+j);
		}
	printf("%d\n",n-G::flow());
	rep(i,1,n)for(auto x:G::e[i])
		if(x.v!=S&&x.f)cur[i]=x.v,cur[x.v]=i;
	rep(i,1,n)if(!cur[i])dfs(i);
	rep(i,1,n)if(vis[i]&&!vis[i+n])printf("%d ",i);
	puts("");
	return 0;
}