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
int n,Q,dep[200005],en[200005],pre[200005][20],bpre[200005];
ll val[200005],inv[200005];
vector<pair<int,ll> > G[200005];
void dfs(int v,int par,int d){
	dep[v]=d;
	pre[v][0]=par;
	rep(k,G[v].size()){
		int u=G[v][k].first;
		if(u==par)continue;
		dfs(u,v,d+1);
		val[u]=inv[G[v][k].second];
		en[G[v][k].second]=u;
	}
}
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int t=0,d=dep[u]-dep[v];d>0;t++,d>>=1)
	if(d&1)u=pre[u][t];
	if(u==v)return u;
	for(int t=17;t>=0;t--)
	if(pre[u][t]!=pre[v][t]){
		u=pre[u][t];
		v=pre[v][t];
	}
	return pre[u][0];
}
int root(int x){
	return bpre[x]==x?x:bpre[x]=root(bpre[x]);
}
int main(){
	scanf("%d%d",&n,&Q);
	rep1(k,n-1){
		int u,v;
		scanf("%d%d%I64d",&u,&v,&inv[k]);
		G[u].push_back(MP(v,k));
		G[v].push_back(MP(u,k));
	}
	dfs(1,0,0);
	rep1(k,n)bpre[k]=k;
	rep1(i,17)rep1(j,n)
	pre[j][i]=pre[pre[j][i-1]][i-1];
	rep1(k,n)if(val[k]==1)bpre[k]=pre[k][0];
	val[1]=1;
	while(Q--){
		int t,u,v;ll x;
		scanf("%d",&t);
		if(t==1){
			scanf("%d%d%I64d",&u,&v,&x);
			int w=lca(u,v);
			while(u>0&&x>0){
				u=root(u);
				if(dep[u]<=dep[w])break;
				x/=val[u];
				u=pre[u][0];
			}
			while(v>0&&x>0){
				v=root(v);
				if(dep[v]<=dep[w])break;
				x/=val[v];
				v=pre[v][0];
			}
			printf("%I64d\n",x);
		}else{
			scanf("%d%I64d",&v,&x);
			if(x==1)bpre[en[v]]=pre[en[v]][0];
			else val[en[v]]=x;
		}
	}
	return 0;
}