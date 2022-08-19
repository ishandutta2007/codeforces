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
vector<int> Edg[200005];
vector<int> G[200005];
bool vis[200005];
vector<pair<pii,int> > ans;
bool dfs(int v,int par){
	vis[v]=true;
	rep(k,G[v].size()){
		int u=G[v][k];
		if(u==par)continue; 
		if(vis[u]){
			Edg[u].push_back(v);
			continue;
		}
		if(dfs(u,v))Edg[v].push_back(u);
	}
	for(int k=Edg[v].size()-1;k>0;k-=2)
	ans.push_back(MP(MP(Edg[v][k-1],Edg[v][k]),v));
	if((Edg[v].size()&1)&&par>0)ans.push_back(MP(MP(Edg[v][0],par),v));
	return !(Edg[v].size()&1);
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	rep(k,m){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	rep1(k,n)if(!vis[k])dfs(k,-1);
	printf("%d\n",ans.size());
	rep(k,ans.size())printf("%d %d %d\n",ans[k].first.first,ans[k].second,ans[k].first.second);
	return 0;
}