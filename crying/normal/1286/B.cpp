#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
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
const int MAXN=2010;
int n,c[MAXN],root,fa,sz[MAXN],ans[MAXN];
vector<int>e[MAXN];
vector<pi>info[MAXN];
void dfs1(int u){
	int cnt=e[u].size();
	rep(j,0,cnt-1){
		int v=e[u][j];
		dfs1(v);
		sz[u]+=sz[v]+1;
	}
}
void Merge(int u,int v){
	if(info[u].size()==0){
		info[u]=info[v];return;
	}
	int lim=info[u].back().fr,sz=info[v].size();
	rep(j,0,sz-1){
		lim++;
		info[u].pb(mp(lim,info[v][j].se));
	}
}
void dfs2(int u){
	int cnt=e[u].size();
//	printf("u:%d\n",u);
	rep(j,0,cnt-1){
		int v=e[u][j];
		dfs2(v);
	//	printf("Merge %d %d\n",u,v);
		Merge(u,v);
	//	printf("succes\n");
	}
	if(sz[u]==0){
		info[u].pb(mp(1,u));
	}else{
		int val=c[u]+1;
	//	printf("val:%d(%d)\n",val,sz[u]-1);
		rep(j,0,sz[u]-1){
			if(info[u][j].fr>=val){
				info[u][j]=mp(info[u][j].fr+1,info[u][j].se);
			}
		}
		info[u].pb(mp(val,u));
	}
	sort(info[u].begin(),info[u].end());
	/*
	if(u==3){
		printf("TMP:(%d,%d)(%d,%d)\n",info[u][0].fr,info[u][0].se,info[u][1].fr,info[u][1].se);
	}
	*/
}
int main(){
	cin>>n;
	rep(i,1,n){
		cin>>fa>>c[i];
		if(!fa)root=i;
		else e[fa].pb(i);
	}
	dfs1(root);
	rep(i,1,n){
		if(c[i]>sz[i])return printf("NO\n"),0;
	}
	dfs2(root);
	rep(i,0,n-1){
		pi tmp=info[root][i];
		ans[tmp.se]=tmp.fr;
	}
	printf("YES\n");
	rep(i,1,n){
		printf("%d ",ans[i]);
	}
	return 0;
}