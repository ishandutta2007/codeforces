// Problem: CF741D Arpas letter-marked tree and Mehrdads Dokhtar-kosh paths
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF741D
// Memory Limit: 250 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
const int N=5e5+10;
const int inf=0x3f3f3f3f;
int n;vector<pair<int,char>>e[N];
int dis[N];
int dep[N];
int ans[N];
int sz[N];
int son[N];
int buc[1<<22];
void dfs1(int u){
	sz[u]=1;pair<int,int>Son={-1,0};
	for(auto [v,w]:e[u]){
		dep[v]=dep[u]+1;
		dis[v]=dis[u]^(1<<w-'a');
		dfs1(v);
		sz[u]+=sz[v];
		Son=max(Son,{sz[v],v});
	}
	son[u]=Son.second;
}
int o;
void init(int u){
	buc[dis[u]]=-inf;
	for(auto [v,w]:e[u])init(v);
}
void up(int u){
	ans[o]=max(ans[o],buc[dis[u]]+dep[u]-2*dep[o]);
	for(int i=0;i<22;i++)ans[o]=max(ans[o],buc[dis[u]^(1<<i)]+dep[u]-2*dep[o]);
	for(auto [v,w]:e[u])up(v);
}
void ins(int u){
	buc[dis[u]]=max(buc[dis[u]],dep[u]);
	for(auto [v,w]:e[u])ins(v);
}
void work(int u){
	for(auto [v,w]:e[u])if(v!=son[u])
		work(v),init(v);
	if(son[u])work(son[u]);
	o=u;
	for(auto [v,w]:e[u])if(v!=son[u])
		up(v),ins(v);
	buc[dis[u]]=max(buc[dis[u]],dep[u]);
	ans[u]=max(ans[u],buc[dis[u]]-dep[u]);
	for(int i=0;i<22;i++)ans[u]=max(ans[u],buc[dis[u]^(1<<i)]-dep[u]);
	for(auto [v,w]:e[u])
		ans[u]=max(ans[v],ans[u]);
}
signed main(){
	memset(buc,-0x3f,sizeof buc);
	read(n);
	for(int i=2;i<=n;i++){
		int f;read(f);char c=getchar();
		while(!isalpha(c))c=getchar();
		e[f].push_back({i,c});
	}
	dfs1(1);
	work(1);
	for(int i=1;i<=n;i++)
		write(ans[i]),putchar(' ');
}