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
int pre[100005],sz[100005];
int cnt[100005];
vector<pair<int,pii> > E;
void init(int n){
	rep1(k,n)pre[k]=k;
	rep1(k,n)sz[k]=1;
}
int root(int v){
	if(pre[v]!=v)pre[v]=root(pre[v]);
	return pre[v];
}
long long unite(int u,int v){
	u=root(u);
	v=root(v);
	if(u==v)return 0LL;
	pre[v]=u;
	sz[u]+=sz[v];
	return ll(sz[u]-sz[v])*sz[v];
}
int main(){
	int n,m;
	ll ans=0;
	scanf("%d%d",&n,&m);
	rep1(k,n)scanf("%d",&cnt[k]);
	rep1(k,m){
		int u,v;
		scanf("%d%d",&u,&v);
		E.push_back(MP(min(cnt[u],cnt[v]),MP(u,v)));
	}
	sort(E.begin(),E.end());
	reverse(E.begin(),E.end());
	init(n);
	rep(k,E.size())ans+=ll(E[k].first)*unite(E[k].second.first,E[k].second.second);
	printf("%.8lf\n",(double)(ans+ans)/n/(n-1));
	return 0;
}