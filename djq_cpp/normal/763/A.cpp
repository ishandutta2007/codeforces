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
int c[100005],prev[100005],ok[100005];
bool dfs1(int v,int par){
	prev[v]=par;
	int cur=c[v];
	bool ans=true;
	rep(k,G[v].size()){
		int u=G[v][k];
		if(u==par)continue;
		if(c[u]!=c[v])ans=false;
		if(!dfs1(u,v))ans=false;
	}
	return ok[v]=ans;
}
//-1=all the same 0=error
int dfs2(int v,int cc){
	if(cc!=c[v])return v;
	int diff=-1;
	rep(k,G[v].size()){
		int u=G[v][k];
		if(u==prev[v])continue;
		int cur=dfs2(u,cc);
		if(cur==-1)continue;
		if(diff==-1)diff=cur;
		else return v;
	}
	return diff;
}
bool good(int v){
	rep(k,G[v].size()){
		int u=G[v][k];
		if(u==prev[v])continue;
		if(!ok[u])return false;
	}
	return true;
}
int main(){
	int n,u,v;
	scanf("%d",&n);
	rep(k,n-1){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	rep1(k,n)scanf("%d",&c[k]);
	dfs1(1,-1);
	if(good(1)){
		printf("YES\n1");
		return 0;
	}
	int ans=dfs2(1,c[1]);
	if(ans==0)printf("NO");
	else if(ans==-1)printf("YES\n1");
	else{
		if(good(ans))printf("YES\n%d",ans);
		else printf("NO");
	}
	return 0;
}