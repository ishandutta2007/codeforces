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
const int MAXN=2e5+10,MAXM=4e5+10;
ll T,n,m,a[MAXN],b[MAXN],t[MAXN],u[MAXN],v[MAXN],fa[MAXN];
ll color[MAXN],vis[MAXN],sz[MAXN],tag[MAXN];
struct Edge{ll v;}edge[MAXM];
ll first[MAXN],next[MAXM],tot;
vector<int>B,W;
void addedge(ll u,ll v){
	edge[++tot]=(Edge){v};next[tot]=first[u];first[u]=tot;
}
void Reset(){
	memset(first,0,sizeof first);memset(next,0,sizeof next);memset(edge,0,sizeof edge);tot=0;
	memset(color,0,sizeof color);memset(vis,0,sizeof vis);memset(tag,0,sizeof tag);
	rep(i,1,n){fa[i]=i;sz[i]=1;}
}
ll Find(ll x){
	if(fa[x]==x)return x;
	return fa[x]=Find(fa[x]);
}
void Merge(ll x,ll y){
	if(Find(x)==Find(y))return;
	a[Find(x)]+=a[Find(y)];b[Find(x)]+=b[Find(y)];sz[Find(x)]+=sz[Find(y)];fa[Find(y)]=Find(x);	
}
bool dfs(int u,int c,int idx){
	if(vis[u])return color[u]==c;
	vis[u]=1;color[u]=c;
	if(c==1)B.pb(u);else W.pb(u);
	int flag=true;
	for(int j=first[u];j;j=next[j]){
		int v=edge[j].v;
		if(!dfs(v,-c,idx))flag=false;
	}
	return flag;
}
int main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld",&n,&m);Reset();
		rep(i,1,n){scanf("%lld",&a[i]);}
		rep(i,1,n){scanf("%lld",&b[i]);}
		rep(i,1,m){
			scanf("%lld%lld",&u[i],&v[i]);
			t[i]=1;
			if(t[i]==1){
				if(u[i]==v[i])tag[i]=1;
			}
			else{
				Merge(u[i],v[i]);
			}
		}
		rep(i,1,m)if(t[i]==1){
			if(u[i]!=v[i])tag[Find(u[i])]=tag[Find(v[i])]=2;
			addedge(Find(u[i]),Find(v[i])),addedge(Find(v[i]),Find(u[i]));
		}
		rep(i,1,m){if(i!=Find(i))continue;
			if(tag[i]==1 && sz[i]==1){
				// 
				ll d=abs(a[i]-b[i]);
				if(d%2)goto FAIL;
			}
		}
		rep(i,1,n){if(vis[Find(i)])continue;
			//
			B.clear();W.clear();
			if(dfs(Find(i),1,i)){
				//
				if(!B.size() || !W.size()){
					if(a[Find(i)]!=b[Find(i)])goto FAIL;
					continue;
				}
				rep(j,1,B.size()-1)Merge(B[0],B[j]);
				rep(j,1,W.size()-1)Merge(W[0],W[j]);
				ll u=Find(B[0]),v=Find(W[0]);
				if(a[u]-b[u] != a[v]-b[v])goto FAIL;	
			}else{
				//
				if(B.size())rep(j,0,B.size()-1)Merge(i,B[j]);
				if(W.size())rep(j,0,W.size()-1)Merge(i,W[j]);
				if(abs(a[Find(i)]-b[Find(i)])%2){
					goto FAIL;
				}
			}
		} 
		printf("YES\n");continue;
		FAIL:printf("NO\n");
	}
	return 0;
}