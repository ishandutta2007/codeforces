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
const int MAXN=1e5+10;
int T,n;
int low[MAXN],dfn[MAXN],dfntot,vis[MAXN],scc[MAXN],num,st[MAXN],top,ins[MAXN];
int d[MAXN],ret;
pi a[MAXN],b[MAXN];
vector<int>e[MAXN],g[MAXN];
void tarjan(int u){
	dfn[u]=low[u]=++dfntot;
	st[++top]=u;vis[u]=ins[u]=1;
	for(auto v:e[u]){
		if(!vis[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}else if(ins[v]){
			low[u]=min(low[u],low[v]);
		}
	}
	if(dfn[u]==low[u]){
		num++;
		while(top){
			int tmp=st[top--];
			scc[tmp]=num;
			ins[tmp]=0;
			if(tmp==u)break;
		}
	}
}
void solve(){
	scanf("%d",&n);
	rep(i,1,n)e[i].clear(),g[i].clear();
	rep(i,1,n){
		scanf("%d",&a[i].fr);a[i].se=i; 
	}
	rep(i,1,n){
		scanf("%d",&b[i].fr);b[i].se=i;
	}
	sort(a+1,a+1+n);sort(b+1,b+1+n);
	per(i,n,2){
		e[a[i].se].pb(a[i-1].se);
		e[b[i].se].pb(b[i-1].se);
	}
	rep(i,1,n){
		vis[i]=ins[i]=0;
	}
	num=dfntot=top=0;
	rep(i,1,n){
		if(!vis[i])tarjan(i);
	}
	rep(i,1,num)d[i]=0;
	ret=-1;
	int cnt=0;
	rep(u,1,n){
		for(auto v:e[u]){
			if(scc[u]==scc[v])continue;
			g[scc[u]].pb(scc[v]);
			d[scc[v]]++;
		}
	}
	rep(i,1,num)if(d[i]==0)cnt++;
	rep(i,1,n){
		if(cnt==1 && d[scc[i]]==0)printf("1");
		else printf("0");
	}
	printf("\n");
	
}
int main(){
	scanf("%d",&T);
	while(T--){
		solve();
	}

	return 0;
}