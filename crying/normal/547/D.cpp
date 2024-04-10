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
#define C(x) (x+200000)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=1e6+10,MAXM=2e6+10;
struct Edge{
	int u,v,w,tag;
}edge[MAXM];
int first[MAXN],next[MAXM],tot;
int n,m,x[MAXN],y[MAXN];
int size[MAXN],vis[MAXN];
vector<int>V;
int ans[MAXN];
void addedge(int u,int v,int w){
	edge[++tot]=(Edge){u,v,w,0};next[tot]=first[u];first[u]=tot;
}
int alone(int i){return !size[i];} 
void dfs(int u){
	vis[u]=1;V.pb(u);
	for(int j=first[u];j;j=next[j]){
		int v=edge[j].v;
		if(vis[v])continue;
		dfs(v);
	}
}
void Eular(int u){
	for(int& j=first[u];j;j=next[j]){
		if(edge[j].tag)continue;
		int v=edge[j].v;
		if(u<=2e5 && edge[j].w>0)ans[edge[j].w]=1;
		edge[j].tag=edge[op(j)].tag=1;
		Eular(v);
	}
}
void solve(){
	int pre=0;
	for(vit it=V.begin();it!=V.end();it++){
		int v=*it;
		if(even(size[v]))continue;
		if(!pre){
			pre=v;
		}else{
			addedge(v,pre,-1),addedge(pre,v,-1);
			pre=0; 
		}
	}
	Eular(V[0]);
} 
int main(){
	n=4e5;
	cin>>m;
	rep(i,1,m){
		cin>>x[i]>>y[i];addedge(x[i],C(y[i]),i);addedge(C(y[i]),x[i],i);
		size[x[i]]++;size[C(y[i])]++;
	}
	rep(i,1,n){
		if(alone(i))continue;
		if(vis[i])continue;
		V.clear();
		dfs(i);
		solve();
	}
	rep(i,1,m){
		if(ans[i])printf("r");
		else printf("b");
	}
	return 0;
}