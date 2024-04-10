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
int n,D[3005],minD[3005],grp[3005],minbk[3005],cnt;
int st[3005],ssz;
bool hv[3005],vis[3005];
vector<int> G[3005];
vector<pii> Q[3005][3005];
int ans[400005];
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
void dfs(int v){
	vis[v]=true;
	D[v]=minD[v]=++cnt;
	st_push(v);
	rep(k,G[v].size()){
		int u=G[v][k];
		if(!vis[u]){
			dfs(u);
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
void dfs2(int v,int ov,bool can){
	vis[v]=true;
	st_push(v);
	rep(k,Q[ov][v].size())ans[Q[ov][v][k].second]=can?st_kth(Q[ov][v][k].first):-1;
	rep(k,G[v].size()){
		int u=G[v][k];
		if(!vis[u])dfs2(u,ov,can&&u<=minbk[v]);
	}
	st_pop();
}
void solve(int v){
	cnt=0;
	st_clear();
	memset(D,0,sizeof(D));
	memset(minD,0,sizeof(minD));
	memset(grp,0,sizeof(grp)); 
	memset(vis,false,sizeof(vis));
	dfs(v);
	rep1(i,n){
		minbk[i]=INF;
		rep(j,G[i].size())
		if(grp[i]==grp[G[i][j]])minbk[i]=min(minbk[i],G[i][j]);
	}
	st_clear();
	memset(vis,false,sizeof(vis));
	dfs2(v,v,true);
}
int main(){
	int m,q;
	scanf("%d%d%d",&n,&m,&q);
	rep(k,m){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
	}
	rep(k,q){
		int s,t,id;
		scanf("%d%d%d",&s,&t,&id);
		Q[s][t].push_back(MP(id-1,k));
	}
	rep1(k,n)sort(G[k].begin(),G[k].end());
	memset(ans,-1,sizeof(ans));
	rep1(k,n)solve(k);
	rep(k,q)printf("%d\n",ans[k]);
	return 0;
}