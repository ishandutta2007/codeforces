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
const ll MAXN=1e6+10,MAXM=1e6+10,INF=1e18;
ll n,m,tot,xorsum;
struct Edge{
	ll u,v,w;
	bool operator<(const Edge& e2)const{return w<e2.w;}
}edge[MAXM],rev[MAXM];
map<int,int>e[MAXN]; 
int fa[MAXN];
int Find(int x){
	if(fa[x]==x)return fa[x];
	return fa[x]=Find(fa[x]);
}
int Merge(int x,int y){
	fa[Find(x)]=Find(y);
}
ll ans=INF,vis[MAXN];
vector<int>V[MAXN];
set<int>s;
sit dfs(int u){
	vis[u]=1;s.erase(u);V[tot].pb(u);
	sit it=s.begin();
	while(it!=s.end()){
		int v=*it;if(e[u][v]){it++;continue;} 
		it=dfs(v);
	}
	return s.upper_bound(u);
}
int main(){
	cin>>n>>m;
	rep(i,1,m){
		cin>>edge[i].u>>edge[i].v>>edge[i].w;xorsum^=edge[i].w;
		e[edge[i].u][edge[i].v]=e[edge[i].v][edge[i].u]=1;
	}
	sort(edge+1,edge+1+m);
	if((n-1)*n/2-m<n){
		//(n<=10^3)
		rep(i,1,n){
			rep(j,i+1,n){
				if(e[i][j])continue;
				rev[++tot]=(Edge){i,j,0};
			}
		}
		//revx
		rep(i,1,tot){
			ll cost=0;
			rep(j,1,n)fa[j]=j;
			rep(j,1,tot){
				if(j==i)continue;
				int u=rev[j].u,v=rev[j].v;if(Find(u)==Find(v))continue;
				Merge(u,v);
			} 
			int flag=0;
			rep(j,1,m){
				if(!flag && xorsum<=edge[j].w){
					int u=rev[i].u,v=rev[i].v;
					if(Find(u)!=Find(v))Merge(u,v),cost+=xorsum;
					flag=1;
				}
				int u=edge[j].u,v=edge[j].v;
				if(Find(u)!=Find(v))Merge(u,v),cost+=edge[j].w;
			} 
			if(!flag){
				int u=rev[i].u,v=rev[i].v;
				if(Find(u)!=Find(v))Merge(u,v),cost+=xorsum;
			}
			ans=Min(ans,cost);
		} 
		return printf("%lld",ans),0;
	}
	ans=0;
	//
	rep(i,1,n)fa[i]=i;
	rep(i,1,n)s.is(i);
	rep(i,1,n){if(vis[i])continue;
		tot++;dfs(i);
	}
	rep(i,1,tot){
		int size=V[i].size();
		rep(j,1,size-1)Merge(V[i][j],V[i][0]);
	}
	rep(i,1,m){
		int u=edge[i].u,v=edge[i].v;
		if(Find(u)!=Find(v)){Merge(u,v);ans+=edge[i].w;}
	}
	return printf("%lld",ans),0;
}