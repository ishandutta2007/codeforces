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
struct SEG_TREE{
	vector<ll> tree,asgn;
	//n is the power of 2
	void clear(int n=0){
		tree.resize(n+n,0);
		asgn.resize(n+n,-1);
	}
	SEG_TREE(int n=0){
		clear(n);
	}
	void assign(int l,int r,ll val,int cur,int cl,int cr){
		if(l==cl&&r==cr){
			asgn[cur]=val;
			tree[cur]=val;
			return;
		}
		int mid=(cl+cr)>>1;
		if(asgn[cur]!=-1){
			asgn[cur<<1]=asgn[cur<<1|1]=asgn[cur];
			tree[cur<<1]=tree[cur<<1|1]=tree[cur];
		}
		asgn[cur]=-1;
		if(l<=mid)assign(l,min(mid,r),val,cur<<1,cl,mid);
		if(r>mid)assign(max(mid+1,l),r,val,cur<<1|1,mid+1,cr);
		tree[cur]=tree[cur<<1]|tree[cur<<1|1];
	}
	ll query(int l,int r,int cur,int cl,int cr){
		if(asgn[cur]!=-1)return asgn[cur];
		if(l==cl&&r==cr)return tree[cur];
		int mid=(cl+cr)>>1;
		ll ans=0LL;
		if(l<=mid)ans|=query(l,min(mid,r),cur<<1,cl,mid);
		if(r>mid)ans|=query(max(mid+1,l),r,cur<<1|1,mid+1,cr);
		return ans;
	}
}tre(524288);
vector<int> G[400005];
int bg[400005],ed[400005],c[400005],cnt;
vector<int> dfss;
void dfs(int v,int par){
	dfss.push_back(v);
	bg[v]=cnt++;
	rep(k,G[v].size()){
		int u=G[v][k];
		if(u==par)continue;
		dfs(u,v);
	}
	ed[v]=cnt-1;
}
int getcnt(ll res){
	int ans=0;
	rep(k,60)if((res>>k)&1LL)ans++;
	return ans;
}
int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	rep1(k,n)scanf("%d",&c[k]);
	rep(k,n-1){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	rep1(k,n)tre.assign(bg[k],bg[k],1LL<<(c[k]-1),1,0,524287);
	while(q--){
		int t,v,c;
		scanf("%d%d",&t,&v);
		if(t==1)scanf("%d",&c);
		if(t==1)tre.assign(bg[v],ed[v],1LL<<(c-1),1,0,524287);
		else printf("%d\n",getcnt(tre.query(bg[v],ed[v],1,0,524287)));
	}
	return 0;
}