#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned int uint;
#define pb push_back
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2) EOF:*p1++)
//char buf[1<<21],*p1=buf,*p2=buf;
#define int long long
inline int read() {
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=x*10+(ch^48),ch=getchar();
	return x*f;
}
const int N=20010;
const int M=(200000+N*2)*2;
const int inf=1e14;
int n,m,S,T,sum;
int head[N],num_edge=1;
int dep[N],cur[N],maxflow;
struct edge {
    int nxt,val,to;
}e[M];
struct node{
	int u,v,w;
}a[M];
void adde(int fr,int to,int val) {
    ++num_edge;
    e[num_edge].nxt=head[fr];
    e[num_edge].to=to;
    e[num_edge].val=val;
    head[fr]=num_edge;
}
void addedge(int fr,int to,int val){
	adde(fr,to,val),adde(to,fr,0);
}
bool bfs(){
    for(int i=1;i<=T;++i)dep[i]=0,cur[i]=head[i];
    dep[S]=1;queue<int>q;q.push(S);
    while(!q.empty()) {
        int u=q.front();q.pop();
        for(int i=head[u];i;i=e[i].nxt) {
            int v=e[i].to;
            if(!dep[v]&&e[i].val)
                dep[v]=dep[u]+1,q.push(v);
        }
    }
    return dep[T]>0;
}
int dfs(int u,int flow) {
    if(u==T){maxflow+=flow;return flow;}
    int used=0,rlow;
    for(int i=cur[u];i;i=e[i].nxt) {
        int v=e[i].to;cur[u]=i;
        if(e[i].val&&dep[v]==dep[u]+1) {
            rlow=dfs(v,min(e[i].val,flow-used));
            if(rlow) {
                used+=rlow;
                e[i].val-=rlow;
                e[i^1].val+=rlow;
                if(used==flow)break;
            }
        }
    }
    return used;
}
inline bool cmp(const node&a,const node&b){
	return a.w<b.w;
}
bool check(int k){
	for(int i=1;i<=T;++i)head[i]=0;num_edge=1,maxflow=0;
	for(int i=1;i<=m&&a[i].w<=k;++i)addedge(a[i].u,a[i].v+n,a[i].w);
	for(int i=1;i<=n;++i)addedge(S,i,1);
	for(int i=1;i<=n;++i)addedge(i+n,T,1);
	while(bfs())dfs(S,inf);
	return maxflow==n;
}
signed main() {
	n=read(),m=read(),S=n+n+1,T=S+1;
	for(int i=1;i<=m;++i)a[i].u=read(),a[i].v=read(),a[i].w=read();
	sort(a+1,a+m+1,cmp);
	int l=1,r=m,ans=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(a[mid].w))ans=a[mid].w,r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}