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
const ll MAXN=5e5+10,INF=1e18;
ll n,u,v,f[MAXN],depth[MAXN],b[MAXN],now;
vector<int>e[MAXN];
void dfs(int u,int fa){
	int flag=0;
	depth[u]=depth[fa]+1;
	for(auto v:e[u]){
		if(v==fa)continue;
		dfs(v,u);
		flag=1;
	}
	if(!flag){
		b[++now]=depth[u];
	}
}
int main(){
	cin>>n;
	rep(i,1,n-1){
		cin>>u>>v;
		e[u].pb(v);e[v].pb(u);
	}
	ll ans=-INF;
	for(auto v:e[1]){
		now=0;
		dfs(v,1);
		sort(b+1,b+1+now);
		rep(i,2,now){
			b[i]=max(b[i],b[i-1]+1);
		}
		ans=max(ans,b[now]);
	}
	cout<<ans;
	
	return 0;
}