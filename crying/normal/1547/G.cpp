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
const int MAXN=4e5+10,MAXM=8e5+10;
struct Edge{
	int u,v;
};
struct Graph{
	Edge edge[MAXM];
	int first[MAXN],next[MAXM],tot,q[MAXN];
	int ru[MAXN]; // 
}old,now;
int n,m,u,v,T;
int st[MAXN],ins[MAXN],vis[MAXN],scc[MAXN],num[MAXN],cnt,top,dfn[MAXN],low[MAXN],tot;
int topo[MAXN],f[MAXN],tag[MAXN],tag2[MAXN],tag3[MAXN];
int ans = 0;
queue<int>q;
inline void addedge(Graph& g,int u,int v){
	g.tot++;
	g.edge[g.tot].u = u;g.edge[g.tot].v = v;
	g.next[g.tot] = g.first[u];
	g.first[u] = g.tot;
}
void tarjan(int u){
	dfn[u] = low[u] = ++tot;
	vis[u] = ins[u] = 1;
	st[++top] = u;
	for(int j=old.first[u];j;j=old.next[j]){
		int v = old.edge[j].v;
		if(!vis[v]){
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}else if(ins[v]){
			low[u] = min(low[u],low[v]);
		}
	} 
	if(dfn[u] == low[u]){
		cnt++;
		while(1){
			num[cnt]++;
			int now = st[top];
			top--;
			scc[now] = cnt;
			ins[now] = 0;
			if(now == u)return; 
		}
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		rep(i,0,n){
			old.first[i]=now.first[i]=0;	
		}
		rep(i,0,old.tot){
			old.next[i]=0;
		}
		rep(i,0,now.tot){
			now.next[i]=0;
		}
		old.tot=now.tot=0;
		cnt++;
		rep(i,1,n){
			vis[i]=low[i]=dfn[i]=ins[i]=num[i]=0;
		}
		top=tot=0;
		rep(i,1,n)f[i]=tag[i]=tag2[i]=tag3[i]=0;
		for(int i=1;i<=m;i++){
			scanf("%d%d",&u,&v);
			if(u==v)tag2[u]=1;
			addedge(old,u,v);
		}
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				tarjan(i);
			}
		}
		for(int i=1;i<=n;i++){
			int idx = scc[i];
			for(int j=old.first[i];j;j=old.next[j]){
				int v = old.edge[j].v;
				int idxv = scc[v];
				if(idxv != idx){
					now.ru[idxv]++;
					addedge(now,idx,idxv); 
				}
			}
		}
		rep(i,1,n)tag3[scc[i]]|=tag2[i];
		while(q.size())q.pop();
		if(num[scc[1]]>1 || tag3[scc[1]]){
			f[scc[1]]=-1;
		}else{
			f[scc[1]]=1;
		}
		rep(i,1,n){
			if(tag[scc[i]])continue;
			if(now.ru[scc[i]]==0){
				q.push(scc[i]);
				tag[scc[i]]=1;
			}
		}
		while(q.size()){
			int u=q.front();q.pop();
			for(int j=now.first[u];j;j=now.next[j]){
				int v=now.edge[j].v;if(tag[v])continue;
				if(f[v]!=-1){
					if(f[u]==-1){
						f[v]=-1;
					}else{
						f[v]=Min(2,f[v]+f[u]); 
					}
				}
				now.ru[v]--;
				if(!now.ru[v]){
					q.push(v);
					if(f[v]!=0 && (tag3[v] || num[v]>1)){
						f[v]=-1;
					}
					tag[v]=1;
				}
			}
		}
		rep(i,1,n){
			printf("%d ",f[scc[i]]);
		}
		printf("\n");
	}
	return 0;
}