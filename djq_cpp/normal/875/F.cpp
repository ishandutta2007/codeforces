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
pair<int,pii> prin[200005];
int pre[200005];
bool cyc[200005];
int root(int v){
	return pre[v]==v?v:pre[v]=root(pre[v]);
}
bool unite(int u,int v){
	u=root(u);v=root(v);
	if(u==v){
		if(cyc[u])return false;
		else return cyc[u]=true; 
	}else if(cyc[u]&&cyc[v])return false;
	else{
		cyc[u]=cyc[u]||cyc[v];
		pre[v]=u;
		return true;
	}
}
int main(){
	int n,m;
	ll ans=0LL;
	scanf("%d%d",&n,&m);
	rep(k,m)scanf("%d%d%d",&prin[k].second.first,&prin[k].second.second,&prin[k].first);
	sort(prin,prin+m);
	reverse(prin,prin+m);
	rep1(k,n)pre[k]=k;
	rep(k,m)if(unite(prin[k].second.first,prin[k].second.second))ans+=prin[k].first;
	printf("%I64d\n",ans);
	return 0;
}