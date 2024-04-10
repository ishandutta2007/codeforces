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
vector<int> G[100005];
set<int> S;
int pre[100005][18];
vector<int> dfsS;
int id[100005],dep[100005];
void dfs(int v,int par,int d){
	id[v]=dfsS.size();
	dfsS.push_back(v);
	dep[v]=d;
	pre[v][0]=par;
	rep(k,G[v].size()){
		int u=G[v][k];
		if(u==par)continue;
		dfs(u,v,d+1);
	}
}
void init_LCA(int n){
	rep1(j,17)rep1(i,n)
	pre[i][j]=pre[pre[i][j-1]][j-1];
}
int LCA(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	int d=dep[u]-dep[v];
	rep(k,18)if((d>>k)&1)u=pre[u][k];
	if(u==v)return u;
	for(int k=17;k>=0;k--)
	if(pre[u][k]!=pre[v][k]){
		u=pre[u][k];
		v=pre[v][k];
	}
	return pre[u][0];
}
int dist(int u,int v){
	int uv=LCA(u,v);
	return dep[u]+dep[v]-dep[uv]-dep[uv];
}
int dist_path(int v,int x,int y){
	return (dist(v,x)+dist(v,y)-dist(x,y))>>1;
}
int effect(int cur){
	if(S.empty())return 0;
	set<int>::iterator it=S.lower_bound(cur);
	int u=(it==S.end())?(*S.begin()):(*it);
	int v=(it==S.begin())?(*S.rbegin()):(*(--it));
	return dist_path(dfsS[cur],dfsS[u],dfsS[v]);
}
bool add(int v,int& cur,int lim){
	int ac=effect(id[v]);
	if(ac+cur>lim)return false;
	cur+=ac;
	S.insert(id[v]);
	return true;
} 
void del(int v,int& cur){
	S.erase(S.find(id[v]));
	cur-=effect(id[v]);
}
int main(){
	int n,t,u,v;
	scanf("%d%d",&n,&t);
	rep(k,n-1){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0,0);
	init_LCA(n);
	int l=1,r=1,cur=1,ans=0;
	while(l<=n){
		while(r<=n){
			if(!add(r,cur,t))break;
			r++;
		}
		ans=max(ans,r-l);
		del(l,cur);
		l++;
	}
	printf("%d",ans);
	return 0;
}