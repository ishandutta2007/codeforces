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
int n,D[1000005],minD[1000005],grp[1000005],cnt;
int st[1000005],ssz;
bool hv[1000005],vis[1000005];
vector<int> G[1000005],dist[1000005];
vector<pair<int,ll> > G2[1000005];
ll tot[1000005],dp[1000005];
int deg[1000005];
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
ll sum[20005],pres[20005];
ll real_dist(int x){
	int l=0,r=20000;
	while(l<r){int mid=(l+r)>>1;if(sum[mid]<=x)l=mid+1;else r=mid;}
	return ll(r)*x-pres[r-1];
}
ll solve(int v){
	cnt=0;
	ll ans=0LL;
	st_clear();
	memset(D,0,sizeof(D));
	memset(minD,0,sizeof(minD));
	memset(grp,0,sizeof(grp)); 
	memset(vis,false,sizeof(vis));
	dfs(v);
	rep1(i,n){
		if(grp[i]==0)continue;
		rep(j,G[i].size())
		if(grp[i]==grp[G[i][j]])tot[grp[i]]+=real_dist(dist[i][j]);
		else G2[grp[i]].push_back(MP(grp[G[i][j]],dist[i][j]));
	}
	queue<int> Q;
	rep1(i,n)if(grp[i]==i)
	rep(j,G2[i].size())deg[G2[i][j].first]++;
	rep1(i,n)if(grp[i]==i&&deg[i]==0)Q.push(i);
	while(!Q.empty()){
		int u=Q.front();Q.pop();
		dp[u]+=tot[u];
		ans=max(ans,dp[u]);
		rep(k,G2[u].size()){
			int w=G2[u][k].first;
			deg[w]--;
			dp[w]=max(dp[w],dp[u]+G2[u][k].second);
			if(deg[w]==0)Q.push(w);
		}
	}
	return ans;
}
int main(){
	rep1(k,20000){
		sum[k]=sum[k-1]+k;
		pres[k]=pres[k-1]+sum[k];
	}
	int m,q;
	scanf("%d%d",&n,&m);
	rep(k,m){
		int u,v,l;
		scanf("%d%d%d",&u,&v,&l);
		G[u].push_back(v);
		dist[u].push_back(l);
	}
	scanf("%d",&q);
	printf("%I64d\n",solve(q));
	return 0;
}