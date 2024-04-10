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
//segment tree
struct node{
	node* left;
	node* right;
	int data;
	node(int dat=0){
		left=right=NULL; 
		data=dat;
	}
};
void clear(node*& v){
	if(v==NULL)return;
	clear(v->left);
	clear(v->right);
	delete v;
	v=NULL;
}
void add(node*& v,int id,int val,int cl=0,int cr=131071){
	if(v==NULL)v=new node;
	v->data+=val;
	if(cl==cr)return;
	int mid=(cl+cr)>>1;
	if(id<=mid)add(v->left,id,val,cl,mid);
	else add(v->right,id,val,mid+1,cr);
}
int query(node* v,int l,int r,int cl=0,int cr=131071){
	if(v==NULL)return 0;
	if(cl==l&&cr==r)return v->data;
	int mid=(cl+cr)>>1;
	int ans=0;
	if(l<=mid)ans+=query(v->left,l,min(mid,r),cl,mid);
	if(r>mid)ans+=query(v->right,max(mid+1,l),r,mid+1,cr);
	return ans;
}
typedef node* seg_tree;
//main part
vector<pii> G[100005];
bool del[100005];
int dep[100005],sz[100005],pre[100005];
vector<pii> mem[100005];
vector<pii> qy[100005];
seg_tree tt,dat[100005];
void dfs1(int v,int par){
	pre[v]=par;
	sz[v]=1;
	dep[v]=dep[par]+1;
	rep(k,G[v].size()){
		int u=G[v][k].first;
		if(u!=par&&!del[u]){
			dfs1(u,v);
			sz[v]+=sz[u];
		}
	}
}
int find_ctr(int tot,int v){
	int csz=tot-sz[v],cur=pre[v];
	rep(k,G[v].size()){
		int u=G[v][k].first;
		if(u!=pre[v]&&!del[u]&&sz[u]>csz){
			cur=u;
			csz=sz[u];
		}
	}
	return csz+csz<=tot?v:find_ctr(tot,cur);
}
vector<int> hv;
void dfs2(int v,int par,int id,int dep,int cd){
	mem[id].push_back(MP(dep,cd));
	hv.push_back(cd);
	sz[v]=1;
	rep(k,G[v].size()){
		int u=G[v][k].first;
		if(u!=par&&!del[u]){
			dfs2(u,v,id,dep+1,cd+G[v][k].second);
			sz[v]+=sz[u];
		}
	}
}
int getid(int num){
	return upper_bound(hv.begin(),hv.end(),num)-hv.begin()-1;
}
ll solve(int d,int w,int root){
	dfs1(root,-1);
	if(sz[root]==1)return 0LL;
	int v=find_ctr(sz[root],root);
	del[v]=true;
	int cnt=1,tmp=0;
	ll ans=0LL;
	hv.clear();
	hv.push_back(0);
	mem[0].clear();
	mem[0].push_back(MP(0,0));
	rep(k,G[v].size()){
		int u=G[v][k].first;
		if(!del[u]){
			mem[cnt].clear();
			dfs2(u,v,cnt,1,G[v][k].second);
			cnt++;
		}
	}
	clear(tt);
	rep(i,cnt){
		clear(dat[i]);
		rep(j,mem[i].size()){
			tmp=max(tmp,mem[i][j].first);
			qy[mem[i][j].first].clear();
		}
	}
	sort(hv.begin(),hv.end());
	hv.resize(unique(hv.begin(),hv.end())-hv.begin());
	rep(i,cnt)rep(j,mem[i].size())
	qy[mem[i][j].first].push_back(MP(i,mem[i][j].second));
	tmp=min(tmp,d);
	for(int i=0;i<=tmp;i++){
		rep(j,qy[i].size()){
			int ci=getid(qy[i][j].second);
			add(tt,ci,1);
			add(dat[qy[i][j].first],ci,1);
		}
		if(d-i<=tmp)rep(j,qy[d-i].size()){
			int ci=getid(w-qy[d-i][j].second);
			ans+=query(tt,0,ci)-query(dat[qy[d-i][j].first],0,ci);
		}
	}
	for(int i=min(tmp,d-tmp-1);i>=0;i--)rep(j,qy[i].size()){
		int ci=getid(w-qy[i][j].second);
		ans+=query(tt,0,ci)-query(dat[qy[i][j].first],0,ci);
	}
	rep(k,G[v].size()){
		int u=G[v][k].first;
		if(!del[u])ans+=solve(d,w,u);
	}
	return ans;
}
int main(){
	int n,d,w;
	scanf("%d%d%d",&n,&d,&w);
	for(int u=2;u<=n;u++){
		int v,z;
		scanf("%d%d",&v,&z);
		G[u].push_back(MP(v,z));
		G[v].push_back(MP(u,z));
	}
	printf("%I64d\n",solve(d,w,1)>>1);
	return 0;
}