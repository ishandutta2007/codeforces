#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<int(n);i++)
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

const int N=2005,inf=1e9+9;
namespace G{
	struct edge{int u,v,f,c,p;};
	vector<edge> e[N];
	int d[N],r[N],in[N],n,s,t;
	void init(int _n,int _s,int _t){
		rep(i,1,n) e[i].clear();
		n=_n,s=_s,t=_t;
	}
	int add(int u,int v,int w){
		e[u].pb((edge){u,v,0,w,(int)e[v].size()});
		e[v].pb((edge){v,u,0,0,(int)e[u].size()-1});
		return (int)e[u].size()-1;
	}
	int bfs(){
		static int q[N]; int l=0,r=0;
		fill(d+1,d+n+1,-1),d[s]=0;
		for(q[r++]=s;l<r;){
			int u=q[l++];
			REP(i,e[u].size()){
				edge &v=e[u][i];
				if(v.f<v.c&&d[v.v]==-1){
					d[q[r++]=v.v]=d[u]+1;
					if(v.v==t) return 1;
				}
			}
		}
		return 0;
	}
	int dfs(int u,int a){
		if(u==t) return a;
		int res=0; in[u]=1;
		for(int &i=r[u];i<(int)e[u].size();i++){
			edge &v=e[u][i];
			if(v.f<v.c&&d[u]+1==d[v.v]&&!in[v.v]){
				int ret=dfs(v.v,min(v.c-v.f,a));
				v.f+=ret,e[v.v][v.p].f-=ret,res+=ret;
				if(!(a-=ret)) break;
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

int u[N],v[N],g[N],d[N],f[N],id[N];
int n,m,s,t,S,T;

int main(){
	read(n),read(m);
	read(s),read(t);
	rep(i,1,m){
		read(u[i]),read(v[i]),read(g[i]);
		if(g[i]) d[u[i]]++,d[v[i]]--;
	}
	G::init(n,s,t);
	rep(i,1,m){
		if(g[i]){
			G::add(u[i],v[i],1);
			G::add(v[i],u[i],inf);
		}
		else{
			G::add(u[i],v[i],inf);
		}
	}
	cout<<G::flow()<<endl;
	rep(i,1,m){
		if(!g[i]) continue;
		f[i]=(G::d[u[i]]>=0&&G::d[v[i]]==-1);
	}
	S=n+1,T=n+2;
	G::init(n+2,S,T);
	rep(i,1,m){
		if(!g[i]) continue;
		id[i]=G::add(u[i],v[i],inf);
	}
	G::add(t,s,inf);
	rep(i,1,n){
		if(d[i]>0) G::add(i,T,d[i]);
		else G::add(S,i,-d[i]);
	}
	G::flow();
	rep(i,1,m){
		if(!g[i]) { puts("0 1"); continue; }
		int bas=G::e[u[i]][id[i]].f+1;
		printf("%d %d\n",bas,bas+(!f[i]?1:0));
	}
	return 0;
}