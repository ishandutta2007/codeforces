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
vector<pii> G[100005];
bool del[100005];
int sz[100005],pre[100005],dat[100005];
void dfs1(int v,int par){
	sz[v]=1;
	pre[v]=par;
	rep(k,G[v].size()){
		int u=G[v][k].first;
		if(u!=par&&!del[u]){
			dfs1(u,v);
			sz[v]+=sz[u];
		}
	}
}
int findcenter(int tot,int v){
	int csz=tot-sz[v],cur=pre[v];
	rep(k,G[v].size()){
		int u=G[v][k].first;
		if(u!=pre[v]&&!del[u]&&sz[u]>csz){
			cur=u;
			csz=sz[u];
		}
	}
	return csz+csz<=tot?v:findcenter(tot,cur);
}
int M,rr[2][100005];
void dfs2(int v,int par,int dep,int cs,int from[],map<int,int>& cnt){
	cs=(cs+ll(from[dep])*dat[v])%M;
	cnt[cs]++;
	rep(k,G[v].size()){
		int u=G[v][k].first;
		if(u!=par&&!del[u]){
			dat[u]=G[v][k].second;
			dfs2(u,v,dep+1,cs,from,cnt);
		}
	}
}
map<int,int> tc[2],cc[2][100005];
ll solve(int root){
	dfs1(root,-1);
	root=findcenter(sz[root],root);
	del[root]=true;
	tc[0].clear();
	tc[1].clear();
	rep(k,G[root].size()){
		cc[0][k].clear();
		cc[1][k].clear();
	}
	rep(k,G[root].size()){
		int u=G[root][k].first;
		if(!del[u]){
			dat[u]=G[root][k].second;
			dfs2(u,root,0,0,rr[0],tc[0]);
			dfs2(u,root,0,0,rr[0],cc[0][k]);
			dfs2(u,root,0,0,rr[1],tc[1]);
			dfs2(u,root,0,0,rr[1],cc[1][k]);
		}
	}
	ll ans=tc[0][0]+tc[1][0];
	rep(k,G[root].size()){
		for(map<int,int>::iterator it=cc[0][k].begin();it!=cc[0][k].end();it++)
		ans+=(tc[1][it->first]-cc[1][k][it->first])*it->second;
	}
	rep(k,G[root].size())
	if(!del[G[root][k].first])ans+=solve(G[root][k].first);
	return ans;
}
ll exgcd(ll a,ll b,ll& x,ll& y){
	if(!a&&!b)return -1;
	if(!b){
		x=1;y=0;
		return a;
	}
	ll d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
void init(int n){
	ll t1,t2;
	exgcd(10%M,M,t2,t1);
	t1=10%M;t2=(M+t2)%M;
	rr[0][0]=(M-t1)%M;rr[1][0]=1;
	rep1(k,n){
		rr[0][k]=t1*rr[0][k-1]%M;
		rr[1][k]=t2*rr[1][k-1]%M;
	}
}
int main(){
	int n,u,v,w;
	scanf("%d%d",&n,&M);
	rep(k,n-1){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		G[u].push_back(MP(v,w));
		G[v].push_back(MP(u,w));
	}
	init(n);
	printf("%I64d\n",solve(0));
	return 0;
}