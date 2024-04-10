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

const int N=200005;
int fa[N],f[N][20],tag[N],p[N],lg[N];
int now,ans,rt,n,m,Q,a,b,c;
ll dis[N],d[N],lim;
vector<pii> e[N];

void dfs(int u,int fa,ll D){
	dis[u]=max(dis[u],D);
	for(auto v:e[u])
		if(v.fi!=fa){
			d[v.fi]=d[u]+v.se;
			dfs(v.fi,u,D+v.se);
		}
}

void dfs2(int u){
	f[u][0]=fa[u];
	rep(j,1,18)f[u][j]=f[f[u][j-1]][j-1];
	for(auto v:e[u])
		if(v.fi!=fa[u]){
			d[v.fi]=d[u]+1;
			fa[v.fi]=u;
			dfs2(v.fi);
		}
}

void dfs3(int u){
	p[u]=u;
	for(auto v:e[u])
		if(v.fi!=fa[u]){
			dfs3(v.fi);
			if(dis[p[v.fi]]<dis[p[u]])p[u]=p[v.fi];
		}
	per(j,lg[d[p[u]]],0){
		int t=f[p[u]][j];
		if(t&&dis[t]>=dis[u]-lim)
			p[u]=t;
	}
	tag[u]++,tag[fa[p[u]]]--;
}

void dfs4(int u){
	for(auto v:e[u])
		if(v.fi!=fa[u]){
			dfs4(v.fi);
			tag[u]+=tag[v.fi];
		}
	ans=max(ans,tag[u]);
}

int main(){
	read(n);
	rep(i,1,n-1){
		read(a),read(b),read(c);
		e[a].pb(mp(b,c)),e[b].pb(mp(a,c));
	}
	dfs(1,0,0);
	rt=max_element(d+1,d+n+1)-d;
	d[rt]=0,dfs(rt,0,0);
	rt=max_element(d+1,d+n+1)-d;
	d[rt]=0,dfs(rt,0,0);
	rt=min_element(dis+1,dis+n+1)-dis;
	d[rt]=fa[rt]=0,dfs2(rt);
	lg[0]=-1;
	rep(i,1,n)lg[i]=lg[i>>1]+1;
	read(Q);
	while(Q--){
		fill(tag+1,tag+n+1,0);
		read(lim),dfs3(rt);
		ans=0,dfs4(rt);
		printf("%d\n",ans);
	}
	return 0;
}