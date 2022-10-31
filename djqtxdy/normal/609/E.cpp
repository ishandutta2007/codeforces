#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string.h>
#include <stdio.h>
#define LL long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define big 19260817
#define pb push_back
#define mp make_pair
using namespace std;
// cf IO: I64d
// atcoder IO: 
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=200005;
const int Maxk=20;
int p[Maxn];
vector<pair<int,pair<int,int> > > e,ee;
vector<pair<int,int> > G[Maxn];
bool vis[Maxn];
int par[Maxk][Maxn],dep[Maxn];
int siz[Maxn];
int id[Maxn];
int num[Maxn];
int dist[Maxn]; // dist with parent

struct segtree{
	vector<int> tree;
	int n;
	segtree(){
		tree.clear();
		n=0;
	}
	void resize(int val){
		tree.resize(val*4,0);
		n=val;
	}
	void modify(int p,int l,int r,int pos,int val){
		if (l==r){
			tree[p]=val;
			return;
		}
		int mid=(l+r)>>1;
		if (pos<=mid){
			modify(p*2,l,mid,pos,val);
		}
		else{
			modify(p*2+1,mid+1,r,pos,val);
		}
		tree[p]=max(tree[p*2],tree[p*2+1]); 
	}
	int query(int p,int l,int r,int lo,int hi){
		if (lo<=l && r<=hi){
			return tree[p];
		}
		int mid=(l+r)>>1;
		int ans=0;
		if (lo<=mid){
			ans=max(ans,query(p*2,l,mid,lo,min(hi,mid)));
		}
		if (hi>mid){
			ans=max(ans,query(p*2+1,mid+1,r,max(lo,mid+1),hi));
		}
		return ans;
	}
	int Query(int lo,int hi){
		return query(1,1,n,lo,hi);
	}
	void Modify(int pos,int val){
		modify(1,1,n,pos,val);
	}
	void Build(int p,int l,int r,vector<int> & refer){
		if (l==r){
			tree[p]=dist[refer[l]];
			return;
		}
		int mid=(l+r)>>1;
		Build(p*2,l,mid,refer);
		Build(p*2+1,mid+1,r,refer);
		tree[p]=max(tree[p*2],tree[p*2+1]);
	}
	void build(vector<int> & refer){
		if (n==0) return;
		Build(1,1,n,refer);
	}
};
struct Chain{
	segtree tree;
	vector<int> ver;
	int beg;
	Chain(){
		ver.clear();
		beg=-1;
	}
	void _init(){
		tree.resize(ver.size()-1);
		tree.build(ver);
		beg=ver[0];
	}
	int query(int lo,int hi){
		if (lo>hi) return 0;
		return tree.Query(lo,hi);
	}
};
vector<Chain> chains;
void _init(){
	for (int i=0;i<Maxn;i++) p[i]=i;
}
int findset(int x){
	return p[x]=(p[x]==x)?x:findset(p[x]);
}
void Union(int x,int y){
	x=findset(x);
	y=findset(y);
	p[x]=y;
}
void dfs(int x,int depth){
	vis[x]=true;
	dep[x]=depth;
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i].first;
		if (!vis[v]){
			dist[v]=G[x][i].second;
			par[0][v]=x;
			dfs(v,depth+1);
			siz[x]+=siz[v];
		}
	}
	siz[x]++;
}
void heavy_light(int x,int chnum,int cnt){
	chains[chnum].ver.pb(x);
	id[x]=chnum;
	num[x]=cnt;
	vis[x]=true;
	int mxsiz=0;
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i].first;
		if (!vis[v]) mxsiz=max(mxsiz,siz[v]);
	}
	int cho;
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i].first;
		if (!vis[v] && siz[v]==mxsiz){
			heavy_light(v,chnum,cnt+1);
			cho=v;
			break;
		}
	}
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i].first;
		if (!vis[v]  && v!=cho){
			Chain tmp;
			chains.push_back(tmp);
			heavy_light(v,chains.size()-1,1);
		}
	}
}
int lca(int u,int v){
	if (dep[u]>dep[v]) swap(u,v);
	int diff=dep[v]-dep[u];
	for (int i=0;i<20;i++){
		if (diff & (1<<i)){
			v=par[i][v];
		}
	}
	if (u==v) return u;
	for (int i=19;i>=0;i--){
		if (par[i][v]!=par[i][u]){
			v=par[i][v];
			u=par[i][u];
		}
	}
	return par[0][u];
}
int gt(int now,int dest){
	int ret=0;
	while (1){
		int ID=id[now];
		if (ID==id[dest]){
			ret=max(ret,chains[ID].query(num[dest],num[now]-1));
			break;
		}
		else{
			ret=max(ret,chains[ID].query(1,num[now]-1));
			now=chains[ID].beg;
			ret=max(ret,dist[now]);
			now=par[0][now];
		}
	}
	return ret;
}
int maxuv(int u,int v){
	int tmp=lca(u,v);
//	cout<<tmp<<endl;
	return max(gt(u,tmp),gt(v,tmp));
}
int main(){
	_init(); 
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i=0;i<m;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		e.push_back(mp(w,mp(u,v)));
	}
	ee=e;
	sort(e.begin(),e.end());
	long long tot=0;
	for (int i=0;i<e.size();i++){
		int u=e[i].second.first,v=e[i].second.second;
		if (findset(u)!=findset(v)){
		//	cerr<<"use:"<<u<<' '<<v<<endl;
			Union(u,v);
			tot+=e[i].first;
			G[u].push_back(mp(v,e[i].first));
			G[v].push_back(mp(u,e[i].first)); 
		}
	}
	memset(vis,false,sizeof(vis));
	dfs(1,0);
	for (int i=1;i<=19;i++){
		for (int j=1;j<=n;j++){
			if (!par[i-1][j]){
				par[i][j]=0;
			}
			else{
				par[i][j]=par[i-1][par[i-1][j]];
			}
		}
	}
	memset(vis,false,sizeof(vis));
	chains.clear();
	Chain tmp;
	chains.push_back(tmp);
	heavy_light(1,0,1);
//	cerr<<123<<endl;
	for (int i=0;i<chains.size();i++){
		//cout<<chains[i].ver.size()<<endl;
		chains[i]._init();
	}
	//cerr<<123<<endl;
	for (int i=0;i<ee.size();i++){
		int u=ee[i].second.first,v=ee[i].second.second;
		int Md=maxuv(u,v);
		LL ans=tot;
		ans-=Md;
		ans+=ee[i].first;
		printf("%I64d\n",ans);
	}
	return 0;
}