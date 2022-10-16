#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
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
const int MAXN=5e3+10,MAXM=1e4+10,INF=1e6;
struct Edge{
	int u,v,w;
}edge[MAXM];
int first[MAXN],next[MAXM],tot;
int n,m,u,v,a[MAXN],b[MAXN],k[MAXN];
int f[MAXN][MAXN]; //f(i,j) ij->fa[j] 
void addedge(int u,int v){
	edge[++tot].u=u;edge[tot].v=v;edge[tot].w=-INF;
	next[tot]=first[u];first[u]=tot;
}
void dfs(int u,int idx){
	for(int j=first[u];j;j=next[j]){
		int v=edge[j].v;
		if(v==edge[f[idx][u]].v)continue;
		f[idx][v]=op(j);
		dfs(v,idx);
	}
}
void Update(int x,int y,int k){
	int t=y;
	while(t!=x){
		int val=Max(k,edge[f[x][t]].w);
		edge[f[x][t]].w=edge[op(f[x][t])].w=val;
		t=edge[f[x][t]].v;
	}
}
void Check(int x,int y,int k){
	int t=y;
	while(t!=x){
		int val=edge[f[x][t]].w;
		if(val==k)return;
		t=edge[f[x][t]].v;
	}
	printf("-1\n");
	exit(0);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n-1){
		scanf("%d%d",&u,&v);
		addedge(u,v);addedge(v,u);
	}
	rep(i,1,n){
		dfs(i,i);
	}
	scanf("%d",&m);
	rep(i,1,m){
		scanf("%d%d%d",&a[i],&b[i],&k[i]);
		Update(a[i],b[i],k[i]);
	}
	rep(i,1,m){
		Check(a[i],b[i],k[i]);
	} 
	rep(i,1,tot){
		if((i&1)==0)continue;
		int val=(edge[i].w==-INF)?INF:edge[i].w;
		printf("%d ",val);
	}
	return 0;
}