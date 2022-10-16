#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=3e5+10,INF=1e9;
int n,a[MAXN],b[MAXN],leaf[MAXN<<1],tag[MAXN<<3],pre[MAXN<<3],idx[MAXN<<3];
int ed,d=INF;
vector<pi>e[MAXN<<3];
int dis[MAXN<<3],vis[MAXN<<3];
deque<int>q;
vector<int>path;
struct Seg{
	void build(int x,int l,int r){
		dis[x]=INF;
		if(l==r){leaf[l]=x;return;}
		int mid=(l+r)>>1; 
		build(lc(x),l,mid);build(rc(x),mid+1,r);
		e[x].pb(mp(lc(x),0));
		e[x].pb(mp(rc(x),0));
	} 
	void add(int x,int l,int r,int ql,int qr,int u){
		if(ql<=l && qr>=r){
			e[u].pb(mp(x,1));
			return;
		}
		int mid=(l+r)>>1;
		if(ql<=mid)add(lc(x),l,mid,ql,qr,u);
		if(qr>mid)add(rc(x),mid+1,r,ql,qr,u);
	} 
}tree;
void bfs(){
	dis[leaf[n]]=0;
	q.pb(leaf[n]);
	while(q.size()){
		int u=q.front();q.pop_front();
		for(auto edge:e[u]){
			int v=edge.fr,w=edge.se;
			if(dis[v]<=dis[u]+w)continue;
			pre[v]=u;
			dis[v]=dis[u]+w;
			if(w==1)q.pb(v);
			else q.push_front(v);
		}
	}
}
void solve(int u){
	if(u==leaf[n])return;
	if(idx[u])path.pb(idx[u]);
	solve(pre[u]);
}
int main(){
	cin>>n;
	rep(i,1,n)cin>>a[i];
	rep(i,1,n)cin>>b[i];
	tree.build(1,1,n<<1);
	rep(i,1,n)e[leaf[n+i]].pb(mp(leaf[i+b[i]],0));
	rep(i,1,n)tree.add(1,1,n<<1,n+i-a[i],n+i,leaf[i]);
	rep(i,1,n)if(a[i]==i)tag[leaf[i]]=1;
	bfs();
	rep(i,1,n)if(tag[leaf[i]]){
		if(d>dis[leaf[i]]+1){
			d=dis[leaf[i]]+1;
			ed=leaf[i];
		}
	}
	rep(i,1,n)idx[leaf[i+n]]=i;
	if(d==INF){
		printf("-1\n");return 0;
	}
	printf("%d\n",d);
	path.pb(0);
	solve(ed);
	reverse(path.begin(),path.end());
	for(auto u:path)printf("%d ",u);
	return 0;
}