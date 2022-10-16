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
int T,n,k[MAXN],deg[MAXN],topo[MAXN],tot,f[MAXN];
vector<int>e[MAXN];
queue<int>q;
void solve(){
	scanf("%d",&n);
	tot=0;
	while(q.size())q.pop();
	rep(i,1,n){
		e[i].clear();
		deg[i]=0;
		f[i]=0;
	}
	rep(i,1,n){
		scanf("%d",&k[i]);
		rep(j,1,k[i]){
			int v;scanf("%d",&v);
			e[v].pb(i);deg[i]++;
		}
	}
	rep(i,1,n){
		if(!deg[i]){
			q.push(i);
			topo[++tot]=i;
		}
	}
	while(q.size()){
		int u=q.front();q.pop();
		for(auto v:e[u]){
			deg[v]--;
			if(!deg[v]){
				q.push(v);
				topo[++tot]=v;
			}
		}
	}
	if(tot!=n){
		printf("-1\n");return;
	}
	int ans=0;
	rep(i,1,n){
		int u=topo[i];
		f[u]=max(f[u],1);
		ans=max(ans,f[u]);
		for(auto v:e[u]){
			if(v>u)f[v]=max(f[v],f[u]);
			else f[v]=max(f[v],f[u]+1);
		}
	}
	printf("%d\n",ans);
}
int main(){
	scanf("%d",&T);
	while(T--){
		solve();
	}

	return 0;
}