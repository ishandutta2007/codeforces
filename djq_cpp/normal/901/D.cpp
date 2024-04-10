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
const ll INF=1LL<<60;
bool vis[100005];
int to[200005];
ll deg[100005];
int dep[100005];
vector<int> G[100005];
ll used[200005];
ll rem[100005];
void dfs(int v,int par,int ce){
	vis[v]=true;
	dep[v]=dep[par]+1;
	rem[v]=deg[v];
	rep(k,G[v].size()){
		int e=G[v][k],u=to[e];
		if(u==par||vis[u])continue;
		dfs(u,v,e^1);
		rem[v]-=used[e];
	}
	if(ce!=-1){
		used[ce]=used[ce^1]=rem[v];
		rem[v]=0;
	}
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	rep1(k,n)scanf("%I64d",&deg[k]);
	rep(k,m){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(k<<1);
		G[v].push_back(k<<1|1);
		to[k+k]=v;
		to[k+k+1]=u;
	}
	memset(vis,false,sizeof(vis));
	dfs(1,0,-1);
	rep(k,m){
		int u=to[k<<1],v=to[k<<1|1];
		if(used[k<<1]!=0LL||(dep[u]-dep[v])&1)continue;
		ll cd=rem[1]>>1;
		if(!(dep[u]&1))cd=-cd;
		used[k<<1]=used[k<<1|1]=cd;
		deg[u]-=cd;
		deg[v]-=cd;
		break;
	}
	memset(vis,false,sizeof(vis));
	dfs(1,0,-1);
	if(rem[1]==0LL){
		printf("YES\n");
		rep(k,m)printf("%I64d\n",used[k<<1]);
	}else printf("NO\n");
	return 0;
}