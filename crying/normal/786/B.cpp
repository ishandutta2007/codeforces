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
const int MAXN=1e5+10,MAXM=3e6+10,LIM=8e5;
const ll INF=1e16;
struct Edge{
	int u,v,w;
}edge[MAXM];
struct Node{
	ll u,d;
	bool operator<(const Node& n2)const{return d>n2.d;}
};
priority_queue<Node>h;
int first[MAXN<<3],next[MAXM];
int n,q,s,op,v,u,l,r,w,tot;
int l1[MAXN<<2],r1[MAXN<<2],l2[MAXN<<2],r2[MAXN<<2],lc1[MAXN<<2],rc1[MAXN<<2],lc2[MAXN<<2],rc2[MAXN<<2];
int pos1[MAXN],pos2[MAXN<<2]; //i
ll dis[MAXN<<3],vis[MAXN<<3];
void addedge(int u,int v,int w){
	static int tot=0;
	edge[++tot]=(Edge){u,v,w};
	next[tot]=first[u];first[u]=tot;
}
void Build(int L,int R,int& fa1,int& fa2){
	fa1=++tot;l1[tot]=L;r1[tot]=R;if(L==R)pos1[L]=tot;
	fa2=++tot;l2[tot]=L;r2[tot]=R;if(L==R)pos2[L]=tot;
	int num1=tot-1,num2=tot;
	if(L!=R){
		int mid=(L+R)>>1;
		Build(L,mid,lc1[num1],lc2[num2]);
		Build(mid+1,R,rc1[num1],rc2[num2]);
		addedge(lc1[num1],num1,0);addedge(rc1[num1],num1,0);
		addedge(num2,lc2[num2],0);addedge(num2,rc2[num2],0);
	}
}
void update1(int x,int ql,int qr,int v,int w){
	if(ql<=l2[x] && qr>=r2[x]){
		addedge(pos2[v],x,w);
		return;
	}
	int mid=(l2[x]+r2[x])>>1;
	if(ql<=mid)update1(lc2[x],ql,qr,v,w);
	if(qr>mid)update1(rc2[x],ql,qr,v,w);
} 
void update2(int x,int ql,int qr,int v,int w){
	if(ql<=l1[x] && qr>=r1[x]){
		addedge(x,pos1[v],w);
		return;
	}
	int mid=(l1[x]+r1[x])>>1;
	if(ql<=mid)update2(lc1[x],ql,qr,v,w);
	if(qr>mid)update2(rc1[x],ql,qr,v,w);
} 
void dij(){
	rep(i,1,LIM)dis[i]=INF;
	dis[pos2[s]]=0;
	h.push((Node){pos2[s],0});
	while(h.size()){
		Node node=h.top();h.pop();
		int u=node.u;
		if(vis[u])continue;
		vis[u]=1;
		for(int j=first[u];j;j=next[j]){
			int v=edge[j].v;
			if(dis[v]>dis[u]+edge[j].w){
				dis[v]=dis[u]+edge[j].w;
				h.push((Node){v,dis[v]});
			}
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&q,&s);
	// 
	Build(1,n,lc1[0],lc2[0]);
	rep(i,1,n){
		addedge(pos1[i],pos2[i],0);
		addedge(pos2[i],pos1[i],0);
	}
	rep(i,1,q){
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d%d",&v,&u,&w);
			addedge(pos1[v],pos2[u],w);addedge(pos2[v],pos1[u],w);
		}else if(op==2){
			scanf("%d%d%d%d",&v,&l,&r,&w); // 
			update1(2,l,r,v,w);
		}else{
			scanf("%d%d%d%d",&v,&l,&r,&w); // 
			update2(1,l,r,v,w);
		}
	}
	//pos2[s]pos2[i] 
	dij();
	rep(i,1,n){
		printf("%lld ",(dis[pos2[i]]==INF)?-1:dis[pos2[i]]);
	}
	return 0;
}