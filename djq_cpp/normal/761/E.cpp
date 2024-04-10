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
int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
ll ax[35],ay[35];
vector<int> G[35];
void dfs(int v,int par,ll x,ll y,ll dist,int udir){
	int d=(udir==0?1:0);
	ax[v]=x;
	ay[v]=y;
	rep(k,G[v].size()){
		int u=G[v][k];
		if(u==par)continue;
		dfs(u,v,x+dist*ll(dx[d]),y+dist*ll(dy[d]),dist/3ll,d^2);
		d++;
		if(d==udir)d++;
	}
}
int main(){
	int n,x,y;
	scanf("%d",&n);
	rep(k,n-1){
		scanf("%d%d",&x,&y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	rep1(k,n)if(G[k].size()>4){
		printf("NO");
		return 0;
	}
	printf("YES\n");
	ll dist=1ll;
	rep(k,n)dist*=3ll;
	dfs(1,-1,0,0,dist,-1);
	rep1(k,n)printf("%I64d %I64d\n",ax[k],ay[k]);
	return 0;
}