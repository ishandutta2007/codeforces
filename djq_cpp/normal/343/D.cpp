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
vector<int> G[500005];
set<int> cur;
set<int> inc[500005];
int id[500005],cnt;
vector<int> q1[500005],q2[500005],q3[500005];
int ans[500005];
void dfs(int v,int par){
	rep(k,q1[v].size())cur.insert(q1[v][k]);
	int ms=-1,mu=-1;
	rep(k,G[v].size()){
		int u=G[v][k];
		if(u==par)continue;
		dfs(u,v);
		if((int)inc[id[u]].size()>ms){
			ms=inc[id[u]].size();
			mu=u;
		}
	}
	if(mu==-1)id[v]=cnt++;
	else id[v]=id[mu];
	rep(k,G[v].size()){
		int u=G[v][k];
		if(u==par||u==mu)continue;
		for(set<int>::iterator it=inc[id[u]].begin();it!=inc[id[u]].end();it++)
		inc[id[v]].insert(*it);
	}
	rep(k,q2[v].size())inc[id[v]].insert(q2[v][k]);
	rep(k,q3[v].size()){
		int cq=q3[v][k];
		set<int>::iterator it1=cur.lower_bound(cq),it2=inc[id[v]].lower_bound(cq);
		if(it1==cur.begin())ans[cq]=false;
		else if(it2==inc[id[v]].begin())ans[cq]=true;
		else{
			it1--;it2--;
			ans[cq]=*it1>*it2;
		}
	}
	rep(k,q1[v].size())cur.erase(cur.find(q1[v][k]));
}
int main(){
	int n,q;
	scanf("%d",&n);
	rep(k,n-1){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	scanf("%d",&q);
	rep(k,q){
		int t,v;
		scanf("%d%d",&t,&v);
		if(t==1)q1[v].push_back(k);
		else if(t==2)q2[v].push_back(k);
		else q3[v].push_back(k);
	}
	memset(ans,-1,sizeof(ans));
	dfs(1,-1);
	rep(k,q)if(ans[k]!=-1)printf("%d\n",ans[k]);
	return 0;
}