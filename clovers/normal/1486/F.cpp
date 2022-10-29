//LCALCA
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pre(i,a,b) for(int i=a;i>=b;i--)
#define N 300005
using namespace std;
int n,m,h[N],tot,d[N],f[N][20],t,dfn[N],idx,c[N],sz[N],u[N],v[N];long long ans=0;
struct edge{int to,nxt;}e[N<<1];
inline void adde(int x,int y){e[++tot].nxt=h[x];h[x]=tot;e[tot].to=y;}
inline void add(int x,int y){for(;x<=n;x+=x&-x)c[x]+=y;}
inline int ask(int x){int sum=0;for(;x;x-=x&-x)sum+=c[x];return sum;}
void dfs(int x,int fa){
	f[x][0]=fa;dfn[x]=++idx;d[x]=d[fa]+1;sz[x]=1;
	rep(i,1,t)f[x][i]=f[f[x][i-1]][i-1];
	for(int i=h[x];i;i=e[i].nxt)if(e[i].to!=fa)dfs(e[i].to,x),sz[x]+=sz[e[i].to];
}
inline int lca(int x,int y){
	if(d[x]<d[y])swap(x,y);
	pre(i,t,0)if(d[f[x][i]]>=d[y])x=f[x][i];
	if(x==y)return x;
	pre(i,t,0)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	return f[x][0];
}
int get(int x,int y){
	pre(i,t,0)if(d[f[x][i]]>=y)x=f[x][i];
	return x;
}
struct node{
	int l,x,y;
	bool operator<(const node o)const{return l<o.l;}
}a[N];
bool cmp(node x,node y){return d[x.l]<d[y.l];}
map<pair<int,int>,int>w;
void calc(int l,int r){
	rep(i,l,r){
		ans+=i-l;
		if(~a[i].x)ans-=c[a[i].x];
		if(~a[i].y)ans-=c[a[i].y];
		if(~a[i].x&&~a[i].y&&w.count(make_pair(a[i].x,a[i].y)))ans+=w[make_pair(a[i].x,a[i].y)];
		if(~a[i].x)c[a[i].x]++;
		if(~a[i].y)c[a[i].y]++;
		if(~a[i].x&&~a[i].y)w[make_pair(a[i].x,a[i].y)]++;
	}
	rep(i,l,r){
		if(~a[i].x)c[a[i].x]--;
		if(~a[i].y)c[a[i].y]--;
	}
	w.clear();
}
void calc1(){
	rep(i,1,m){
		int x,y;scanf("%d%d",&x,&y);
		a[i].l=lca(x,y);u[i]=x;v[i]=y;
		a[i].x=(x==a[i].l?-1:get(x,d[a[i].l]+1));
		a[i].y=(y==a[i].l?-1:get(y,d[a[i].l]+1));
		if(a[i].x>a[i].y)swap(a[i].x,a[i].y);
	}
	sort(a+1,a+m+1);int pre=1;
	//rep(i,1,m)printf("%d %d %d\n",a[i].l,a[i].x,a[i].y);
	rep(i,2,m)if(a[i].l!=a[i-1].l){calc(pre,i-1);pre=i;}
	calc(pre,m);
}
inline void solve(int l,int r){rep(i,l,r)add(dfn[a[i].x],1),add(dfn[a[i].y],1);}
void calc2(){
	rep(i,1,m)a[i].l=lca(u[i],v[i]),a[i].x=u[i],a[i].y=v[i];
	sort(a+1,a+m+1,cmp);int pre=1;
	rep(i,2,m){
		if(d[a[i].l]!=d[a[i-1].l])solve(pre,i-1),pre=i;
		ans+=ask(dfn[a[i].l]+sz[a[i].l]-1)-ask(dfn[a[i].l]-1);
		int cur;
		if(a[i].x!=a[i].l){
			cur=get(a[i].x,d[a[i].l]+1);
			ans-=ask(dfn[cur]+sz[cur]-1)-ask(dfn[cur]-1);
		}
		if(a[i].y!=a[i].l){
			cur=get(a[i].y,d[a[i].l]+1);
			ans-=ask(dfn[cur]+sz[cur]-1)-ask(dfn[cur]-1);
		}
	}
}
int main(){
	scanf("%d",&n);t=log2(n);
	rep(i,1,n-1){int x,y;scanf("%d%d",&x,&y);adde(x,y);adde(y,x);}
	dfs(1,0);scanf("%d",&m);calc1();calc2();
	return printf("%lld\n",ans),0;
}