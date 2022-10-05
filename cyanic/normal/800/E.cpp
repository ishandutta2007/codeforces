#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
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

const int N=2005;
int fa[N],t[N][2],sz[N],vis[N],leaf[N];
int n,cur,rt,ans,aim;
vi e[N];

void getsz(int u,int pa){
	e[u].clear();
	if(fa[u]) e[u].pb(fa[u]);
	if(t[u][0]) e[u].pb(t[u][0]);
	if(t[u][1]) e[u].pb(t[u][1]);
	sz[u]=1;
	for(auto v:e[u]){
		if(v==pa||vis[v]) continue;
		getsz(v,u);
		sz[u]+=sz[v];
	}
}
int tot,root;
void getrt(int u,int pa){
	int mx=tot-sz[u];
	for(auto v:e[u]){
		if(v==pa||vis[v]) continue;
		getrt(v,u);
		mx=max(mx,sz[v]);
	}
	if(mx*2<=tot) root=u;
}

void solve(int u){
	getsz(u,0);
	tot=sz[u];
	if(tot==1){
		ans=u;
		return;
	}
	getrt(u,0);
	int o=root;
	if(tot==2&&!vis[fa[o]]) o=fa[o];
	printf("%d %d %d\n",leaf[t[o][0]],leaf[t[o][1]],aim);
	fflush(stdout);
	char ret[5]; scanf("%s",ret);
	if(ret[0]=='Z') vis[o]=1,solve(t[o][0]);
	if(ret[0]=='Y') vis[o]=1,solve(t[o][1]);
	if(ret[0]=='X') vis[t[o][0]]=vis[t[o][1]]=1,solve(o);
}

int main(){
	read(n);
	fa[1]=fa[2]=cur=n+1;
	t[cur][0]=1,t[cur][1]=2,leaf[cur]=2;
	rt=cur;
	rep(i,1,n) leaf[i]=i;
	rep(x,3,n){
		memset(vis,0,sizeof vis);
		vis[0]=1,aim=x,solve(rt);
		fa[++cur]=fa[ans];
		if(t[fa[cur]][0]==ans) t[fa[cur]][0]=cur;
		else t[fa[cur]][1]=cur;
		t[cur][0]=ans,fa[ans]=cur;
		t[cur][1]=aim,fa[aim]=cur;
		leaf[cur]=aim;
	}
	puts("-1");
	rep(i,1,2*n-1) printf("%d ",!fa[i]?-1:fa[i]);
	return 0;
}