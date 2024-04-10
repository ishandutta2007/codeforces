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
pii eid[200005],edges[200005];
vector<pii> tre[200005];
int pre[200005][20],maxv[200005][20],dep[200005];
int par[200005];
ll ans[200005];
int root(int v){
	return par[v]==v?v:par[v]=root(par[v]);
}
bool unite(int u,int v){
	u=root(u);v=root(v);
	if(u==v)return false;
	par[v]=u;
	return true;
}
void dfs(int v,int fa){
	pre[v][0]=fa;
	dep[v]=dep[fa]+1;
	rep(k,tre[v].size()){
		int u=tre[v][k].first;
		if(u!=fa){
			maxv[u][0]=tre[v][k].second;
			dfs(u,v);
		}
	}
}
int max_among(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	int ans=0,dif=dep[u]-dep[v];
	rep(k,18)if(dif>>k&1){
		ans=max(ans,maxv[u][k]);
		u=pre[u][k];
	}
	if(u==v)return ans;
	for(int k=17;k>=0;k--)
	if(pre[u][k]!=pre[v][k]){
		ans=max(ans,maxv[u][k]);
		ans=max(ans,maxv[v][k]);
		u=pre[u][k];
		v=pre[v][k];
	}
	return max(ans,max(maxv[u][0],maxv[v][0]));
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	rep(k,m){
		scanf("%d%d%d",&edges[k].first,&edges[k].second,&eid[k].first);
		eid[k].second=k;
	}
	sort(eid,eid+m);
	rep1(k,n)par[k]=k;
	rep(k,m){
		int id=eid[k].second;
		int u=edges[id].first,v=edges[id].second;
		if(unite(u,v)){
			tre[u].push_back(MP(v,eid[k].first));
			tre[v].push_back(MP(u,eid[k].first));
			ans[m]+=eid[k].first;
		}
	}
	dfs(1,0);
	rep1(i,17)rep1(j,n){
		pre[j][i]=pre[pre[j][i-1]][i-1];
		maxv[j][i]=max(maxv[j][i-1],maxv[pre[j][i-1]][i-1]);
	}
	rep(k,m)ans[eid[k].second]=ans[m]+eid[k].first;
	rep(k,m){
		int u=edges[k].first,v=edges[k].second;
		printf("%I64d\n",ans[k]-max_among(u,v));
	}
	return 0;
}