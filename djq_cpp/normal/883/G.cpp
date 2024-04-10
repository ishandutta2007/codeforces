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
vector<pii> G1[300005],G2[300005];
vector<pii> E;
bool vis[300005],cho[300005];
int ans=0;
void dfs(int u,vector<pii> G[]){
	ans++;
	vis[u]=true;
	rep(k,G[u].size()){
		int v=G[u][k].first;
		if(vis[v])continue;
		cho[G[u][k].second]=true;
		dfs(v,G);
	}
}
int main(){
	int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	rep(k,m){
		int t,u,v;
		scanf("%d%d%d",&t,&u,&v);
		if(t==1){
			G1[u].push_back(MP(v,m));
			G2[u].push_back(MP(v,m));
		}else{
			G2[u].push_back(MP(v,m));
			G2[v].push_back(MP(u,E.size()));
			E.push_back(MP(u,v));
		}
	}
	ans=0;memset(vis,false,sizeof(vis));dfs(s,G2);
	printf("%d\n",ans);
	rep(k,E.size())putchar(cho[k]?'-':'+');
	ans=0;memset(vis,false,sizeof(vis));dfs(s,G1);
	printf("\n%d\n",ans);
	rep(k,E.size())putchar(vis[E[k].first]?'-':'+');
	return 0;
}