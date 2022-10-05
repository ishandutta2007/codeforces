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
typedef double ld;
 
template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=200005;
int sz[N],w[N],vis[N],ans,n,m,a,b,c;
ld s[N],d[N],best=1e99;
vector<pii> e[N];

void dfs(int u,int fa,int from,int dis){
	s[from]+=dis*sqrt(dis)*w[u];
	d[from]+=sqrt(dis)*w[u];
	for(auto v:e[u])
		if(v.fi!=fa)dfs(v.fi,u,from,dis+v.se);
}

int find(int x){
	memset(s,0,sizeof s);
	memset(d,0,sizeof d);
	ld mx=-1,sum=0; int cur=0;
	for(auto v:e[x]){
		dfs(v.fi,x,v.fi,v.se);
		if(d[v.fi]>mx){
			mx=d[v.fi];
			cur=v.fi;
		}
		sum+=s[v.fi];
	}
	if(sum<best)best=sum,ans=x;
	return cur;
}

int tot,rt,mn;
void dfs1(int u,int fa){
	sz[u]=1;
	for(auto v:e[u])
		if(v.fi!=fa&&!vis[v.fi])
			dfs1(v.fi,u),sz[u]+=sz[v.fi];
}
void dfs2(int u,int fa){
	int mx=tot-sz[u];
	for(auto v:e[u])
		if(v.fi!=fa&&!vis[v.fi])
			dfs2(v.fi,u),mx=max(mx,sz[v.fi]);
	if(mx<mn)mn=mx,rt=u;
}

void solve(int u){
	dfs1(u,0);
	tot=mn=sz[u],rt=u;
	dfs2(u,0);
	int x=rt,y=find(x);
	vis[x]=1;
	if(y&&!vis[y])solve(y);
}

int main(){
	read(n);
	rep(i,1,n)read(w[i]);
	rep(i,1,n-1){
		read(a),read(b),read(c);
		e[a].pb(mp(b,c)),e[b].pb(mp(a,c));
	}
	solve(1);
	printf("%d %.10lf\n",ans,best);
	return 0;
}