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
vector<int> G[200005];
bool del[200005];
int sz[200005],pre[200005];
char dat[200005];
ll ans[200005],ca[200005];
int cnt[1048576];
vector<pii> cc[200005];
void dfs(int v,int par){
	sz[v]=1;
	pre[v]=par;
	rep(k,G[v].size()){
		int u=G[v][k];
		if(u!=par&&!del[u]){
			dfs(u,v);
			sz[v]+=sz[u];
		}
	}
}
void dfs2(int v,int msk,int grp){
	ca[v]=0LL;
	msk^=1<<dat[v];
	cnt[msk]++;
	cc[grp].push_back(MP(msk,v));
	rep(k,G[v].size()){
		int u=G[v][k];
		if(u!=pre[v]&&!del[u])
		dfs2(u,msk,grp);
	}
}
void dfs3(int v,int msk,ll& chg){
	chg+=ca[v];
	msk^=1<<dat[v];
	cnt[msk]--;
	rep(k,G[v].size()){
		int u=G[v][k];
		if(u!=pre[v]&&!del[u]){
			dfs3(u,msk,chg);
			ca[v]+=ca[u];
		}
	}
	ans[v]+=ca[v];
}
int centroid(int tot,int v){
	int csz=tot-sz[v],cur=pre[v];
	rep(k,G[v].size()){
		int u=G[v][k];
		if(u!=pre[v]&&!del[u]&&sz[u]>csz){
			cur=u;
			csz=sz[u];
		}
	}
	return csz+csz<=tot?v:centroid(tot,cur);
}
void solve(int rt){
	dfs(rt,-1);
	rt=centroid(sz[rt],rt);
	dfs(rt,-1);
	del[rt]=true;
	rep(k,G[rt].size()){
		int u=G[rt][k];
		if(!del[u]){
			cc[k].clear();
			dfs2(u,0,k);
		}
	}
	ll cur=cnt[1<<dat[rt]];
	rep(k,20)cur+=cnt[(1<<k)^(1<<dat[rt])];
	cnt[0]++;
	ans[rt]++;
	rep(i,G[rt].size()){
		int u=G[rt][i];
		if(!del[u]){
			rep(j,cc[i].size())cnt[cc[i][j].first]--;
			rep(j,cc[i].size()){
				ca[cc[i][j].second]+=cnt[cc[i][j].first^(1<<dat[rt])];
				rep(k,20)ca[cc[i][j].second]+=cnt[cc[i][j].first^(1<<dat[rt])^(1<<k)];
			}
			rep(j,cc[i].size())cnt[cc[i][j].first]++;
		}
	}
	cnt[0]--;
	rep(k,G[rt].size()){
		int u=G[rt][k];
		if(!del[u])dfs3(u,0,cur);
	}
	ans[rt]+=cur/2;
	rep(k,G[rt].size()){
		int u=G[rt][k];
		if(!del[u])solve(u);
	}
}
int main(){
	int n,u,v;
	scanf("%d",&n);
	rep(k,n-1){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u); 
	}
	scanf("%s",dat+1);
	rep1(k,n)dat[k]-='a';
	solve(1);
	rep1(k,n)printf("%I64d ",ans[k]);
	return 0;
}