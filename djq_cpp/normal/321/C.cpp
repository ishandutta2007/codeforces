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
int sz[100005];
bool del[100005];
char ans[100005];
void dfs(int v,int par){
	sz[v]=1;
	rep(k,G[v].size()){
		int u=G[v][k];
		if(del[u]||u==par)continue;
		dfs(u,v);
		sz[v]+=sz[u];
	}
}
int find_centre(int ssz,int v,int par){
	int msu=par,lar=ssz-sz[v];
	rep(k,G[v].size()){
		int u=G[v][k];
		if(del[u]||u==par)continue;
		if(sz[u]>lar){
			msu=u;
			lar=sz[u];
		}
	}
	return lar+lar<=ssz?v:find_centre(ssz,msu,v);
}
void solve(int root,char ch){
	dfs(root,0);
	root=find_centre(sz[root],root,0);
	del[root]=true;
	ans[root]=ch;
	rep(k,G[root].size()){
		int u=G[root][k];
		if(del[u])continue;
		solve(u,ch+1);
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
	solve(1,'A');
	rep1(k,n)printf("%c ",ans[k]);
	return 0;
}