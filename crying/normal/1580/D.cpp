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
const ll MAXN=4010,INF=1e18;
int n,m,a[MAXN];
int st[MAXN],top;
int root,lc[MAXN],rc[MAXN];
int sz[MAXN];
ll f[MAXN][MAXN],ans;
void build(){
	rep(i,1,n){
		int j=0;
		while(top && a[st[top]]>a[i]){
			j=st[top];top--;
		}
		if(!top)root=i;
		else rc[st[top]]=i;
		lc[i]=j;
		st[++top]=i;
	}	
}
void dfs1(int u){
	if(!u)return;
	sz[u]=1;
	dfs1(lc[u]);dfs1(rc[u]);
	sz[u]+=sz[lc[u]];sz[u]+=sz[rc[u]];
}
void dfs2(int u){
	if(!u)return;
	dfs2(lc[u]);dfs2(rc[u]);
	rep(i,0,min(m,sz[lc[u]])){
		rep(j,0,min(m-i,sz[rc[u]])){
			f[u][i+j]=max(f[u][i+j],f[lc[u]][i]+f[rc[u]][j]-(ll)i*j*2*a[u]);
		}
	}
	per(i,m,1){
		f[u][i]=max(f[u][i],f[u][i-1]+(ll)(m-1)*a[u]-(ll)(i-1)*2*a[u]);
	}
	
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&a[i]);
	build();
	rep(i,1,n)rep(j,1,m)f[i][j]=-INF;
	dfs1(root);
	dfs2(root);
	rep(i,1,n)ans=max(ans,f[i][m]);
	printf("%lld\n",ans);
	return 0;
}