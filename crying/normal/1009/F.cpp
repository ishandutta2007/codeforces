#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=1e6+10;
int n,depth[MAXN],maxd[MAXN],wson[MAXN];
pi ans[MAXN];
vector<int>e[MAXN];
deque<int>f;
void upd(pi& p1,pi p2){
	if(p2.fr<p1.fr)return;
	if(p2.fr>p1.fr){p1=p2;return;}
	p1.se=min(p1.se,p2.se);
}
void dfs1(int u,int fa){
	depth[u]=depth[fa]+1;
	for(auto v:e[u]){
		if(v==fa)continue;
		dfs1(v,u);
		maxd[u]=max(maxd[u],maxd[v]+1);
		if((wson[u]==0) || (maxd[v]>maxd[wson[u]]))wson[u]=v;
	}
}
void add(int u,int fa,int rt){
	int k=depth[u]-depth[rt];
	f[k]++;
	upd(ans[rt],mp(f[k],k));
	for(auto v:e[u]){
		if(v==fa)continue;
		add(v,u,rt);
	}
}
void dfs2(int u,int fa){
	if(!wson[u]){
		ans[u].fr=1;
		ans[u].se=0;
		f.push_front(1);
		return;
	}
	for(auto v:e[u]){
		if(v==fa || v==wson[u])continue;
		dfs2(v,u);f.clear();
	}
	dfs2(wson[u],u);
	ans[u]=ans[wson[u]];ans[u].se++;
	f.push_front(1);
	upd(ans[u],mp(1,0));
	for(auto v:e[u]){
		if(v==fa || v==wson[u])continue;
		add(v,u,u);
	}
}
int main(){
	scanf("%d",&n);
	rep(i,1,n-1){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].pb(v);e[v].pb(u);
	}
	dfs1(1,0);
	rep(i,1,n)ans[i]=mp(-1e9,1e9);
	dfs2(1,0);
	rep(i,1,n){
		printf("%d\n",ans[i].se);
	}
	return 0;
}