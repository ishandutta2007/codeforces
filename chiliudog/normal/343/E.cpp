#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long int64;
#define mk(a,b) make_pair(a,b)
#define w1 first
#define w2 second
typedef pair<int,int> pin;
const int maxn=205,maxm=1005;
int n,m;
int head[maxn],t[maxm<<1],ne[maxm<<1],sap[maxm<<1];
int num,st[maxm],ed[maxm],v[maxm];
int d[maxn],his[maxn],cnt[maxn],cur[maxn],S,T,pre[maxn],edge[maxn];
inline void addedge(int x,int y,int z){
	ne[++num]=head[x];head[x]=num;t[num]=y;sap[num]=z;
	ne[++num]=head[y];head[y]=num;t[num]=x;sap[num]=z;
}
const int inf=1<<29;
inline int isap(){
	rep(i,1,n)d[i]=0,cnt[i]=0,cur[i]=head[i];cnt[0]=n;
	int i=S,aug=inf,ans=0,minnum,jl;
	while(d[S]<n){
		bool flag=0;his[i]=aug;for(int j=cur[i];j!=-1;j=ne[j])if(d[t[j]]+1==d[i]&&sap[j]){
			flag=1;pre[t[j]]=i;edge[i]=j;cur[i]=j;aug=min(aug,sap[j]);i=t[j];
			if(i==T){
				ans+=aug;
				while(i!=S){i=pre[i];sap[edge[i]]-=aug;sap[edge[i]^1]+=aug;}
				aug=inf;
			}break;
		}if(flag)continue;minnum=n;forE(j,i)if(sap[j]&&d[t[j]]<minnum)minnum=d[t[j]],jl=j;
		cnt[d[i]]--;if(cnt[d[i]]==0)return ans;d[i]=minnum+1;cnt[d[i]]++;cur[i]=jl;
		if(i!=S){i=pre[i];aug=his[i];}
	}return ans;
}
int fa[maxn],fl[maxn];
int Queue[maxn];bool vis[maxn];
inline void bfs(int x){
	memset(vis,0,sizeof(vis));int front=0,finish=0;
	Queue[++finish]=x;vis[x]=1;while(front!=finish){
		int x=Queue[++front];forE(i,x)if(sap[i]&&!vis[t[i]])vis[Queue[++finish]=t[i]]=1;
	}
}
inline void buildtree(){
	rep(i,2,n)fa[i]=1;
	rep(i,2,n){
		num=1;rep(j,1,n)head[j]=-1;
		rep(j,1,m)addedge(st[j],ed[j],v[j]);
		S=i;T=fa[i];
		fl[i]=isap();bfs(i);
		rep(x,i+1,n)if(fa[x]==fa[i]&&vis[x])fa[x]=i;
	}
}
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}
typedef pair<int,pair<int,int> > ee;
ee e[maxn];
int ans=0,tot=0;
int a[maxn];
int maxi=inf,sp,eq;
inline void dfs(int x,int fa){
	forE(i,x)if(t[i]!=fa&&!vis[t[i]]){
		if(sap[i]<maxi){maxi=sap[i];sp=x;eq=t[i];}dfs(t[i],x);
	}
}
inline void calc(int x){
	maxi=inf;dfs(x,-1);
//	cerr<<'!'<<x<<endl;
	if(maxi==inf){
		a[++tot]=x;return;
	}
	int fir=sp,snd=eq;
//	cerr<<fir<<' '<<snd<<endl;
	vis[snd]=1;
	calc(fir);vis[snd]=0;vis[fir]=1;
	calc(snd);
}
inline void calc(){
	rep(i,2,n)e[i-1]=mk(fl[i],mk(fa[i],i)),ans+=fl[i];
	rep(i,1,n)head[i]=-1;num=0;
	rep(i,2,n)addedge(fa[i],i,fl[i]);
	printf("%d\n",ans);memset(vis,0,sizeof(vis));
	calc(1);
	rep(i,1,n)printf("%d ",a[i]);
}
int main(){
 //   judge();
    read(n);read(m);
    rep(i,1,m)read(st[i]),read(ed[i]),read(v[i]);
    buildtree();
    calc();
    return 0;
}