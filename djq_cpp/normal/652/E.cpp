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
int cnt,D[300005],minD[300005],chv[300005];
vector<int> G[300005],G2[300005],root;
int grp[300005];
int pre[300005];
map<pii,int> ecnt;
set<pii> can,ccan;
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
	else if(can.find(MP(i,G[i][j]))!=can.end())chv[grp[i]]=true;
	rep1(k,n){
		sort(G2[k].begin(),G2[k].end());
		G2[k].resize(unique(G2[k].begin(),G2[k].end())-G2[k].begin()); 
	}
	for(set<pii>::iterator it=can.begin();it!=can.end();it++)ccan.insert(MP(grp[it->first],grp[it->second]));
}
void dfs2(int v,int par){
	if(ccan.find(MP(v,par))!=ccan.end())chv[v]=true;
	pre[v]=par;
	rep(k,G2[v].size()){
		int u=G2[v][k];
		if(u==par)continue;
		dfs2(u,v);
	}
}
int main(){
	int n,m,from,to;
	scanf("%d%d",&n,&m);
	rep(k,m){
		int u,v,d;
		scanf("%d%d%d",&u,&v,&d);
		G[u].push_back(v);
		G[v].push_back(u);
		ecnt[MP(u,v)]++;ecnt[MP(v,u)]++;
		if(d){
			can.insert(MP(u,v));
			can.insert(MP(v,u));
		}
	}
	scanf("%d%d",&from,&to);
	dfs(from,0);
	getG2(n);
	memset(pre,-1,sizeof(pre));
	from=grp[from];to=grp[to];
	dfs2(from,0);
	if(pre[to]!=-1)
		while(to!=0){
			if(chv[to]){
			    printf("YES\n");
			    return 0;
			}
			to=pre[to];
		}
	printf("NO\n");
	return 0;
}