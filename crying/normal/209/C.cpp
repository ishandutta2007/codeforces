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
const int MAXN=1e6+10,MAXM=2e6+10;
struct Edge{
	int u,v;
}edge[MAXM];
int n,m,u,v;
int first[MAXN],next[MAXM],tot;
int fa[MAXN],size[MAXN];
int vis[MAXN],sccnt,num,ans;
vector<int>V;
void addedge(int u,int v){
	edge[++tot]=(Edge){u,v};
	next[tot]=first[u];first[u]=tot;
}
int Find(int x){if(fa[x]==x)return x;return fa[x]=Find(fa[x]);}
void Merge(int x,int y){fa[Find(x)]=Find(y);}
int Alone(int x){return size[x]==0;}
void dfs(int u){
	vis[u]=1;V.pb(u);
	for(int j=first[u];j;j=next[j]){
		int v=edge[j].v;if(vis[v])continue;
		dfs(v);
	}
}
void solve(){
	int cnt=0;
	for(vit it=V.begin();it!=V.end();it++){
		cnt+=odd(size[*it]);
	}
	ans+=Max(0,cnt/2);
	num+=(bool)(!cnt);
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n){
		fa[i]=i;
	}
	rep(i,1,m){
		scanf("%d%d",&u,&v);addedge(u,v),addedge(v,u);
		Merge(u,v);size[u]++;size[v]++;
	}
	sccnt++;dfs(1);solve();
	rep(i,2,n){
		if(Alone(i))continue;
		if(vis[i])continue;sccnt++;
		V.clear(); 
		dfs(i);
		solve();
	}
	//
	if(sccnt>1)ans+=num;
	printf("%d",ans); 
	return 0;
}