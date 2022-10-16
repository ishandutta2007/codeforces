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
const int MAXN=2e5+10,MAXM=20;
int T,n,m,u,v,depth[MAXN],l,tag[MAXM];
int p[MAXN];
vector<int>e[MAXN];
vector<int>x,y;
int h[MAXN];
void dfs(int u,int fa){
	depth[u]=depth[fa]+1;
	if(odd(depth[u]))l++;
	for(auto v:e[u]){
		if(v==fa)continue;
		dfs(v,u);
	}
}
void solve(){
	x.clear();y.clear();
	memset(tag,0,sizeof tag);
	scanf("%d",&n);
	rep(i,1,n)e[i].clear();
	rep(i,1,n-1){
		scanf("%d%d",&u,&v);
		e[u].pb(v);e[v].pb(u);
	}
	l=0;
	dfs(1,0);
	rep(j,0,19)if((1<<j)<=n)m=j;
	int rest=n-(1<<m)+1;
	if(l>=(1<<m))l-=rest,tag[m]=1;
	rep(i,0,m-1){
		if(l>>i&1)tag[i]=1;
	}
	rep(i,1,n){
		if(tag[h[i]])x.pb(i);
		else y.pb(i);
	}
	rep(i,1,n){
		if(odd(depth[i])){
			p[i]=x.back();
			x.pop_back();
		}else{
			p[i]=y.back();
			y.pop_back();
		}
	}
	rep(i,1,n)printf("%d ",p[i]);printf("\n");
}
int main(){
	rep(i,1,2e5){
		rep(j,0,19){
			if(i>>j&1)h[i]=j;
		}
	}
	scanf("%d",&T);
	while(T--){
		solve();
	}

	return 0;
}