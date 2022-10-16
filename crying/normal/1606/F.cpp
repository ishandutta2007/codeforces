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
const int MAXN=2e5+10;
int n,q,f[MAXN];
int L[MAXN],R[MAXN],tot;
ll sum[MAXN],sz[MAXN];
int fa[MAXN],vis[MAXN];
vector<int>e[MAXN];
struct Qry{
	int v,k,idx;ll ans;
}qry[MAXN];
struct BIT{
	ll tree[MAXN];
	void update(int x,ll val){for(;x<=n;x+=lowbit(x))tree[x]+=val;}
	ll query(int x){ll ret=0;for(;x;x-=lowbit(x))ret+=tree[x];return ret;}
	ll query(int L,int R){return query(R)-query(L-1);}
}t1,t2; 
struct Node{
	ll val;int idx;
	bool operator<(const Node& n2)const{return val<n2.val;}
};
priority_queue<Node>pq;
bool cmp1(const Qry& q1,const Qry& q2){return q1.k>q2.k;}
bool cmp2(const Qry& q1,const Qry& q2){return q1.idx<q2.idx;}
int Find(int x){
	if(fa[x]==x)return x;
	return fa[x]=Find(fa[x]);
}
void Merge(int x,int y){if(Find(x)==Find(y))return;fa[Find(x)]=Find(y);}
ll D(ll x,ll y){if(y<0)x=-x,y=-y;return (x<0)?(-((-x+y-1)/y)):(x/y);}
void dfs(int u){
	L[u]=++tot;
	for(auto v:e[u]){if(v==f[u])continue;
		f[v]=u;dfs(v);sum[u]++;
	}
	R[u]=tot;
}
void solve(){
	dfs(1);
	rep(i,1,n){fa[i]=i;sz[i]=1;}
	rep(i,1,n){pq.push((Node){D(sum[i]-sz[i],sz[i]),i});}
	rep(i,1,q){
		Qry& now=qry[i];
		while(pq.size()){
			Node cur=pq.top();if(cur.val<now.k)break;
			pq.pop();
			if(vis[cur.idx])continue;
			vis[cur.idx]=1;
			if(cur.idx==1)continue;
			Merge(cur.idx,f[cur.idx]);
			int top=Find(cur.idx);
			ll nsz=sz[cur.idx]+t1.query(L[cur.idx],R[cur.idx]);
			ll nsum=sum[cur.idx]+t2.query(L[cur.idx],R[cur.idx]);
			t1.update(L[f[cur.idx]],nsz);
			if(f[top])t1.update(L[f[top]],-nsz);
			t2.update(L[f[cur.idx]],nsum);
			if(f[top])t2.update(L[f[top]],-nsum);
			if(vis[top])continue;
			nsz=sz[top]+t1.query(L[top],R[top]);
			nsum=sum[top]+t2.query(L[top],R[top]);
			pq.push((Node){D(nsum-nsz,nsz),top});
		}
		int u=now.v;
		ll nsz=sz[u]+t1.query(L[u],R[u]);
		ll nsum=sum[u]+t2.query(L[u],R[u]);
		now.ans=nsum-nsz*now.k+now.k-nsz+1;
	}
}
int main(){
	scanf("%d",&n);
	rep(i,1,n-1){
		int u,v;scanf("%d%d",&u,&v);
		e[u].pb(v);e[v].pb(u);
	}
	scanf("%d",&q);
	rep(i,1,q){
		scanf("%d%d",&qry[i].v,&qry[i].k);
		qry[i].idx=i;
	}
	sort(qry+1,qry+1+q,cmp1);
	solve();
	sort(qry+1,qry+1+q,cmp2);
	rep(i,1,q){
		printf("%lld\n",qry[i].ans);
	}

	return 0;
}