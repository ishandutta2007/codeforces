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
#define mapit map<int,int>::iterator
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=1e5+10,MAXM=2e5+10;
int n,rt,u,v;
struct Edge{
	int u,v;
}edge[MAXM];
int first[MAXN],next[MAXM],tot;
int dep[MAXN],ans1[2],size[MAXN],ans2;
il void addedge(int u,int v){
	edge[++tot].u=u;edge[tot].v=v;
	next[tot]=first[u];first[u]=tot;
}
void dfs1(int u,int fa){
	size[u]=1;
	for(int j=first[u];j;j=next[j]){
		int v=edge[j].v;
		if(v==fa)continue;
		dep[v]=dep[u]+1;
		dfs1(v,u);
		size[u]+=size[v];
	}
	if(size[u]==1)ans1[dep[u]&1]=1;
}
void dfs2(int u,int fa){
	int flag=0;
	for(int j=first[u];j;j=next[j]){
		int v=edge[j].v;
		if(v==fa)continue;
		if(size[v]>1){
			ans2++;
			dfs2(v,u);
		}else flag=1;
	}
	ans2+=flag;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n-1){
		scanf("%d%d",&u,&v);
		addedge(u,v);addedge(v,u);
	}
	rep(i,1,n)if(next[first[i]]){rt=i;break;} //rt
	dfs1(rt,rt);
	if(ans1[0] && ans1[1])printf("3 ");
	else printf("1 ");
	dfs2(rt,rt);printf("%d ",ans2);
	return 0;
}