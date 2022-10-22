//T2 
#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){
	x=0;char c=getchar();bool f=false;
	for(;!isdigit(c);c=getchar())f!=c=='-';
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	if(f)x=-x;
}
template<typename T ,typename ...Arg>
inline void read(T &x,Arg &...args){
	read(x);read(args...);
}
template<typename T>
inline void write(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
const int N=1e5+10;
int n,O,tim[N];//
int sz[N];// 
double f[N];// 
vector<pair<int,int>>e[N];
#define pb push_back
void dfs(int u,int fa){
	tim[u]=f[u]=0;sz[u]=1;
	for(auto Edge:e[u]){
		int v=Edge.first,w=Edge.second;
		if(v==fa)continue;
		dfs(v,u);
		tim[u]+=2*w+tim[v];
		sz[u]+=sz[v];
	}
	/*
	x,y
	 xy
	f[x]*P(in x)+(tim[x]+2*wx)*f[y]*P(in y)
	
	f[y]*P(in y)+(tim[y]+2*wy)*f[x]*P(in x)
	
	f[x]*P(in x)+((tim[x]+2*wx)+f[y])*P(in y)>f[y]*P(in y)+((tim[y]+2*wy)+f[x])*P(in x)
	 P(in x) a P(in y)  b  tim[x]+2*wx=g[x]
	f[x]*a + g[x]*b + f[y]*b > f[y] *b + g[y]*a + f[x]*a
	g[x]*b>g[y]*a
	g[y]/b<g[x]/a
	g[y]/P(in y)<g[x]/P(in x)
	g[y]/sz[y]*sz[u]<g[x]/sz[x]*sz[u]
	g[y]/sz[y]<g[x]/sz[x]
	 
	*/  
	vector<pair<double,pair<int,int>>>son;
	//first
	//second.first
	//second.second 
	for(auto Edge:e[u]){
		int v=Edge.first,w=Edge.second;
		if(v==fa)continue;
		son.pb({1.0*(2*w+tim[v])/sz[v],{v,w}});
	}
	int wait=0,tot;
	if(u==1)tot=sz[u]-1;
	else tot=sz[u];
	sort(son.begin(),son.end());
	for(auto Son:son){
		int v=Son.second.first;
		int w=Son.second.second;
		f[u]+=(wait+w+f[v])*1.0*sz[v]/tot;
		wait+=tim[v]+2*w;
	}
}
signed main(){
	//freopen("treasure.in","r",stdin);
	//freopen("treasure.out","w",stdout);
	read(n);
	for(int i=1,u,v,w;i<n;i++)
		read(u,v,w),
		e[u].pb({v,w}),e[v].pb({u,w});
	dfs(1,0);
	printf("%.8lf",f[1]);
}