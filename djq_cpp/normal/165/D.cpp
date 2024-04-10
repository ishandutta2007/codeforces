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
int root;
vector<int> ni[100005];
struct seg_tree{
	int MN;
	vector<int> tree;
	void init(int n){
		MN=1;
		while(MN<=n)MN<<=1;
		tree.resize(MN+MN,0);
	}
	void modify(int id,int v){
		id+=MN;
		tree[id]=v;
		id>>=1;
		while(id>0){
			tree[id]=tree[id<<1]+tree[id<<1|1];
			id>>=1;
		}
	}
	int query(int l,int r){
		l+=MN;r+=MN;
		int a1=0,a2=0;
		while(l<r){
			if(l&1)a1=a1+tree[l];
			if(!(r&1))a2=tree[r]+a2;
			l=(l+1)>>1;
			r=(r-1)>>1;
		}
		if(l==r)a1=a1+tree[l];
		return a1+a2;
	}
}tre[100005];
int gp[100005],id[100005];
void dfs(int v,int par,int grp){
	ni[grp].push_back(v);
	gp[v]=grp;
	id[v]=ni[grp].size();
	rep(k,G[v].size())
	if(G[v][k]!=par)dfs(G[v][k],v,grp);
}
pii E[100005];
int main(){
	int n,m;
	scanf("%d",&n);
	rep1(k,n-1){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
		E[k]=MP(u,v);
	}
	root=1;
	rep1(k,n)
	if(G[k].size()>2)root=k;
	rep(k,G[root].size())dfs(G[root][k],root,k);
	rep(k,G[root].size())tre[k].init(ni[k].size());
	scanf("%d",&m);
	rep(k,m){
		int t,u,v;
		scanf("%d%d",&t,&u);
		if(t==3){
			scanf("%d",&v);
			if(gp[u]==gp[v]){
				if(id[u]<id[v])swap(u,v);
				printf("%d\n",tre[gp[u]].query(id[v]+1,id[u])==0?id[u]-id[v]:-1);
			}else printf("%d\n",tre[gp[u]].query(0,id[u])+tre[gp[v]].query(0,id[v])==0?id[u]+id[v]:-1);
		}else{
			v=E[u].second;u=E[u].first;
			if(id[u]<id[v])swap(u,v);
			tre[gp[u]].modify(id[u],t-1);
		}
	}
	return 0;
}