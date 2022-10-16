#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
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
const int MAXN=1e5+10,MAXM=2e5+10;
struct Edge{int u,v;}edge[MAXM];
int first[MAXN],next[MAXM],tot;
int depth[MAXN],fa[MAXN];
db ans;
void addedge(int u,int v){
	edge[++tot]=(Edge){u,v};next[tot]=first[u];first[u]=tot;
}
int n,u,v;
void dfs(int u){
	depth[u]=depth[fa[u]]+1;
	ans+=1.00/depth[u];
	for(int j=first[u];j;j=next[j]){
		int v=edge[j].v;if(v==fa[u])continue;
		fa[v]=u;
		dfs(v);
	}
}
int main(){
	cin>>n;
	rep(i,1,n-1){
		cin>>u>>v;
		addedge(u,v);addedge(v,u);
	}
	dfs(1);
	printf("%.8f",ans);
	return 0;
}