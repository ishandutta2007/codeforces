#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=1e9+7;
int st[300005],ssz;
bool hv[300005];
bool vis[300005];
int cnt,D[300005],minD[300005];
vector<int> G[300005],G2[300005],root;
int grp[300005];
int lcac[300005],lc[300005],rc[300005];
int pre[300005][20],dep[300005];
map<pii,int> ecnt;
int st_top(){
	return st[ssz-1];
}
void st_push(int v){
	st[ssz++]=v;
	hv[st_top()]=true;
}
void st_pop(){
	hv[st_top()]=false;
	ssz--;
}
void st_clear(){
	while(ssz){
		hv[st_top()]=false;
		ssz--;
	}
}
bool st_in(int v){
	return hv[v];
}
int st_kth(int id){
	return id>=ssz?-1:st[id];
}
void dfs(int v,int par){
	vis[v]=true;
	D[v]=minD[v]=++cnt;
	st_push(v);
	rep(k,G[v].size()){
		int u=G[v][k];
		if(u==par&&ecnt[MP(v,par)]==1)continue;
		if(!vis[u]){
			dfs(u,v);
			minD[v]=min(minD[v],minD[u]);
		}else if(st_in(u))minD[v]=min(minD[v],D[u]);
	}
	if(D[v]==minD[v])
	for(;;){
		int u=st_top();
		st_pop();
		grp[u]=v;
		if(u==v)break;
	}
}
void getG2(int n){
	rep1(i,n)rep(j,G[i].size())
	if(grp[i]!=grp[G[i][j]])G2[grp[i]].push_back(grp[G[i][j]]);
	rep1(k,n){
		sort(G2[k].begin(),G2[k].end());
		G2[k].resize(unique(G2[k].begin(),G2[k].end())-G2[k].begin()); 
	}
}
void dfs2(int v,int par){
	pre[v][0]=par;
	dep[v]=dep[par]+1;
	rep(k,G2[v].size()){
		int u=G2[v][k];
		if(u==par)continue;
		dfs2(u,v);
	}
}
void init_lca(int n){
	rep1(i,18)rep1(j,n)
	pre[j][i]=pre[pre[j][i-1]][i-1];
}
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	int dif=dep[u]-dep[v];
	rep(k,19)if((dif>>k)&1)u=pre[u][k];
	if(u==v)return u;
	for(int k=18;k>=0;k--)
	if(pre[u][k]!=pre[v][k]){
		u=pre[u][k];
		v=pre[v][k];
	}
	return pre[u][0];
}
bool dfs3(int v,int par){
	rep(k,G2[v].size()){
		int u=G2[v][k];
		if(u==par)continue;
		if(!dfs3(u,v))return false;
		lc[v]+=lc[u];
		rc[v]+=rc[u];
	}
	lc[v]-=lcac[v];
	rc[v]-=lcac[v];
	return lc[v]==0||rc[v]==0;
}
int main(){
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	rep(k,m){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
		ecnt[MP(u,v)]++;ecnt[MP(v,u)]++;
	}
	dep[0]=-1;
	rep1(k,n)
	if(!vis[k]){
		dfs(k,0);
		root.push_back(k);
	}
	getG2(n);
	rep(k,root.size())dfs2(root[k],0);
	init_lca(n);
	rep(k,q){
		int u,v;
		scanf("%d%d",&u,&v);
		u=grp[u];v=grp[v];
		if(lca(u,v)==0){
			printf("No\n");
			return 0;
		}
		lc[u]++;rc[v]++;
		lcac[lca(u,v)]++;
	}
	rep(k,root.size())
	if(!dfs3(root[k],0)){
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	return 0;
}