#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
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
struct Edge{
	int u,v;
}edge[MAXM];
int first[MAXN],next[MAXM],tot;
int n;
ll size[MAXN],fa[MAXN],ans,u,v;
ll C(ll n){
	return n*(n-1)/2; //C(n,2)
}
void addedge(int u,int v){
	edge[++tot].u=u;edge[tot].v=v;
	next[tot]=first[u];first[u]=tot;
}
void dfs(int u){
	size[u]=1;
	ll sum1=0,sum2=0;
	for(int j=first[u];j;j=next[j]){
		int v=edge[j].v;
		if(v==fa[u])continue;
		fa[v]=u;dfs(v);
		size[u]+=size[v];
		sum2-=C(size[v]);
	}
	sum1=(n-size[u])*size[u];
	sum2+=C(size[u]);
	ans-=sum2*sum2;
	ans-=sum2*sum1*2;
}
int main(){
	cin>>n;
	rep(i,1,n-1){
		cin>>u>>v;
		addedge(u,v),addedge(v,u);
	}
	ans=C(n)*C(n);
	dfs(1);
	cout<<ans;
	return 0;
}