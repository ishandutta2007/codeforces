//starusc
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=1e5+4;
struct edge{
	int v,w,nxt;
}e[N<<1];
int first[N],cnt;
inline void add(int u,int v,int w){
	e[++cnt]=(edge){v,w,first[u]};first[u]=cnt;
}
int n,p1,p2,d[N][3],c[N],fa[N];
queue<int>q;
inline int findfar(int st,int r){
	d[st][r]=0;
	q.push(st);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=first[x],v;i;i=e[i].nxt){
			v=e[i].v;
			if(d[v][r]!=-1)continue;
			d[v][r]=d[x][r]+e[i].w;
			q.push(v);
		}
	}
	int ret=1;
	for(int i=2;i<=n;i++)
		if(d[i][r]>d[ret][r])ret=i;
	return ret;
}
inline bool comp(int x,int y){
	return d[x][0]<d[y][0];
}
namespace dsu{
	int fa[N],siz[N];
	inline void clear(){
		for(int i=1;i<=n;i++){fa[i]=i;siz[i]=1;}
	}
	int find(int x){
		return x==fa[x]?x:fa[x]=find(fa[x]);
	}
	inline void merge(int u,int v){
		u=find(u);v=find(v);
		if(u!=v){
			fa[v]=u;
			siz[u]+=siz[v];
		}
	}
}
signed main(){
	n=read();
	for(int i=1,u,v,w;i<n;i++){
		u=read();v=read();w=read();
		add(u,v,w);add(v,u,w);
	}
	memset(d,-1,sizeof(d));
	memset(fa,-1,sizeof(fa));
	p1=findfar(1,0);p2=findfar(p1,1);findfar(p2,2);
	for(int i=1;i<=n;i++){
		d[i][0]=max(d[i][1],d[i][2]);
		c[i]=i;
	}
	sort(c+1,c+n+1,comp);
	fa[c[1]]=0;
	for(int i=2;i<=n;i++)
		for(int j=first[c[i]],v;j;j=e[j].nxt){
			v=e[j].v;
			if(fa[v]!=-1){fa[c[i]]=v;break;}
		}
	for(int Q=read(),l,ans;Q--;){
		l=read();
		dsu::clear();
		ans=0;
		for(int i=n,p=n;i;i--){
			while(d[c[p]][0]-d[c[i]][0]>l)dsu::siz[dsu::find(c[p--])]--;
			ans=max(ans,dsu::siz[dsu::find(c[i])]);
			dsu::merge(c[i],fa[c[i]]);
		}
		cout<<ans<<"\n";
	}
	return (0-0);
}