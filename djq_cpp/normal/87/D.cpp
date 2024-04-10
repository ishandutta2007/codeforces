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
int n,pre[100005],sz[100005];
int dfsi[100005],cnt;
pii E[100005],ei[100005];
ll ans[100005];
vector<int> G[100005];
int root(int v){
	return pre[v]==v?v:pre[v]=root(pre[v]);
}
void dfs(int v,int par){
	dfsi[v]=cnt++;
	rep(k,G[v].size())
	if(G[v][k]!=par)dfs(G[v][k],v);
}
int main(){
	scanf("%d",&n);
	for(int k=1;k<n;k++){
		int u,v,d;
		scanf("%d%d%d",&u,&v,&d);
		G[u].push_back(v);
		G[v].push_back(u);
		ei[k]=MP(u,v);
		E[k]=MP(d,k);
	}
	rep1(k,n){
		pre[k]=k;
		sz[k]=1;
	}
	sort(E+1,E+n);
	dfs(1,0);
	for(int k=1;k<n;k++)
	if(dfsi[ei[k].first]>dfsi[ei[k].second])swap(ei[k].first,ei[k].second);
	int lp=1;
	for(int k=2;k<=n;k++)
	if(k==n||E[k].first!=E[k-1].first){
		vector<pii> curp;
		for(int j=lp;j<k;j++){
			int i=E[j].second;
			curp.push_back(MP(-dfsi[ei[i].second],i));
		}
		sort(curp.begin(),curp.end());
		rep(j,curp.size()){
			int i=curp[j].second;
			int u=ei[i].first,v=ei[i].second;
			sz[root(u)]+=sz[v];
			pre[v]=u;
		}
		rep(j,curp.size()){
			int i=curp[j].second;
			int u=ei[i].second;
			ans[i]=ll(sz[root(u)]-sz[u])*sz[u]*2LL;
		}
		lp=k;
	}
	ll ca=0LL;
	vector<int> cur;
	for(int k=1;k<n;k++)
	if(ans[k]>ca){
		ca=ans[k];
		cur.clear();
		cur.push_back(k);
	}else if(ans[k]==ca)cur.push_back(k);
	printf("%I64d %d\n",ca,cur.size());
	rep(k,cur.size())printf("%d ",cur[k]);
	return 0;
}