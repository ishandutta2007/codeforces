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
int T,n,ans,cnt[MAXN];
vector<int>e[MAXN];
void dfs(int u,int fa){
	for(auto v:e[u]){
		if(v==fa)continue;
		dfs(v,u);
		if(cnt[v]==0)cnt[u]++;
	}
}
void solve(){
	ans=0;
	cin>>n;
	rep(i,1,n)e[i].clear(),cnt[i]=0;
	rep(i,1,n-1){
		int u,v;cin>>u>>v;
		e[u].pb(v);e[v].pb(u);
	}
	dfs(1,0);
	ans=cnt[1];
	rep(i,2,n){
		if(cnt[i]!=0){
			if(ans)ans+=cnt[i]-1;
			else ans+=cnt[i];	
		}
	}
	printf("%d\n",ans);
}
int main(){
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}